#include <bits/stdc++.h>
using namespace std;
#define LEFT(x) 2*x+1
#define RIGHT(x) 2*x+2

void heapify_large(vector<int>&arr, int i){
	int n = arr.size();
	if(i<0 || i>=n)return;
	int largest = i;
	int left = LEFT(i);
	int right = RIGHT(i);

	if(left>=0 &&  left<n){
		if(arr[left]>arr[largest])
			largest = left;
	}

	if(right>=0 && right<n){
		if(arr[right]>arr[largest])
			largest = right;	
	}

	if(largest!=i){
		int temp = arr[i];
		arr[i] = arr[largest];
		arr[largest] = temp;
		heapify_large(arr,largest);
	}
}

void heapify_small(vector<int>&arr, int i){
	int n = arr.size();
	if(i<0 || i>=n)return;
	int smallest = i;
	int left = LEFT(i);
	int right = RIGHT(i);

	if(left>=0 &&  left<n){
		if(arr[left]<arr[smallest])
			smallest = left;
	}

	if(right>=0 && right<n){
		if(arr[right]<arr[smallest])
			smallest = right;	
	}

	if(smallest!=i){
		int temp = arr[i];
		arr[i] = arr[smallest];
		arr[smallest] = temp;
		heapify_small(arr,smallest);
	}	
}

void build_heap(vector<int>&arr){
	int n = arr.size();
	int start = floor(n/2.0)-1;
	for(int i=start;i>=0;i--){
		heapify_small(arr,i);
	}
	return;
}

void print(vector<int>&arr){
	for(int i=0;i<arr.size();i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}

int main(){
	
	vector<int>arr1 = {25,12,1,16,10};build_heap(arr1);print(arr1);
	vector<int>arr2 = {1,2,3,4,5,6,7};build_heap(arr2);print(arr2);
	vector<int>arr3 = {1,2,3,4,5,6};build_heap(arr3);print(arr3);
	vector<int>arr4 = {1,2,3,4,5};build_heap(arr4);print(arr4);		
	return 0;
}