#include <bits/stdc++.h>
using namespace std;
#define MAX 1e8

#define SUBLIME
#if defined SUBLIME
	#define ISTREAM ifile
#else
	#define ISTREAM std::cin
#endif

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;

int main(){
	 #if defined (SUBLIME)
      std::ifstream ifile("in_prim.input");
    #endif

	int V,E;
	cout<<"no of nodes";ISTREAM>>V;		
	vvii G(V);
	vector<bool>visited(V,0);
	vi distance(V,MAX);
	vi parent(V,-1);
	vii mstEdge;
	cout<<"no of edges";ISTREAM>>E;
	for(int i=0;i<E;i++){
		int u,v,wt;
		ISTREAM>>u>>v>>wt;
		G[u].push_back(ii(v,wt));
		G[v].push_back(ii(u,wt));
	}
	int src;
	cout<<"Enter source vertex";ISTREAM>>src;
	set<ii>Q; //RBT
	for(int i=0;i<V;i++)
		Q.insert(ii(distance[i],i));
	Q.erase(Q.find(ii(distance[src],src)));
	distance[src] = 0;
	Q.insert(ii(distance[src],src));

	while(!Q.empty()){
		ii top = *Q.begin();
		Q.erase(Q.begin());
		int d = top.first;
		int v1 = top.second;
		visited[v1] = 1;
		if(v1!=src)
			mstEdge.push_back(ii(parent[v1],v1));
		for(int i=0;i<G[v1].size();i++){
			if(!visited[(G[v1][i].first)]){ //if not included in MST,may be only there distance is updated
				int v2 = G[v1][i].first;
				int cost = G[v1][i].second; //weight of v1v2
				if(distance[v2]>cost){
					Q.erase(Q.find(ii(distance[v2],v2)));
					distance[v2] = cost;
					Q.insert(ii(distance[v2],v2));
					parent[v2] = v1;
				}
			}
		}
	}

	cout<<"MST edges are\n";
	for(int i=0;i<mstEdge.size();i++)
		cout<<mstEdge[i].first<<","<<mstEdge[i].second<<endl;
	return 0;
}