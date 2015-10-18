#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int onexor=0,twoxor=0,notthree,temp;        

        for(int i=0;i<nums.size();i++){
        	temp = nums[i];
        	twoxor = twoxor | (onexor & temp);
        	onexor = onexor ^ temp;
        	
        	notthree = ~(onexor & twoxor);
        	onexor = onexor & notthree;
        	twoxor = twoxor & notthree;
        }

        if(onexor)return onexor;
        else return twoxor;
    }
};

int main(){

	vector<int> v;
	v.push_back(1);
	v.push_back(1);
	v.push_back(1);
	v.push_back(2);
	v.push_back(2);
	v.push_back(2);
	Solution obj;
	cout<<obj.singleNumber(v)<<endl;
	return 0;
}




/*

Explanation for step 1
------------------------
Lets say a new element(x) appears.
CURRENT SITUATION - Both variables - "ones" and "twos" has not recorded "x".

Observe the statement "twos| = ones & x".
Since bit representation of "x" is not present in "ones", AND condition yields nothing. So "twos" does not get bit representation of "x".
But, in next step "ones ^= x" - "ones" ends up adding bits of "x". Thus new element gets recorded in "ones" but not in "twos".

The last 3 lines of code as explained already, converts common 1's b/w "ones" and "twos" to zeros.
Since as of now, only "ones" has "x" and not "twos" - last 3 lines does nothing.

Explanation for step 2.
------------------------
Lets say an element(x) appears twice.
CURRENT SITUATION - "ones" has recorded "x" but not "twos".

Now due to the statement, "twos| = ones & x" - "twos" ends up getting bits of x.
But due to the statement, "ones ^ = x" - "ones" removes "x" from its binary representation.

Again, last 3 lines of code does nothing.
So ultimately, "twos" ends up getting bits of "x" and "ones" ends up losing bits of "x".

Explanation for step 3.
-------------------------
Lets say an element(x) appears for the third time.
CURRENT SITUATION - "ones" does not have bit representation of "x" but "twos" has.

Though "ones & x" does not yield nothing .. "twos" by itself has bit representation of "x". So after this statement, "two" has bit representation of "x".
Due to "ones^=x", after this step, "one" also ends up getting bit representation of "x".

Now last 3 lines of code removes common 1's of "ones" and "twos" - which is the bit representation of "x".
Thus both "ones" and "twos" ends up losing bit representation of "x".


Explanation becomes much more complicated when there are more elements in the array in mixed up fashion. But again due to associativity of XOR operation - We actually end up getting answer.*/