#include <stdio.h>

int main (void) {
		
	double S,W,H,x,y;
	
	scanf("%lf %lf %lf %lf",&W,&H,&x,&y);	
	S = W*H/2;
	int P = (x == W/2 && y == H/2)? 1 : 0;
	printf("%lf %d\n",S,P);

	return 0;

}
