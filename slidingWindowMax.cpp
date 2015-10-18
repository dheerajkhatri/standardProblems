#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> vec;
        if(nums.size()==0)return vec;
        deque<int> dq(k);                

        int i,n=nums.size();

        for(i=0;i<k;i++){
        	while(!dq.empty() && nums[dq.back()] <= nums[i])
        		dq.pop_back();
        	dq.push_back(i);
        }

        for(;i<n;i++){

        	vec.push_back(nums[dq.front()]);

        	while(!dq.empty() && dq.front() <= i-k)
        		dq.pop_front();


        	while(!dq.empty() && nums[dq.back()] <= nums[i])
        		dq.pop_back();

        	dq.push_back(i);

        }

        vec.push_back(nums[dq.front()]);
        return vec;
    }

    void print(vector<int>v){
    	for(auto i:v)cout<<i<<" ";cout<<endl;
    }
};

int main(){
	Solution obj;
	vector<int> v = {};
	vector<int> result;
	result = obj.maxSlidingWindow(v,0);
	obj.print(result);
	return 0;
}