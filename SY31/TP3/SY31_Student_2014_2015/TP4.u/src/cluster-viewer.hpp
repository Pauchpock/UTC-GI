#ifndef DEF_CLUSTER_VIEWER_HPP
#define DEF_CLUSTER_VIEWER_HPP

// Includes, project.
#include "cluster.hpp"
#include "hokuyo-window.hpp"

// Includes, rtmaps.
#include "maps.hpp"

// Includes, standard.
#include <vector>

namespace sy31
{
  class ClusterViewer
    : MAPSComponent
  {
    MAPS_COMPONENT_STANDARD_HEADER_CODE(ClusterViewer)
    private:
      /// Read clusters from the input.
      void readClustersFromInput(std::vector<Cluster>& clusters);

    private:
      std::vector<Cluster>    mClusters;
      HokuyoWindow            mViewer;
  };
}

#endif
