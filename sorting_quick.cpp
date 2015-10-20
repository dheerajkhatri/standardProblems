#include <bits/stdc++.h>
using namespace std;

void swap(int*arr, int pos1, int pos2){
	int temp = arr[pos1];
	arr[pos1] = arr[pos2];
	arr[pos2] = temp;
}

int partition(int* arr, int start, int end){
	int pIndex = start,pivot = arr[end];
	for(int i=start;i<end;i++){
		if(arr[i]<pivot){
			swap(arr,i,pIndex);
			pIndex++;
		}
	}
	swap(arr,pIndex,end);
	return pIndex;
}

void quickSort(int* arr, int start, int end){
	if(start<end){
		int pIndex = partition(arr,start,end);
		quickSort(arr,start,pIndex-1);
		quickSort(arr,pIndex+1,end);
	}
}


int main(){

	int i,*arr = new int[8];
	arr[0]=2;arr[1]=4;arr[2]=1;arr[3]=6;
	arr[4]=8;arr[5]=5;arr[6]=3;arr[7]=7;

	for(i=0;i<8;i++)cout<<arr[i]<<" ";cout<<endl;
	quickSort(arr,0,7);
	for(i=0;i<8;i++)cout<<arr[i]<<" ";cout<<endl;
	return 0;
}