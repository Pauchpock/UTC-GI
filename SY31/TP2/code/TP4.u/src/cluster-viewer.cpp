// Includes, project.
#include "cluster-viewer.hpp"

// Includes, standard.
#include <cmath>

double deg2rad(double a) { return a * (180.0 / 3.1415659); }
double rad2deg(double a) { return a * (3.1415659 / 180.0); }

#define WIN_W 640
#define WIN_H 480

using namespace sy31;

#define NB_CLUSTER_COLOR 10
vec3d ClusterColors[NB_CLUSTER_COLOR] = {
  vec3d(1.0, 0.0, 0.0),
  vec3d(0.0, 1.0, 0.0),
  vec3d(0.0, 0.0, 1.0),
  vec3d(1.0, 0.0, 1.0),
  vec3d(0.0, 1.0, 1.0),
  vec3d(0.2, 0.8, 0.1),
  vec3d(0.8, 0.2, 0.1),
  vec3d(0.5, 0.2, 0.7),
  vec3d(0.8, 0.8, 0.4),
  vec3d(0.9, 0.1, 0.1)
};

////////////////////////////////////////////////////////////////
// RTMaps - Input
////////////////////////////////////////////////////////////////
MAPS_BEGIN_INPUTS_DEFINITION(ClusterViewer)
  MAPS_INPUT("ClustersSize", MAPS::FilterInteger32, MAPS::FifoReader)
  MAPS_INPUT("ClustersData", MAPS::FilterFloat64, MAPS::FifoReader)
MAPS_END_INPUTS_DEFINITION

////////////////////////////////////////////////////////////////
// RTMaps - Output
////////////////////////////////////////////////////////////////
MAPS_BEGIN_OUTPUTS_DEFINITION(ClusterViewer)
MAPS_END_OUTPUTS_DEFINITION

////////////////////////////////////////////////////////////////
// RTMaps - Properties
////////////////////////////////////////////////////////////////
MAPS_BEGIN_PROPERTIES_DEFINITION(ClusterViewer)
MAPS_END_PROPERTIES_DEFINITION

////////////////////////////////////////////////////////////////
// RTMaps - Actions
////////////////////////////////////////////////////////////////
MAPS_BEGIN_ACTIONS_DEFINITION(ClusterViewer)
MAPS_END_ACTIONS_DEFINITION

////////////////////////////////////////////////////////////////
// RTMaps - Definition
////////////////////////////////////////////////////////////////
MAPS_COMPONENT_DEFINITION(
	ClusterViewer, "ClusterViewer", "1.0", 128,
	MAPS::Threaded|MAPS::Sequential,MAPS::Threaded,
  2, // Nb of inputs
	0, // Nb of outputs
	0, // Nb of properties
	0) // Nb of actions

void
ClusterViewer::Birth()
{
  mViewer.open(WIN_W, WIN_H);
  mViewer.setScale(0.1f);
}

void
ClusterViewer::Core() 
{
  readClustersFromInput(mClusters);
  
  mViewer.clear();
  for (size_t i = 0; i < mClusters.size(); ++i)
    mViewer.render(mClusters[i], ClusterColors[i % NB_CLUSTER_COLOR]);
  mViewer.refresh();
  mViewer.processEvents();
}

void
ClusterViewer::Death()
{
  mViewer.close();
}

void 
ClusterViewer::readClustersFromInput(std::vector<Cluster>& clusters)
{
  MAPSIOElt* clustersSize = StartReading(Input("ClustersSize"));
  MAPSIOElt* clustersData = StartReading(Input("ClustersData"));

  // Allocate enough clusters.
  clusters.resize(clustersSize->VectorSize());
  
  // Read all the clusters from the input.
  unsigned int offset = 0;
  for (unsigned int i = 0; i < clusters.size(); ++i)
  {
    // Resize the number of points in the cluster.
    clusters[i].resize(clustersSize->Integer32(i));
    
    // Read the points of the cluster.
    for (unsigned int j = 0; j < clusters[i].size(); ++j)
    {
      clusters[i][j].x = clustersData->Float64(offset++);
      clusters[i][j].y = clustersData->Float64(offset++);
    }
  }

  StopReading(Input("ClustersSize"));
  StopReading(Input("ClustersData"));
}
