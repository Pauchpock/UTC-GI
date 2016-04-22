#ifndef DEF_ODOMETRY_COMPONENT_HPP
#define DEF_ODOMETRY_COMPONENT_HPP

// Includes, RTMaps.
#include <maps.hpp>

// Includes, project.
#include "wifibot.hpp"

namespace sy31
{
  class OdometryComponent
    : public MAPSComponent
  {
    MAPS_COMPONENT_STANDARD_HEADER_CODE(OdometryComponent)
    public:
      /// RTMaps action: Reset the wifibot's odometry.
      static void ResetOdometry(MAPSModule *module, int actionNb);
      /// Reset the odometry.
      void reset();
    private:
      MAPSTimestamp     mPreviousTimestamp;
      sy31::Wifibot     mWifibot;
  };
}

#endif /* end of include guard: DEF_ODOMETRY_COMPONENT_HPP */
