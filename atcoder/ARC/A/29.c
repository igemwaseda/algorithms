#include <stdio.h>
#include <math.h>

int main()
{
	int n;
	scanf("%d", &n);
	int t[n], min = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &t[i]);
		min += t[i];
	}

	int one_sum, the_other_sum, time;
	for (int i = 0; i < pow(2, n); i++) {
		one_sum = 0;
		the_other_sum = 0;
		for (int j = 0; j < n; j++) {
			if ((i >> j) & 1) {
				one_sum += t[j];
			} else {
				the_other_sum += t[j];
			}
		}
		time = (one_sum > the_other_sum) ? one_sum : the_other_sum;
		if (min > time) min = time;
	}
	printf("%d\n", min);
	return 0;
}
