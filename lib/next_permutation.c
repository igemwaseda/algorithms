#include <stdio.h>
#include "rep.h"

#define REF_LENGTH 7
int ref[REF_LENGTH] = {0, 1, 2, 5, 3, 3, 0};
int pivot_index;
int pivot;
int suffix_swapped_index;

// functions from library
void printSingleArr(int n, int arr[n]);
void swap(int *a, int *b);
void bubbleSort(int s, int n, int arr[n]);

int findPivotIndex()
{
	int i;
	int pivot_index = REF_LENGTH - 1;
	unrep(i, 0, REF_LENGTH - 1) {
		if (ref[i] < ref[pivot_index]) return  i;
		else pivot_index = i;
	}
	return pivot_index;
}

int findSuffixSwappedIndex()
{
	int i;
	int suffix_swapped_index = pivot_index + 1;
	rep(i, pivot_index + 2, REF_LENGTH) {
		if (ref[i] >= ref[suffix_swapped_index]) continue;
		if (ref[i] <= pivot) continue;
		suffix_swapped_index = i;
	}
	return suffix_swapped_index;
}

int main()
{
	pivot_index = findPivotIndex();
	pivot = ref[pivot_index];
	suffix_swapped_index = findSuffixSwappedIndex();
	swap(&ref[pivot_index], &ref[suffix_swapped_index]);
	bubbleSort(pivot_index + 1, REF_LENGTH, ref);
	printSingleArr(REF_LENGTH, ref);
	return 0;
}
