#include <bits/stdc++.h>
using namespace std;

typedef list<int>LI;
typedef pair<int,LI::iterator>PI;
typedef unordered_map<int,PI> HIPI;

class LRU{
private:
	int capacity;
	LI curKeys;
	HIPI cache;

	void touch(HIPI::iterator it){
		int key = it->first;
		curKeys.erase(it->second.second);
		curKeys.push_front(key);
		(it->second).second = curKeys.begin();
	}

public:
	LRU(int capacity){
		curKeys.clear();
		cache.clear();
		this->capacity = capacity;
	}
	void set(int key, int value){
		auto it = cache.find(key);
		if(it!=cache.end())	
			touch(it);
		else{
			if(curKeys.size()==capacity){
				cache.erase(curKeys.back());
				curKeys.pop_back();
			}
			curKeys.push_front(key);			
		}
		//can be different value for same key at different time so outside else
		cache[key] = make_pair(value,curKeys.begin());	
	}

	int get(int key){
		HIPI::iterator it = cache.find(key);
		if(it==cache.end())return -1;
		touch(it);
		return (it->second).first;
	}
};


int main(){
	LRU ll(3);
	ll.set(1,2);
	ll.set(2,4);
	cout<<ll.get(1)<<endl;
	cout<<ll.get(1)<<endl;
	ll.set(1,3);
	cout<<ll.get(1)<<endl;
	cout<<ll.get(2)<<endl;
	ll.set(1,2);
	cout<<ll.get(1)<<endl;
	ll.set(3,6);
	cout<<ll.get(1)<<endl;
	ll.set(4,8);
	cout<<ll.get(1)<<endl;
	cout<<ll.get(2)<<endl;
	cout<<ll.get(3)<<endl;
	cout<<ll.get(4)<<endl;
	return 0;
}