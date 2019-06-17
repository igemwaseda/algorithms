#include <stdio.h>

void swap(int **A, int **B);
void bubbleSort(int A[], int N);

int main()
{
	int N;
	scanf("%d",&N);
	int A[N];
	for ( int i = 0; i < N; i++ ) {
		scanf("%d",&A[i]);
	}
	bubbleSort(A, N);
  return 0;
}

void bubbleSort(int A[], int N)
{
	int flag = 1;
	int loop = 0;
	int counter = 0;
	while ( flag ) {
		flag = 0;
		loop++;
		for ( int i = N - 1; i > 0; i-- ) {
			if ( A[i] < A[i-1] ) {
				int tmp = A[i];
				A[i] = A[i-1];
				A[i-1] = tmp;
				counter++;
				flag = 1;
			}
		}
		printf("Loop%d : ", loop);
		for ( int j = 0; j < N; j++ ) {
			printf("%d ",A[j]);
		}
		printf("\n");
	}
	for ( int i = 0; i < N; i++ ) {
		printf("%d ", A[i]);
	}
	printf("\n%d\n", counter);
}
