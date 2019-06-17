#include <stdio.h>

double  calcIndex(int n, int k, int val)
{
	int tmp = 1;
	double probability = (double) 1 / n;
	while ( 1 ) {
		if ( val * tmp  >= k ) break;
		tmp *= 2;
	}
	return (double) probability / tmp; 
}

int main()
{
	int n,k;
	double probability = 0;
	scanf("%d %d", &n, &k);
	for ( int val = 1; val <= n; val++ ) {
		probability += calcIndex(n, k, val);
	}
	printf("%.10f\n", probability);
	return 0;
}
