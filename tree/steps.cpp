/*:-Dheeraj Khatri*/
#include <iostream>
using namespace std;

int main() {
	int n;
	cin>>n;	
	if(n<0)n = -n;
	int i=1;


	if(n==0){cout<<0<<endl;return 0;}

	while(true){		
		if((i*(i+1))/2 >= n && (i*(i+1)/2 - n)%2==0){
			cout<<i<<endl;
			return 0;
		}
		i++;
	}
	return 0;
}