#include <bits/stdc++.h>
using namespace std;
#define N 1e6
vector<bool>prime(N,true);

void primeGen(){
	int n = N;
	int limit = sqrt(n);
	for(int i=2;i<=limit;i++){
		if(prime[i]==true){
			for(int j=i*i;j<n;j+=i){
				prime[j] = false;
			}
		}
	}
}

int main() {
	clock_t tstart = clock();
	primeGen();	
	int i,count;
	/*for(i=2,count=0;i<N;i++)
		if(prime[i]){cout<<i<<" ";count++;}*/
	cout<<endl<<count<<" primes"<<endl;	
	cout<<"time taken "<<(double)(clock()-tstart)/CLOCKS_PER_SEC<<endl;
	return 0;
}