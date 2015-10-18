#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int min(int a, int b, int c){
		return std::min(a,std::min(b,c));
	}

    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        int dparr[n+1][m+1],val;
        

        for(int i=0;i<=n;i++){
        	for(int j=0;j<=m;j++){

        		if(i==0 || j==0){
        			if(i==0) dparr[i][j] = j;
        			else dparr[i][j] = i;
        		}else{
	        		if(word1[i-1]==word2[j-1])val=0;
	        		else val = 1;
        			dparr[i][j] = min(dparr[i-1][j]+1,dparr[i][j-1]+1,dparr[i-1][j-1]+val);
        			//cout<<"i j dparr[i][j] "<<i<<" "<<j<<" "<<dparr[i][j]<<endl;
        		}
        	}
        }

        return dparr[n][m];
    }
};

int main(){
	Solution obj;	
	cout<<obj.minDistance("kitten","spiten")<<endl;
	return 0;
}