#include <bits/stdc++.h>
using namespace std;
typedef vector<vector<int>> vvi;

void readEdge(vvi& g){
	ifstream reader("in.txt");
	int n,s,e,i=0,val;
	reader>>n;	
	g.resize(n);
	string line;	
	getline(reader,line);//skip first newline

	while(getline(reader,line)){		
		stringstream linedata(line);	
		while(linedata >> val){			
			g[i].push_back(val);			
		}				
		i++;
	}	
}

void print(vvi& vv){
	for(auto it:vv){
		for(auto jt:it)
			cout<<jt<<" ";		
		cout<<endl;
	}
}

vvi bfs(vvi& g){
	int n = g.size();
	vector<vector<int>>bfsv;
	vector<int>visited(n,0);
	vector<int>cur;
	cur.push_back(0);
	visited[0] = 1;

	while(!cur.empty()){
		bfsv.push_back(cur);
		vector<int>next;	

		for(auto it:cur){
			int val = it;			
			for(int i=0;i<g[val].size();i++){
				if(!visited[g[val][i]]) {
					next.push_back(g[val][i]);
					visited[g[val][i]] = 1;
				}
			}
		}
		cur.clear();
		cur = next;		
	}

	return bfsv;	
}

void dfs(vvi& g){
	
}

int main(){		
	vvi	graph;
	cout<<"reading graph..."<<endl;
	readEdge(graph);
	cout<<"printing graph.."<<endl;
	print(graph);	
	cout<<"starting bfs.."<<endl;
	vector<vector<int>>bfsv = bfs(graph);
	cout<<"printing bfs.."<<endl;
	print(bfsv);
}