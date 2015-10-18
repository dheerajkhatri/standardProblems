#include <bits/stdc++.h>
using namespace std;

//longest increasing subsequence length in (NLOGN)
int main() {
	set<int>s;
	vector<int>arr = {10,22,9,33,21,50,41,60};
	int n = arr.size();
	
	for(int i=0;i<n;i++){
		s.insert(arr[i]);
		auto it = s.find(arr[i]);
		it++;
		if(it!=s.end()) //whether arr[i] can replace already present max element
			s.erase(it);
		//else means arr[i] is max element, so its extending present array
	}
	cout<<"LIS length is "<<s.size()<<endl;
	for(auto it:s)cout<<it<<" ";cout<<endl;
	return 0;
}