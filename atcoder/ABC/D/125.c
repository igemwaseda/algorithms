#include <stdio.h>

int main()
{
	int N;
	scanf("%d",&N);
	unsigned long int sum = 0;
	double tmp;
	double min;
	int negative_counter = 0;
	for ( int i = 0; i < N; i++ ) {
		scanf("%lf",&tmp);
		if ( i == 0 ) {
			if ( tmp < 0 ) {
				min = -tmp;
			} else {
				min = tmp;
			}
		}
		if ( tmp < 0 ) {
			negative_counter++;
			tmp = -tmp;
			sum += tmp;
			if ( min > tmp ) min = tmp;
		} else {
			sum += tmp;
			if ( min > tmp ) min = tmp;
		}
	}
	if ( negative_counter % 2 != 0 ) {
		sum -= 2 * min;
	}
	printf("%ld\n",sum);
  return 0;
}
