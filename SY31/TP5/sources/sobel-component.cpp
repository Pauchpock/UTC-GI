// Includes, project
#include "sobel-component.hpp"

// Includes, standar
#include <cmath>

using namespace sy31;

////////////////////////////////////////////////////////////////
// RTMaps - Input
////////////////////////////////////////////////////////////////
MAPS_BEGIN_INPUTS_DEFINITION(SobelComponent)
  MAPS_INPUT("Source", MAPS::FilterIplImage, MAPS::FifoReader)
MAPS_END_INPUTS_DEFINITION

////////////////////////////////////////////////////////////////
// RTMaps - Output
////////////////////////////////////////////////////////////////
MAPS_BEGIN_OUTPUTS_DEFINITION(SobelComponent)
  MAPS_OUTPUT("Gray", MAPS::IplImage, NULL, NULL, 1)
  MAPS_OUTPUT("Sobel", MAPS::IplImage, NULL, NULL, 1)
  MAPS_OUTPUT("Per", MAPS::IplImage, NULL, NULL, 1)
MAPS_END_OUTPUTS_DEFINITION

////////////////////////////////////////////////////////////////
// RTMaps - Properties
////////////////////////////////////////////////////////////////
MAPS_BEGIN_PROPERTIES_DEFINITION(SobelComponent)
MAPS_END_PROPERTIES_DEFINITION

////////////////////////////////////////////////////////////////
// RTMaps - Actions
////////////////////////////////////////////////////////////////
MAPS_BEGIN_ACTIONS_DEFINITION(SobelComponent)
MAPS_END_ACTIONS_DEFINITION

////////////////////////////////////////////////////////////////
// RTMaps - Definition
////////////////////////////////////////////////////////////////
MAPS_COMPONENT_DEFINITION(
	SobelComponent, "SobelComponent", "1.0", 128,
	MAPS::Threaded|MAPS::Sequential,MAPS::Threaded,
  1, // Nb of inputs
	3, // Nb of outputs
	0, // Nb of properties
	0) // Nb of actions

void
SobelComponent::Birth()
{
  mIsAllocated = false;
}

void
SobelComponent::Core() 
{
  MAPSIOElt* input = StartReading(Input("Source"));
  IplImage& source = input->IplImage();
  if (!mIsAllocated)
    allocateOutputs(source);

  MAPSIOElt* outSobel = StartWriting(Output("Sobel"));
   MAPSIOElt* outPer = StartWriting(Output("Per"));
  MAPSIOElt* outGray  = StartWriting(Output("Gray"));

  IplImage& sobel = outSobel->IplImage();
  IplImage& gray  = outGray->IplImage();
  IplImage& per = outPer->IplImage();

  /* Convertir l'image en niveau de gris */
  rgb2gray(source, gray);

  /* Calculer le filtre de Sobel */
  compute_sobel(gray, sobel);
  compute_per(gray, per);

  /* Set the timestamps */
  outPer->Timestamp() = MAPS::CurrentTime();
  outSobel->Timestamp() = MAPS::CurrentTime();
  outGray->Timestamp()  = MAPS::CurrentTime();

  StopReading(Input("Source"));
  StopWriting(outSobel);
  StopWriting(outGray);
  StopWriting(outPer);
}

void
SobelComponent::Death()
{
  // Couic! :(
}

void
SobelComponent::allocateOutputs(IplImage const& src)
{
  IplImage model = MAPS::IplImageModel(src.width, src.height, MAPS_CHANNELSEQ_GRAY);

  Output("Sobel").AllocOutputBufferIplImage(model);
  Output("Per").AllocOutputBufferIplImage(model);
  Output("Gray").AllocOutputBufferIplImage(model);

  mIsAllocated = true;
}

void
SobelComponent::rgb2gray(IplImage const& src, IplImage& dst)
{
	int i;
	for(i=0;i<src.width*src.height;i++)
	{
		dst.imageData[i]=src.imageData[3*i] *0.299+src.imageData[3*i+1]*0.587+src.imageData[3*i+2]*0.114;
	}
	
}

int
SobelComponent::convolution(IplImage const& src, int x, int y, int const* mask)
{ 
	int R=0; 

	 for(int i=-1;i<=1;i++)
		{
			for(int j=-1;j<=1;j++)
				R+=mask[3*(i+1)+(j+1)]*src.imageData[(src.width*(i+x))+(j+y)];
	    }

return R;	

}

void
SobelComponent::compute_sobel(IplImage const& src, IplImage& dst)
{  
	//Masque de SOBEL
	int Gx[9] ={-1,0,1,-2,0,2,-1,0,1};
	int Gy[9] ={1,2,1,0,0,0,-1,-2,-1};
	int x,y;

	for(int i=1;i<src.height-1;i++)
	{
		for(int j=1;j<src.width-1;j++)
		{
		x=convolution(src,i,j,Gx);
		y=convolution(src,i,j,Gy);
		int g=sqrt((double)(x*x)+(y*y));
		g=max(min(g,255),0);
		dst.imageData[i*dst.width+j]=g;
		}
	}


}

void
SobelComponent::compute_per(IplImage const& src, IplImage& dst)
{ 
		//Masque de Prewitt
	int Gx[9] ={-1,0,1,-1,0,1,-1,0,1};
	int Gy[9] ={1,1,1,0,0,0,-1,-1,-1};
	int x,y;
	for(int i=1;i<src.height-1;i++)
	{
		for(int j=1;j<src.width-1;j++)
		{
		x=convolution(src,i,j,Gx);
		y=convolution(src,i,j,Gy);
		int g=sqrt((double)(x*x)+(y*y));
		g=max(min(g,255),0);
		dst.imageData[i*dst.width+j]=g;
		}
	}
}