#ifndef DEF_POSITION_VIEWER_HPP
#define DEF_POSITION_VIEWER_HPP

// Includes, RTMaps.
#include <maps.hpp>

// Includes, standard.
#include <list>

// Includes, project.
#include "wifibot.hpp"

namespace sy31
{
  class PositionViewer
    : public MAPSComponent 
  {
    MAPS_COMPONENT_STANDARD_HEADER_CODE(PositionViewer)
    typedef MAPSList<Wifibot::Position> Trajectory;
    public:
      /// RTMaps action: Reset the wifibot's odometry.
      static void ResetOdometry(MAPSModule *module, int actionNb);
      /// Reset the trajectory.
      void reset();
    private:
      /// Draw the current trajectory.
      void drawTrajectory();
      /// Process the SDL events.
      void processEvents();
    private:
      size_t       mWidth;
      size_t       mHeight;
      Trajectory   mTrajectory;
  };
}

#endif /* DEF_POSITION_VIEWER_HPP */
