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
      std::ifstream ifile("in_dijkstra.input");
    #endif
	int V,E;
	cout<<"no of nodes";ISTREAM>>V;	
	vvii G(V);	
	vi distance(V,MAX);
	vi parent(V,-1);
	cout<<"no of edges";ISTREAM>>E;
	for(int i=0;i<E;i++){
		int u,v,wt;
		ISTREAM>>u>>v>>wt;
		G[u].push_back(ii(v,wt));
		G[v].push_back(ii(u,wt));
	}
	int src,dest;
	cout<<"Enter source vertex";ISTREAM>>src;
	cout<<"Enter destination vertex";ISTREAM>>dest;
	set<ii>Q; //RBT

	distance[src] = 0;
	parent[src] = -1;
	Q.insert(ii(distance[src],src));

	while(!Q.empty()){
		ii top = *Q.begin();
		Q.erase(Q.begin());
		int d = top.first;
		int v1 = top.second;		
		
		for(int i=0;i<G[v1].size();i++){			
			int v2 = G[v1][i].first;
			int cost = G[v1][i].second; //weight of v1v2
			if(distance[v1]+cost < distance[v2]){
				if(distance[v2]!=MAX)
					Q.erase(Q.find(ii(distance[v2],v2)));
				distance[v2] = distance[v1]+cost;												
				parent[v2] = v1;
				Q.insert(ii(distance[v2],v2));
			}
		}
	}

	cout<<"min distance between "<<src<<" and "<<dest<<distance[dest]<<endl;
	cout<<"path in reverse direction";
	int cur = dest;
	while(cur!=-1){
		cout<<cur<<" ";
		cur = parent[cur];
	}
	return 0;
}