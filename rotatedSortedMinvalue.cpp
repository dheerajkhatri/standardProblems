#include <bits/stdc++.h>
using namespace std;

int findMin(vector<int>&arr, int left, int right){
	if(left==right)return arr[left];
	else if(right == left+1) return min(arr[left],arr[right]);
	
	int mid = left + (right-left)/2;
	
	if(arr[left] < arr[right]) //already sorted
		return arr[left];
	else if(arr[left] == arr[right]) // move by one step
		return findMin(arr,left+1,right);
	else if(arr[mid] >= arr[right]) //goto right side
		return findMin(arr,mid,right);
	else 						//goto left side
		return findMin(arr,left,mid);
}

int main(){
	vector<int> arr1 = {3,3,1,3,3};
	cout<<findMin(arr1,0,arr1.size()-1)<<endl;
	
	vector<int> arr2 = {2,2,3,3,1,2,2};
	cout<<findMin(arr2,0,arr2.size()-1)<<endl;
}