// Includes, project.
#include "WebcamModule.h"

// Includes, standard.
#include <cstdio>

// Number of data extracted from the Hokuyo.
size_t const NB_DATA_FROM_HOKUYO = 1000;

////////////////////////////////////////////////////////////////
// RTMaps - Input
////////////////////////////////////////////////////////////////
MAPS_BEGIN_INPUTS_DEFINITION(WebcamModule)
	// Nothing.
MAPS_END_INPUTS_DEFINITION

////////////////////////////////////////////////////////////////
// RTMaps - Output
////////////////////////////////////////////////////////////////
MAPS_BEGIN_OUTPUTS_DEFINITION(WebcamModule)
    MAPS_OUTPUT("output", MAPS::IplImage, NULL, NULL, 0)
MAPS_END_OUTPUTS_DEFINITION

////////////////////////////////////////////////////////////////
// RTMaps - Properties
////////////////////////////////////////////////////////////////
MAPS_BEGIN_PROPERTIES_DEFINITION(WebcamModule)
    MAPS_PROPERTY("pIndex", 0, true, false)
MAPS_END_PROPERTIES_DEFINITION

////////////////////////////////////////////////////////////////
// RTMaps - Actions
////////////////////////////////////////////////////////////////
MAPS_BEGIN_ACTIONS_DEFINITION(WebcamModule)
MAPS_END_ACTIONS_DEFINITION

////////////////////////////////////////////////////////////////
// RTMaps - Definition
////////////////////////////////////////////////////////////////
MAPS_COMPONENT_DEFINITION(
	WebcamModule, "WebcamModule", "1.0", 128,
	MAPS::Threaded|MAPS::Sequential,MAPS::Threaded,
    0, // Nb of inputs
	1, // Nb of outputs
	1, // Nb of properties
	0) // Nb of actions

////////////////////////////////////////////////////////////////
// RTMaps - Birth
////////////////////////////////////////////////////////////////
void
WebcamModule::Birth()
{
    // Index of the camera.
    int index = (int) GetIntegerProperty("pIndex");
    // Open the camera.
    m_Webcam.open(index);
    if (!m_Webcam.isOpened())
        Error("Cannot open the webcam");
    m_Webcam.set(CV_CAP_PROP_FRAME_WIDTH, 320);
    m_Webcam.set(CV_CAP_PROP_FRAME_HEIGHT, 240);

    // Grab one frame.
    while (m_Frame.empty())
        m_Webcam >> m_Frame;

    // Create the IPL Model.
	IplImage model = m_Frame;

	// Allocate output image according to the model.
	Output("output").AllocOutputBufferIplImage(model);
}

////////////////////////////////////////////////////////////////
// RTMaps - Core
////////////////////////////////////////////////////////////////
void
WebcamModule::Core() 
{
    // Grab the next frame.
    do
    {
        m_Webcam >> m_Frame;
    } while (m_Frame.empty());

    // Get the output pin.
    MAPSIOElt* ioElt = StartWriting(Output("output"));

    // Get the raw memory of the output image.
    IplImage &iplimage=ioElt->IplImage();
    unsigned char *imageData=(unsigned char *)iplimage.imageData;

    // Copy the frame.
    for (size_t i = 0; i < m_Frame.rows * m_Frame.step; ++i)
        imageData[i] = m_Frame.data[i];
    // Copy the timestamp.
    ioElt->Timestamp() = MAPS::CurrentTime();

    // Stop writing.
    StopWriting(ioElt);
}

////////////////////////////////////////////////////////////////
// RTMaps - Death
////////////////////////////////////////////////////////////////
void
WebcamModule::Death()
{
    m_Webcam.release();
}
