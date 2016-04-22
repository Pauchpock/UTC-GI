// Includes, project.
#include "cluster.hpp"
#define K 10
#define R 10
#define D 5



/*
 * points : Points d'entrée
 * clusters : tableau de cluster en sortie de l'algorithme
 */
void
sy31::computeClusters(std::vector<sy31::Cluster>& clusters, std::vector<sy31::vec2d> const& points)
{
   // Exemple d'utilisation des clusters
   clusters.clear();		// Effacer tout les clusters
   clusters.resize(1);		// Créer un cluster
   clusters[0].clear();	// Effacer le cluster 0 (Initialiser)
   
	
	int *G=new int[points.size()]; // tableau G, groupes
	double d[K]={0}; // tableau D, distance
	int g=0;
	
 for(int i=0; i<(int)points.size(); ++i)
 {
	 clusters[0].push_back(points[i]);
	 G[i]=0;
	 
}
 	for(int i=K;i<=(int)points.size();i++)
	{
		double dmin=100;
	    int jmin;
		if(sqrt(pow(points[i].x,2)+pow(points[i].y,2))>R)
		{
			for(int j=1;j<=K;j++)
			{
				d[j]=sqrt(pow(points[i].x-points[i-j].x,2)+pow(points[i].y-points[i-j].y,2));
				if(d[j]<dmin)
			{
				dmin=d[j];
				jmin=j;
			}
			}
		}

		

		if(dmin<D)
		{
			if(G[i-jmin]==0)
			{
				g++;
				G[i-jmin]=g;
				clusters.resize(g);
				clusters[G[i-jmin]-1].push_back(points[i-jmin]);
			}
			G[i]=G[i-jmin];
			clusters[G[i]-1].push_back(points[i]);
		}
	}

}
