#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n;
	scanf("%d",&n);
	
	int *R;
	R = (int *)malloc(sizeof(int) * n);
	for ( int i = 0; i < n; i++ ) {
		scanf("%d",&R[i]);
	}
	
	int min = R[0];
	int max = -100;

	for ( int i = 1; i < n; i++ ) {
		if ( max < R[i] - min ) max = R[i] - min;
		if( min > R[i] ) min = R[i];
	}
	printf("%d\n",max);
  return 0;
}
