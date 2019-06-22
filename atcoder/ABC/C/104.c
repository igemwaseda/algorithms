#include <stdio.h>
#include <math.h>

int main()
{
	int d, g;
	scanf("%d %d", &d, &g);
	
	int p[d], c[d], min = 0;
	for (int i = 0; i < d; i++) {
		scanf("%d %d", &p[i], &c[i]);
		min += p[i];
	}

	int sum, count, is_already_used[d];
	for (int i = 0; i < pow(2, d); i++) {
		sum = 0;
		count = 0;
		for (int j = 0; j < d; j++) {
			if ((i >> j) & 1) {
				sum += 100 * (j + 1) * p[j] + c[j];
				count += p[j];
				is_already_used[j] = 1;
			} else {
				is_already_used[j] = 0;
			}
		}
		
		if (sum <  g) {
			for (int i = d - 1; i >= 0; i--) {
				if (is_already_used[i] == 1) continue;
				int left = g - sum;
				if (left <= 100 * (i + 1) * (p[i] - 1)) {
					int rem = left % (100 * (i + 1));
					int div = left / (100 * (i + 1));
					count += (rem == 0) ? div : div + 1;
					sum += (rem == 0) ? 100 * (i + 1) * div : 100 * (i + 1) * (div + 1);
					goto COMPARE;
				}
			}
			continue;
		}

		COMPARE: if (min > count) min = count;
	}
	printf("%d\n", min);
	return 0;
}
