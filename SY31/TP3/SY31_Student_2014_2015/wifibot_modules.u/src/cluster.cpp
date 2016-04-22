// Includes, project.
#include "cluster.hpp"

// Includes, standard.
#include <iostream>

void
sy31::computeClusters(std::vector<sy31::Cluster>& clusters, std::vector<sy31::vec2d> const& points)
{
  // Packages.
  using namespace std;

  // Sortie de l'algorithme: clusters de points.
  clusters.resize(0);

  // Critere: distance max. pour etre dans le meme cluster.
  double th = 200;
  // Identifiant de groupe.
  unsigned int g  = 0;
  // Histories des cinqs derniers points.
  vector<double> di(5);
  // Identifiant du groupe de chaque point.
  vector<unsigned int> group(points.size());

  // Parcourir l'ensemble des points.
  for (unsigned int k = di.size(); k < points.size(); ++k)
  {
    // Calculer un historique de distance par rapport aux N points precednt.
    for (unsigned int j = 0; j < di.size(); ++j)
    {
      double x2 = (points[k].x - points[k - j - 1].x) * (points[k].x - points[k - j - 1].x);
      double y2 = (points[k].y - points[k - j - 1].y) * (points[k].y - points[k - j - 1].y);
      di[j] = std::sqrt(x2 + y2);
    }

    // Calculer dans l'historique la distance minimale.
    unsigned int min_idx = 0;
    double       min_dst = di[min_idx];
    for (unsigned int i = 1; i < di.size(); ++i)
    {
      if (di[i] < min_dst)
      {
        min_dst = di[i];
        min_idx = i;
      }
    }

    if (min_dst < th)
    {
      // Calculer l'index du voisin le plus proche.
      int closest = k - min_idx - 1;

      if (group[closest] == 0)
      {
        g = g + 1;
        group[closest] = g;
      }
      group[k] = group[closest];
    }
  }

  // Generer les clusters, complexite pas terrible, a ameliorer.
  clusters.resize(g+1);
  for (unsigned int i = 0; i < group.size(); ++i)
    clusters[group[i]].push_back(points[i]);
}
