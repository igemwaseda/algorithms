#include <stdio.h>
#include <stdbool.h>
#define LEN 3

int are_all_positive(int a[LEN], int b[LEN])
{
	return ((a[0] >= 0) && (a[1] >= 0) && (a[2] >= 0) && (b[0] >= 0) && (b[1] >= 0) && (b[2] >= 0));
}

int is_matched(int a[LEN], int b[LEN], int c[LEN][LEN])
{
	return ((c[0][1] == a[0] + b[1]) && (c[0][2] == a[0] + b[2]) && (c[1][2] == a[1] + b[2]) && (c[2][0] == a[2] + b[0]));
}

int main()
{
	int c[LEN][LEN];
	int a[LEN], b[LEN];
	bool is_correct = false;
	
	for (int i = 0; i < LEN; i++) {
		scanf("%d %d %d", &c[i][0], &c[i][1], &c[i][2]);
	}
	
	a[0] = 0;
	while (1) {
		if (a[0] > c[0][0]) goto RESULT;
		b[0] = c[0][0] - a[0];
		a[1] = c[1][0] - b[0];
		b[1] = c[1][1] - a[1];
		a[2] = c[2][1] - b[1];
		b[2] = c[2][2] - a[2];

		if (!is_matched(a, b, c)) goto INCREMENT;
		if (are_all_positive(a, b)) {
			is_correct = true;
			goto RESULT;
		}	
		INCREMENT:a[0]++;
	}
	
	RESULT:if (is_correct == true) {
		printf("Yes\n");
	} else {
		printf("No\n");
	}
  return 0;
}
