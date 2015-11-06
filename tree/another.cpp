#include <bits/stdc++.h>

using namespace std;

const int maxn=10000;

unordered_map< string,int > hashTable;
int dp[maxn];

int LongestChain(vector<string> V)
{

	vector< pair<int,string> > list;
	for (auto s:V){
		list.push_back({s.size(),s});
	}
	sort(list.begin(),list.end());
	
	int N=list.size();
	hashTable.insert( {list[0].second,1} );
	dp[0]=1;

	int answer=dp[0];

	for (int i=1;i<N;i++){
		dp[i]=1;
		string s=list[i].second;
		
		int size = s.size();
		for (int j=0;j<size;j++){
			
			string tmpStr = s;
			tmpStr.erase(tmpStr.begin()+j);
			auto it = hashTable.find(tmpStr);

			if (it!=hashTable.end())
				dp[i] = max (dp[i],dp[it->second]+1);
		}
		answer = max ( answer , dp[i]);

		hashTable.insert({s,i});

	}

	return answer;
}



int main()
{

	int N;
	cin >> N;
	vector<string> V(N);
	for (int i=0;i<N;i++)
		cin >> V[i];

	cout << LongestChain(V) << endl;


	return 0;
}