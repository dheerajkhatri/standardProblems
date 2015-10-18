#include <bits/stdc++.h>
using namespace std;

class Graph{
	private:
		int v;
		list<int>*adj;

	public:
	Graph(int v);
	void addEdge(int u, int v);
	bool bipartite(int src);

};


Graph::Graph(int v){
		this->v = v;
		this->adj = new list<int>[v];
}

void Graph::addEdge(int u, int v){
	adj[u].push_back(v);
	adj[v].push_back(u);
}

bool Graph::bipartite(int src){
	list<int>queue;
	int* visited = new int[v];
	for(int i=0;i<v;i++)visited[i]=-1;

	queue.push_back(src);
	visited[src] = 1;

	cout<<src<<" colored 1"<<endl;

	while(!queue.empty()){
		int todo = queue.front();
		queue.pop_front();				
		list<int>::iterator it;
		cout<<"current bfs node is "<<todo<<"-------------"<<endl;
		for(it=adj[todo].begin();it!=adj[todo].end();it++){
			if(visited[*it]==-1 ){
				queue.push_back(*it);
				visited[*it] = 1-visited[todo];
				cout<<*it<<" colored "<<1-visited[todo]<<endl;

			}else if(visited[*it]==visited[todo]){
				cout<<"problem "<<*it<<" "<<todo<<endl;
				return false;	
			}
		}
	}	
	return true;
}

int main(){
	
	Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 3);    
    g.addEdge(1, 2);    
    g.addEdge(2, 3);    
    
    g.bipartite(0)==1 ? cout<<"bipartite"<<endl: cout<<"not bipartite"<<endl;


	return 0;
}