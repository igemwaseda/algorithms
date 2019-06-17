#include <stdio.h>
#include <stdlib.h>

void insertionSort(int A[],int N);
void printArray(int A[],int N);

int main()
{
	int N;
	scanf("%d",&N);
	
	int *A;
	A = (int *) malloc(sizeof(int) * N);
	for ( int i = 0; i < N; i++ ) {
		scanf("%d",&A[i]);
	}

	printf("Original array : ");
	printArray(A,N);
	insertionSort(A,N);
	printf("Sorted array : ");
	printArray(A,N);
  return 0;
}

void insertionSort(int A[],int N)
{
	int v,j;
	for( int i = 0; i < N; i++ ) {
		v = A[i];
		j = i - 1;
		while( j >= 0 && A[j] > v ) {
			A[j+1] = A[j];
			j--;
		}
		A[j+1] = v;
	}
}

void printArray(int A[],int N)
{
	for ( int i = 0; i < N; i++ ) {
		printf("%d ",A[i]);
	}
	printf("\n");
}
