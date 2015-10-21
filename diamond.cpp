#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;

void print(vvi& v){
	for(auto it:v){
		for(auto jt:it)
			cout<<jt<<" ";
		cout<<endl;
	}
}

int getDiamon(vvi& mat){
	int n = mat.size();
	vvi dm(n,vi(n,INT_MIN));	
	if(mat[0][0]==-1)return 0;
	dm[0][0] = mat[0][0]==1 ? 1:0;

	for(int i=1;i<n;i++){
		if(mat[0][i]!=-1 && mat[0][i-1]!=-1)
			dm[0][i] = mat[0][i]==1 ? dm[0][i-1]+1 : dm[0][i-1];			
	}

	for(int i=1;i<n;i++){
		if(mat[i][0]!=-1 && mat[i-1][0]!=-1)
			dm[i][0] = mat[i][0]==1 ? dm[i-1][0]+1 : dm[i-1][0];			
	}

	for(int i=1;i<n;i++){
		for(int j=1;j<n;j++){
			if(mat[i][j]!=-1 && (dm[i-1][j]!=INT_MIN || dm[i][j-1]!=INT_MIN)){				
				dm[i][j] = mat[i][j]==1 ? 1+max(dm[i][j-1],dm[i-1][j]) : max(dm[i][j-1],dm[i-1][j]);
			}
		}
	}
	//print(dm);

	//now modify original matrix to reduce diamonds
	int c = n-1, r = n-1;
	while(c>0 && r>0){
		if(mat[r][c]==1)
			mat[r][c] = 0;
		if(dm[r-1][c]>=dm[r][c-1])
			r--;
		else if(dm[r-1][c]<dm[r][c-1])
			c--;
	}
	while(c!=0){
		if(mat[r][c]==1)
			mat[r][c] = 0;
		c--;
	}
	while(r!=0){
		if(mat[r][c]==1)
			mat[r][c] = 0;
		r--;
	}
	if(mat[0][0]==1)mat[0][0]=0;
	return dm[n-1][n-1];
}


int main() {	
	int n;cin>>n;
	vvi mat(n,vi(n));
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>mat[i][j];
		}
	}
	int diam = getDiamon(mat);	
	cout<<"diamonds in first iteration = "<<diam<<endl;
	cout<<"After first iteration matrix is"<<endl;
	print(mat);
	diam += getDiamon(mat);	
	cout<<"total diamonds collected are = "<<diam<<endl;
	cout<<"After second iteration matrix is "<<endl;
	print(mat);
	return 0;
}