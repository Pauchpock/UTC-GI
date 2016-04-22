////////////////////////////////
// Webcam Sensor
////////////////////////////////

#ifndef DEF_WEBCAM_H
#define DEF_WEBCAM_H

// Includes, opencv.
#include <opencv2/video/tracking.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

// HACKS: prevent RTMaps from redefining IplImage.
#define __IPL_H__

// Includes, rtmaps.
#include "maps.hpp"

/** WebcamModule
 * \brief Webcam module (PAN/TILT camera).
 */
class WebcamModule
	: public MAPSComponent
{
private:
	// Use standard header definition macro.
	MAPS_COMPONENT_STANDARD_HEADER_CODE(WebcamModule)

private:
    cv::VideoCapture        m_Webcam;
    cv::Mat                 m_Frame;
};

#endif // DEF_WEBCAM_H
