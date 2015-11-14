/*:-Dheeraj Khatri*/
#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef long long LL;

void print(vi &v);

void print(vvi &vv);
int n,m,q;

int maxtime()

int solve(vi& air, vector<ii>& pos){

}

int main() {
	std::ios::sync_with_stdio(false);
	int T,t;
	cin>>T;
	for(int t=1;t<=T;t++){		
		cin>>n>>m>>q;
		vi air(m);
		for(int i=0;i<m;i++){
			cin>>air[i];
		}
		vector<ii>pos;
		for(int i=0;i<n;i++){
			int x,y;
			cin>>x>>y;
			pos.push_back(ii(x,y));
		}

		int res = solve(air,pos);
		cout<<"Case #"<<t<<": ";
		if(res==-1)cout<<"IMPOSSIBLE"<<endl;
		else cout<<res<<endl;
	}
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