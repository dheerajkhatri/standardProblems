/*http://cs.stackexchange.com/questions/10538/bit-what-is-the-intuition-behind-a-binary-indexed-tree-and-how-was-it-thought-a*/
#include <bits/stdc++.h>
using namespace std;

int getVal(vector<int>&bit, int index){
	int n = bit.size();
	index += 1;
	int sum = 0;
	while(index>0){
		sum += bit[index];
		index -= index&(-index);
	}
	return sum;
}

void updateTree(vector<int>&bit, int index, int val){
	int n = bit.size();
	index += 1;
	while(index<=n){
		bit[index] += val;
		index += index&(-index);
	}
}

vector<int> buildTree(vector<int>&in){
	int n = in.size();
	vector<int>bit(n+1,0);
	
	for(int i=0;i<n;i++){
		updateTree(bit,i,in[i]);
	}

	return bit;
}


int main(){
	vector<int>	in = {2, 1, 1, 3, 2, 3, 4, 5, 6, 7, 8, 9};
	vector<int> bit = buildTree(in);
	cout<<getVal(bit,3)<<endl;
	cout<<getVal(bit,4)<<endl;
	cout<<getVal(bit,5)<<endl;
	updateTree(bit,2,10);
	cout<<getVal(bit,3)<<endl;
	return 0;
}