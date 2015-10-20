#include <bits/stdc++.h>
using namespace std;
#define midround(start,end) (int(0.5+start+(end-start)/2.0))

void merge(int* left, int len1, int* right,int len2 , int *arr){

	int ll,lr,i,j,k;
	ll = len1;
	lr = len2;	

	for(i=j=k=0;i<len1 && j<len2 ; ){
		if(left[i]<=right[j]){
			arr[k++] = left[i++];
		}else{
			arr[k++] = right[j++];
		}
	}
	while(i<ll) arr[k++] = left[i++];	
	while(j<lr) arr[k++] = right[j++];	
	
	return;
}

void mergeSort(int* arr, int start, int end){
	int len = end-start+1;
	int mid = midround(start,end);
	int ll,lr,i;	

	if(len==1)return;	

	ll = mid-start;
	lr = end-mid+1;

	int *left,*right;
	left = new int[ll];
	right = new int[lr];

	//create left and right sublist
	for(i=0;i<ll;i++)left[i] = arr[start+i];
	for(i=0;i<lr;i++)right[i] = arr[mid+i];	

	mergeSort(left,0,ll-1);
	mergeSort(right,0,lr-1);
	merge(left,ll,right,lr,arr);
}

int main(){
	int i,*arr = new int[8];
	arr[0]=2;arr[1]=4;arr[2]=4;arr[3]=6;
	arr[4]=8;arr[5]=5;arr[6]=3;arr[7]=7;

	for(i=0;i<8;i++)cout<<arr[i]<<" ";cout<<endl;
	mergeSort(arr,0,7);
	for(i=0;i<8;i++)cout<<arr[i]<<" ";cout<<endl;
	return 0;
}