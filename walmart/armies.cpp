#include <bits/stdc++.h>
using namespace std;
typedef vector<vector<int>> V;

void dfs(V& arr, V& visited, int x, int y, int& count){		
	if(arr[x][y]==0)return;
	if(visited[x][y])return;	
	visited[x][y]=1;
	count++;
	int arrx[] = {-1,0,1,0};
	int arry[] = {0,1,0,-1};
	int n = arr.size();
	int m = arr[0].size();

	for(int k=0;k<4;k++){
		int curx = x+arrx[k];
		int cury = y+arry[k];
		if(curx>=0 && curx<n && cury>=0 && cury<m && !visited[curx][cury]){			
			dfs(arr,visited,curx,cury,count);			
		}
	}	
	return;
}

int main(){
	int n,m;
	cin>>n>>m;
	vector<vector<int>>arr(n,vector<int>(m));
	vector<vector<int>>visited(n,vector<int>(m,0));
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>arr[i][j];
		}
	}
	map<int,int>mm;	
	int totalcount = 0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(arr[i][j]==1 && visited[i][j]==0){				
				int cursize = 0;
				dfs(arr,visited,i,j,cursize);
				if(cursize){
					auto it = mm.find(cursize);
					if(it!=mm.end()){						
						mm[cursize]++;
						totalcount++;
					}else{
						mm[cursize] = 1;
						totalcount+=1;
					}	
				}
				
			}
		}
	}		
	cout<<totalcount<<endl;
	for(auto it = mm.begin();it!=mm.end();it++){		
		cout<<it->first<<" "<<it->second<<endl;
	}
	return 0;
}