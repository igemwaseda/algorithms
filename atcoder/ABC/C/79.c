#include <stdio.h>
#include <math.h>
#include <string.h>
#define LEN 4
#define SPACE 3

int main()
{
	int operands[LEN];
	char spaces[SPACE];
	char left[100];
	int index, sum;
	const char *operators[2] = {"+", "-"};
	scanf("%1d%1d%1d%1d", &operands[0], &operands[1], &operands[2], &operands[3]);

	for (int i = 0; i < pow(2, SPACE); i++) {
		sprintf(left, "%d", operands[0]);
		index = 0;
		sum = operands[0];
		for (int j = 0; j < SPACE; j++) {
			if ((i >> j) & 1) {
				sprintf(left, "%s%s%d", left, "+", operands[index+1]);
				sum += operands[index+1];
			} else {
				sprintf(left, "%s%s%d", left, "-", operands[index+1]);
				sum -= operands[index+1];
			}
			index++;
		}
		if (sum == 7) goto FINAL;
	}
	FINAL: printf("%s=7\n", left);
  return 0;
}
