/*:-Dheeraj Khatri*/
#include <bits/stdc++.h>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	double x11,y11,x12,y12,x21,y21,x22,y22;	
	cout<<"line 1 point1 point2"<<endl;
	cin>>x11>>y11>>x12>>y12;
	cout<<"line 2 point1 point2"<<endl;
	cin>>x21>>y21>>x22>>y22;
	double x,y,det,a1,b1,c1,a2,b2,c2;
	a1 = y12-y11;
	a2 = y22-y21;
	b1 = x12-x11;
	b2 = x22-x21;
	c1 = a1*x11+b1*y11;
	c2 = a2*x21+b2*y21;
	cout<<"intersection point"<<endl;
	det = a1*b2-a2*b1;
	if(det==0){
		cout<<"-1"<<endl;		
	}else{
		x = (b2*c1-b1*c2)/det;
		y = (a1*c2-a2*c1)/det;
		double xmin = min(x11,x12);xmin = min(xmin,x21);xmin = min(xmin,x22);
		double xmax = max(x11,x12);xmax = max(xmax,x21);xmax = max(xmax,x22);
		double ymin = min(y11,y12);ymin = min(ymin,y21);ymin = min(ymin,y22);
		double ymax = max(y11,y12);ymax = max(ymax,y21);ymax = max(ymax,y22);
		//cout<<xmin<<" "<<xmax<<" "<<ymin<<" "<<ymax<<endl;
		if(x >= xmin && x <= xmax && y >= ymin && y <= ymax){
			cout<<x<<" "<<y<<endl;	
		}else{
			cout<<"-1"<<endl;
		}		
	}	
	return 0;
}