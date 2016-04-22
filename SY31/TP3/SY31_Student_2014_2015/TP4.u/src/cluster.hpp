#ifndef DEF_CLUSTER_HPP
#define DEF_CLUSTER_HPP



// Includes, standard
#include <vector>

// Includes, project.
#include "vec.hpp"

namespace sy31
{
  /** Cluster
   * @brief Array of points.
   */
  typedef std::vector<vec2d> Cluster;

  /** Compute clusters from a scan range.
   * @param[out] clusters
   * @param[in] points
   */
  void computeClusters(std::vector<Cluster>& clusters, std::vector<vec2d> const& points);
}

#endif /* end of include guard: DEF_CLUSTER_HPP */
