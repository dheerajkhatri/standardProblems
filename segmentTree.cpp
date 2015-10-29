//implement Segment tree
#include <bits/stdc++.h>
using namespace std;
vector<int>st,arr;

//i update position in arr
void updateUtil(int ss, int se, int i, int diff, int si){
	if(i<ss || i>se) return;
	st[si] += diff;
	
	if(ss!=se){
		int mid = ss+(se-ss)/2;
		updateUtil(ss,mid,i,diff,2*si+1);
		updateUtil(mid+1,se,i,diff,2*si+2);
	}
}

void update(int pos, int value){
	int n = arr.size();
	if(pos<0 || pos>=n)return;
	int diff = value - arr[pos];
	updateUtil(0,n-1,pos,diff,0);
}

int findSumUtil(int ss, int se, int qs, int qe, int si){
	if(qs<=ss && qe>=se)
		return st[si];
		
	if(qs>se || qe<ss)return 0;
	
	int mid = ss+(se-ss)/2;
	return findSumUtil(ss,mid,qs,qe,2*si+1) + findSumUtil(mid+1,se,qs,qe,2*si+2);
}

int findSum(int qs,int qe){
	int n = arr.size();
	if(qs<0 || qe>=n)return -999;
	return findSumUtil(0,n-1,qs,qe,0);
}

// arr[ss,.....,se]
int build(vector<int>&arr, vector<int>&st, int ss, int se, int si){
	if(ss==se){
		st[si] = arr[ss];
		return st[si];
	}
	
	int mid = ss + (se-ss)/2;
	st[si] = build(arr,st,ss,mid,si*2+1)+build(arr,st,mid+1,se,si*2+2);
	return st[si];
	
}

vector<int> makeTree(vector<int>& arr){
	int len = arr.size();
	int x = (int)ceil(log2(len)); //height
	int maxsize = 2*(int)(pow(2,x)) - 1;//max size of segment tree
	vector<int>st(maxsize,0);
	build(arr,st,0,len-1,0);
	return st;
}

void print(vector<int>&v){
	for(auto it:v)cout<<it<<" ";
}

int main(){
	vector<int> in = {1,3,5,7,9,11};
	arr = in;
	st = makeTree(arr);
	cout<<"segmetn tree is ";print(st);cout<<endl;
	cout<<findSum(0,5)<<endl;
	cout<<findSum(1,5)<<endl;
	cout<<findSum(2,4)<<endl;
	update(1,0);
	update(2,1);
	cout<<"segment tree is ";print(st);cout<<endl;
	cout<<findSum(0,5)<<endl;
}