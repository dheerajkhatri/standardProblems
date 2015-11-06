#include <stdio.h>
int main()
 {
	int x=10,y=15;
	int i=0;
	int z;
	for(i=0;i<10;i++)x = x++;
	z = x++;
	y=++y;
	printf("%s\n", "bahut bar kar lia");
	printf("%d %d %d",x,y,z);
	return 0;
 }
