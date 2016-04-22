#ifndef DEF_CLUSTER_COMPONENT_HPP
#define DEF_CLUSTER_COMPONENT_HPP

// Includes, rtmaps.
#include "maps.hpp"

// Includes, project.
#include "cluster.hpp"

namespace sy31
{
  class ClusterComponent
    : public MAPSComponent
  {
    MAPS_COMPONENT_STANDARD_HEADER_CODE(ClusterComponent)
    private:
      /// Read a scan from the input.
      void readScanFromInput(std::vector<vec2d>& points);
      
      /// Send clusters to the output.
      void sendClusters(std::vector<Cluster> const& clusters);
      
    private:
      std::vector<vec2d>      mPoints;
      std::vector<Cluster>    mClusters;
  };
}

#endif
