#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;

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

bool check(string p, string s){	
    int slen = s.size();
    int plen = p.size();
    
    vector<vector<bool>>dp(slen+1,vector<bool>(plen+1));
    dp[0][0]=true;dp[0][1]=false;
    
    for(int j=2;j<=plen;j++){
        dp[0][j] = p[j-1]=='*' ? dp[0][j-2] : false;
    }
    
    for(int i=1;i<=slen;i++){
        for(int j=1;j<=plen;j++){
            if(p[j-1]!='*'){
                dp[i][j] = dp[i-1][j-1] && (s[i-1]==p[j-1] || p[j-1]=='.');
            }else{
                dp[i][j] = j>1 && (dp[i][j-2] || (dp[i-1][j] && (s[i-1]==p[j-2]||p[j-2]=='.' )));
                //dp[i][j-2] skip current *
            }
        }
    }
    return dp[slen][plen];
}


int main() {
	string p,s;
	cin>>p>>s;
	cout<<p<<endl<<s<<endl;
	cout<<check(p,s)<<endl;
	return 0;
}