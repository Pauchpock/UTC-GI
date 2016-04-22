// Includes, project
#include "red-component.hpp"

// Includes, standar
#include <cmath>

using namespace sy31;

////////////////////////////////////////////////////////////////
// RTMaps - Input
////////////////////////////////////////////////////////////////
MAPS_BEGIN_INPUTS_DEFINITION(RedComponent)
  MAPS_INPUT("Source", MAPS::FilterIplImage, MAPS::FifoReader)
MAPS_END_INPUTS_DEFINITION

////////////////////////////////////////////////////////////////
// RTMaps - Output
////////////////////////////////////////////////////////////////
MAPS_BEGIN_OUTPUTS_DEFINITION(RedComponent)
  MAPS_OUTPUT("Grey", MAPS::IplImage, NULL, NULL, 1)
  MAPS_OUTPUT("Mirror", MAPS::IplImage, NULL, NULL, 1)
  MAPS_OUTPUT("Scaled", MAPS::IplImage, NULL, NULL, 1)
  MAPS_OUTPUT("Both", MAPS::IplImage, NULL, NULL, 1)
MAPS_END_OUTPUTS_DEFINITION

////////////////////////////////////////////////////////////////
// RTMaps - Properties
////////////////////////////////////////////////////////////////
MAPS_BEGIN_PROPERTIES_DEFINITION(RedComponent)
MAPS_END_PROPERTIES_DEFINITION

////////////////////////////////////////////////////////////////
// RTMaps - Actions
////////////////////////////////////////////////////////////////
MAPS_BEGIN_ACTIONS_DEFINITION(RedComponent)
MAPS_END_ACTIONS_DEFINITION

////////////////////////////////////////////////////////////////
// RTMaps - Definition
////////////////////////////////////////////////////////////////
MAPS_COMPONENT_DEFINITION(
	RedComponent, "RedComponent", "1.0", 128,
	MAPS::Threaded|MAPS::Sequential,MAPS::Threaded,
  1, // Nb of inputs
	4, // Nb of outputs
	0, // Nb of properties
	0) // Nb of actions

void
RedComponent::Birth()
{
  mIsAllocated = false;
}

void
RedComponent::Core() 
{
  MAPSIOElt* input = StartReading(Input("Source"));
  IplImage& source = input->IplImage();
  if (!mIsAllocated)
    allocateOutputs(source);

  MAPSIOElt* outGrey    = StartWriting(Output("Grey"));
  MAPSIOElt* outScaled  = StartWriting(Output("Scaled"));
  MAPSIOElt* outMirror  = StartWriting(Output("Mirror"));
  MAPSIOElt* outBoth  = StartWriting(Output("Both"));

  IplImage& grey   = outGrey->IplImage();
  IplImage& scaled = outScaled->IplImage();
  IplImage& mirror = outMirror->IplImage();
  IplImage& both = outBoth->IplImage();

  /* Convertir l'image en niveau de gris */
 fonction(source,grey,false,false);
 fonction(source,scaled,true,false);
 fonction(source,mirror,false,true);
 fonction(source,both,true,true);

  /* Set the timestamps */
  outGrey->Timestamp()  = MAPS::CurrentTime();
  outScaled->Timestamp()  = MAPS::CurrentTime();
  outMirror->Timestamp()  = MAPS::CurrentTime();
  outBoth->Timestamp()  = MAPS::CurrentTime();

  StopReading(Input("Source"));
  StopWriting(outGrey);
  StopWriting(outScaled);
  StopWriting(outMirror);
  StopWriting(outBoth);
}

void
RedComponent::Death()
{
  // Couic! :(
}

void
RedComponent::allocateOutputs(IplImage const& src)
{
  IplImage model = MAPS::IplImageModel(src.width, src.height, MAPS_CHANNELSEQ_GRAY);

  Output("Grey").AllocOutputBufferIplImage(model);
  Output("Scaled").AllocOutputBufferIplImage(model);
  Output("Mirror").AllocOutputBufferIplImage(model);
  Output("Both").AllocOutputBufferIplImage(model);

  mIsAllocated = true;
}


void
RedComponent::fonction(IplImage const& src,IplImage & dst, bool scaled, bool mirror)
{
	// Pour simplement avoir l'image, return src;
	for(int i=0; i<src.width*src.height;i++) {

		int val = (src.imageData[3*i]*0.299) + (src.imageData[(3*i)+1]*0.587) + (src.imageData[(3*i)+2]*0.114);
		
		if (scaled) {
			if (val >=0 && val < 50)
				val = 25;
			else if (val >= 50 && val < 100)
				val = 75;
			else if (val >= 100 && val < 150)
				val = 125;
			else if (val >= 150 && val < 200)
				val = 175;
			else
				val = 225;
		}

		if (mirror)
			dst.imageData[((i/src.width)+1)*src.width-(i%src.width)] = val;
		else
			dst.imageData[i] = val;
	}
}
