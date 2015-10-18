#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
using namespace std;


vector<int> computeLPS(string pattern){
	int len = pattern.length();	
	vector<int>lps;
	if(!len)return lps;
	lps.resize(len);
	int i=1,maxmatch=0;
	lps[0] = 0;

	while(i<len){		
		//compute lps[i]
		if(pattern[i]==pattern[maxmatch]){	
			maxmatch++;
			lps[i] = maxmatch;
			i++;
		}else{			
			if(maxmatch){			
				maxmatch = lps[maxmatch-1];
			}else{				
				lps[i] = 0;
				i++;
			}
		}
	}	
	return lps;
}

void kmpSeach(string pattern, string text){
	int n = text.length();
	int m = pattern.length();	
	vector<int>lps = computeLPS(pattern);
	int i(0),j(0);	

	while(i<n){
		if(pattern[j]==text[i]){
			i++;
			j++;
		}
		if(j==m){
			cout<<"pattern found at "<<i-j<<endl;
			j = lps[j-1];
		}

		else if(i<n and pattern[j]!=text[i]){
			if(j){
				j = lps[j-1];
			}else{
				i++;
			}
		}
	}
	return;
}

int main(){
	kmpSeach("ABABCABAB","ABABDABACDABABCABAB");
	return 0;
}