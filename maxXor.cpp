#include <bits/stdc++.h>
using namespace std;

struct Node{	
	Node *left,*right;	
	bool p;
	Node():left(NULL),right(NULL),p(false){}
};

Node* root = new Node();

string int2Binary(int n){
	string s = "";
	while(n){
		if(n%2)s.push_back('1');
		else s.push_back('0');
		n /= 2;
	}
	return s;
}

int getMax(string s){
	int n = s.length();
	int max = 0;
	int mul = 1;
	Node* crawl = root;

	for(int i=0;i<n;i++){
		if(crawl->left || crawl->right){

		}
		if(s[i]=='1'){
			if(root->left!=NULL){
				root = root->left;
				max = max*2+1;
			}else if(root->right!=NULL){

			}
		}else{

		}
	}
}

int maxXor(vector<int>&arr){
	int n = arr.size();
	int maxtill = INT_MIN;
	for(int i=0;i<n;i++){
		int cur = insertTrie(int2Binary(arr[i]));
		maxtill = max(maxtill,cur);
	}
	return maxtill;
}

int main(){
	
	return 0;
}