// Includes, project.
#include "cluster-component.hpp"

// Includes, standard.
#include <cmath>

#define NB_MAX_CLUSTERS 2048
#define NB_MAX_POINTS 2048

using namespace sy31;

////////////////////////////////////////////////////////////////
// RTMaps - Input
////////////////////////////////////////////////////////////////
MAPS_BEGIN_INPUTS_DEFINITION(ClusterComponent)
  MAPS_INPUT("Angles", MAPS::FilterFloat64, MAPS::FifoReader)
  MAPS_INPUT("Distances", MAPS::FilterInteger32, MAPS::FifoReader)
MAPS_END_INPUTS_DEFINITION

////////////////////////////////////////////////////////////////
// RTMaps - Output
////////////////////////////////////////////////////////////////
MAPS_BEGIN_OUTPUTS_DEFINITION(ClusterComponent)
  MAPS_OUTPUT("ClustersSize", MAPS::Integer32, NULL, NULL, NB_MAX_CLUSTERS)
  MAPS_OUTPUT("ClustersData", MAPS::Float64, NULL, NULL, 2 * NB_MAX_POINTS)
MAPS_END_OUTPUTS_DEFINITION

////////////////////////////////////////////////////////////////
// RTMaps - Properties
////////////////////////////////////////////////////////////////
MAPS_BEGIN_PROPERTIES_DEFINITION(ClusterComponent)
MAPS_END_PROPERTIES_DEFINITION

////////////////////////////////////////////////////////////////
// RTMaps - Actions
////////////////////////////////////////////////////////////////
MAPS_BEGIN_ACTIONS_DEFINITION(ClusterComponent)
MAPS_END_ACTIONS_DEFINITION

////////////////////////////////////////////////////////////////
// RTMaps - Definition
////////////////////////////////////////////////////////////////
MAPS_COMPONENT_DEFINITION(
	ClusterComponent, "ClusterComponent", "1.0", 128,
	MAPS::Threaded|MAPS::Sequential,MAPS::Threaded,
  2, // Nb of inputs
	2, // Nb of outputs
	0, // Nb of properties
	0) // Nb of actions

void
ClusterComponent::Birth()
{
  // Hi! :)
}

void
ClusterComponent::Core() 
{
  this->readScanFromInput(mPoints);
  computeClusters(mClusters, mPoints);
  this->sendClusters(mClusters);
}

void
ClusterComponent::Death()
{
  // Couic! :(
}

void
ClusterComponent::readScanFromInput(std::vector<vec2d>& points)
{
  MAPSIOElt* angles    = StartReading(Input("Angles"));
  MAPSIOElt* distances = StartReading(Input("Distances"));
  if (angles->VectorSize() != distances->VectorSize())
    Error("angles/distances size mismatch");

  // Allocate enough memory to store the points.
  points.resize(angles->VectorSize());

  // Convert from scan space to 2D space.
  for (int i = 0; i < angles->VectorSize(); ++i)
  {
    points[i].x = distances->Integer32(i) * std::cos( angles->Float64(i) * 3.1415659 / 180.0 );
    points[i].y = distances->Integer32(i) * std::sin( angles->Float64(i) * 3.1415659 / 180.0 );
  }
}

void
ClusterComponent::sendClusters(std::vector<Cluster> const& clusters)
{
  MAPSIOElt* clustersSize = StartWriting(Output("ClustersSize"));
  MAPSIOElt* clustersData = StartWriting(Output("ClustersData"));

  // Computer the number of points.
  size_t nbPoints = 0;
  for (unsigned int i = 0; i < clusters.size(); ++i)
    nbPoints += clusters[i].size();

  // Allocate the output buffers memory.
  clustersSize->VectorSize() = clusters.size();
  clustersData->VectorSize() = nbPoints;

  // Serialize the clusters.
  unsigned int offset = 0;
  for (unsigned int i = 0; i < clusters.size(); ++i)
  {
    // Write the cluster size.
    clustersSize->Integer32(i) = clusters[i].size();

    // Write the cluster points.
    for (unsigned int j = 0; j < clusters[i].size(); ++j)
    {
      clustersData->Float64(offset++) = clusters[i][j].x;
      clustersData->Float64(offset++) = clusters[i][j].y;
    }
  }

  StopWriting(clustersSize);
  StopWriting(clustersData);
}

