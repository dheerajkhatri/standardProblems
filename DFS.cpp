#include <bits/stdc++.h>
using namespace std;

class Graph{
	private:
		int v;
		list<int>*adj;
		void dfsutil(int node, bool* visited){			
			visited[node] =true;			
			cout<<node<<" ";

			for(auto it=adj[node].begin();it!=adj[node].end();it++){
				if(!visited[*it]){
					dfsutil(*it,visited);
				}
			}
		}

	public:
	Graph(int v);
	void addEdge(int u, int v);
	void BFS(int start);
	void DFS(int start);

};


Graph::Graph(int v){
		this->v = v;
		this->adj = new list<int>[v];
}

void Graph::addEdge(int u, int v){
	adj[u].push_back(v);
}

void Graph::BFS(int s){
	list<int>queue;
	bool* visited = new bool[v];
	for(int i=0;i<v;i++)visited[i]=false;

	queue.push_back(s);
	visited[s] = true;

	while(!queue.empty()){
		int todo = queue.front();
		queue.pop_front();
		cout<<todo<<" ";
		
			list<int>::iterator it;

			for(it=adj[todo].begin();it!=adj[todo].end();it++){
				if(!visited[*it]){
					queue.push_back(*it);
					visited[*it] = 1;
				}
			}
	}
	cout<<endl;
}

void Graph::DFS(int s){
	bool* visited = new bool[v];
	int i;
	for(i=0;i<v;i++)visited[i]=false;

	dfsutil(s,visited);

	for(i=0;i<v;i++){		
		if(!visited[i])dfsutil(i,visited);
	}	
}

int main(){
	
	Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
 	g.addEdge(4,5);
 	
    cout << "Following is Breadth First Traversal (starting from vertex 2) \n";
    g.BFS(2);

	cout << "Following is Depth First Traversal (starting from vertex 4) \n";
    g.DFS(4);cout<<endl;

	return 0;
}