#include "rep.h"
void printSingleArr(int n, int arr[n]);
void swap(int *a, int *b);
void bubbleSort(int s, int n, int arr[n])
{
	int i, j;
	rep(i, s, n) {
		rep(j, s, n - i + s - 1) {
			if (arr[j] > arr[j + 1]) swap(&arr[j], &arr[j + 1]);
		}
	}
}
