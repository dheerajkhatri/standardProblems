/*:-Dheeraj Khatri*/
#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef long long LL;

void print(vi &v);

void print(vvi &vv);

void dfs(vvi& arr, int x, int y, int r, int c, vvi& visited){
	if(x<0 || y<0 || x>=r || y>=c)return;
	if(visited[x][y]==1 || arr[x][y]==0)return;	
	visited[x][y] = 1;

	int arrx[] = {-1,0,1,0};
	int arry[] = {0,1,0,-1};

	for(int k=0;k<4;k++){
		int curx = x+arrx[k];
		int cury = y+arry[k];
		dfs(arr,curx,cury,r,c,visited);
	}
}

int componenets(vvi& arr){ 
	int r = arr.size();
	int c = arr[0].size();
	vvi visited(r,vi(c,0));
	int curcount = 0;
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){			
			//cout<<i<<" "<<j<< " "<<arr[i][j]<<" "<<visited[i][j]<<endl;
			if(arr[i][j]==1 && visited[i][j]==0){				
				//cout<<i<<" "<<j<<"called"<<endl;
				curcount++;
				dfs(arr,i,j,r,c,visited);
			}
		}
	}
	return curcount;
}

int main() {
	std::ios::sync_with_stdio(false);
	clock_t t1,t2;
	t1 = clock();
	int T,t;
	cin>>T;
	for(int t=1;t<=T;t++){
		int r,c,q;
		cin>>r>>c;		
		vvi arr(r,vi(c));
		for(int i=0;i<r;i++){
			string s;cin>>s;
			for(int j=0;j<s.size();j++){
				if(s[j]=='0')arr[i][j]=0;
				else arr[i][j]=1;
			}
		}
		cin>>q;
		char qc;
		bool change = true;
		int com=0;
		cout<<"Case #"<<t<<":"<<endl;				
		while(q--){
			cin>>qc;
			if(qc=='Q'){
				if(change){
					com = componenets(arr);
					cout<<com<<endl;
					change = false;
				}else{
					cout<<com<<endl;
				}				
			}else if(qc=='M'){
				int x,y,val;
				cin>>x>>y>>val;
				if(arr[x][y]==val)continue;
				else{
					arr[x][y] = val;
					change = true;
				}
			}
		}

	}
	t2 = clock();
	//cout<<"time is "<<t2-t1/CLOCKS_PER_SEC<<endl;
	return 0;
}

void print(vi &v){
	for(auto it:v)
		cout<<it<<" ";
	cout<<endl;
}

void print(vvi &vv){
	for(auto it:vv){
		for(auto jt:it)
			cout<<jt<<" ";
		cout<<endl;
	}
}