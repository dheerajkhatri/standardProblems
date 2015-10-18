/*If your graph is directed then you have to not just remember if you have visited a node or not,
but also how you got there. Otherwise you might think you have found a cycle 
but in reality all you have is two separate paths A->B but that doesn't mean there is a path B->A. 
With a depth first search you can mark nodes as visited as you descend and unmark them as you backtrack.*/

#include <bits/stdc++.h>
using namespace std;

class Graph{
	private:
		int v;
		list<int>*adj;
		bool cycleUtil(int node, bool* visited, int parent);

	public:
		Graph(int v);
		void addEdge(int u, int v);	
		bool cycleContain();
};


Graph::Graph(int v){
	this->v = v;
	this->adj = new list<int>[v];
}

void Graph::addEdge(int u, int v){
	adj[u].push_back(v);
	adj[v].push_back(u);
}

bool Graph::cycleUtil(int node, bool* visited, int parent){			
	
	visited[node] =true;			

	for(list<int>::iterator it=adj[node].begin();it!=adj[node].end();it++){
		if(!visited[*it]){
			if(cycleUtil(*it,visited,node))return true;
		}else if(*it==parent)return true;
	}
	return false;
}


bool Graph::cycleContain(){
	bool* visited = new bool[v];	

	int i;
	for(i=0;i<v;i++) visited[i]=false;		

	for(i=0;i<v;i++){		
		if(!visited[i])
			if(cycleUtil(i,visited,-1))return true;
	}	
	return false;
}

int main(){
	
	Graph g(5);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 1);
    //g.addEdge(4, 0);
    //g.addEdge(0, 3); 	
 	    
    g.cycleContain()==true ? cout<<"YES cycle is there "<<endl:cout<<"No cycle found"<<endl;

	return 0;
}