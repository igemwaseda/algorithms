#include <stdio.h>

int main()
{
	unsigned long N, min = 1000000000000000;
	unsigned long A;
	scanf("%ld",&N);
	for ( int i = 0; i < 5; i++ ) {
		scanf("%ld",&A);
		if ( A < min ) min = A;
	}
	unsigned long ans;
	if ( min >= N ) {
		ans = 5;
	} else if ( N % min == 0 ) {
		ans = N / min + 4;
	} else {
		ans = N / min + 5;
	}
	printf("%ld\n",ans);
  return 0;
}
