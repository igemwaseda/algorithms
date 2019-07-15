#include <stdio.h>
#include "rep.h"

void printSingleArr(int n, int arr[n])
{
	int i;
	rep(i, 0, n) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}
