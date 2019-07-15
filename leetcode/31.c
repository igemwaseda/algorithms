#include <stdio.h>
#define rep(i, a, n) for (i = (a); i < (n); i++)
#define unrep(i, a, n) for (i = (n) - 1; i >= (a); i--)

int pivot_index;
int pivot;
int suffix_swapped_index;
int findPivotIndex(int n, int ref[n])
{
	int i;
	int pivot_index = n - 1;
	unrep(i, 0, n - 1) {
		if (ref[i] < ref[pivot_index]) return  i;
		else pivot_index = i;
	}
	return -1;
}

int findSuffixSwappedIndex(int n, int ref[n])
{
	int i;
	int suffix_swapped_index = pivot_index + 1;
	rep(i, pivot_index + 2, n) {
		if (ref[i] >= ref[suffix_swapped_index]) continue;
		if (ref[i] <= pivot) continue;
		suffix_swapped_index = i;
	}
	return suffix_swapped_index;
}

void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void bubbleSort(int s, int n, int arr[n])
{
	int i, j;
	rep(i, s, n) {
		rep(j, s, n - i + s - 1) {
			if (arr[j] > arr[j + 1]) swap(&arr[j], &arr[j + 1]);
		}
	}
}

void printSingleArr(int n, int arr[n])
{
	int i;
	rep(i, 0, n) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void nextPermutation(int* nums, int numsSize){
    if (numsSize == 1) goto PRINT;
    pivot_index = findPivotIndex(numsSize, nums);
    if (pivot_index == -1) {
        bubbleSort(0, numsSize, nums);
        goto PRINT;
    }
    pivot = nums[pivot_index];
    suffix_swapped_index = findSuffixSwappedIndex(numsSize, nums);
    swap(&nums[suffix_swapped_index], &nums[pivot_index]);
    bubbleSort(pivot_index + 1,numsSize, nums);
    PRINT:
    printSingleArr(numsSize, nums);
}
