#include <stdio.h>

int main()
{
	int num, sum;
	int x, y, z;
	int judge = 0;
	int val[3] = {10000, 5000, 1000};
	scanf("%d %d", &num, &sum);
	
	for (x = 0; x <= num; x++) {
		for (y = 0; x + y <= num; y++) {
			z = num - (x + y);
			int count = x * val[0] + y * val[1] + z * val[2];
			if (count == sum) {
				judge = 1;
				goto RESULT;
			}
		}
	}
	
	RESULT:if (judge == 0) {
		printf("-1 -1 -1\n");
	} else {
		printf("%d %d %d\n", x, y, z);
	}
  return 0;
}
