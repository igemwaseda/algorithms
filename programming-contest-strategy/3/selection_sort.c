#include <stdio.h>

int find_min_index(int A[], int n, int head);

int main()
{
	int n;
	scanf("%d", &n);

	int A[n];
	for ( int i = 0; i < n; i++ ) {
		scanf("%d", &A[i]);
	}
	
	for ( int i = 0; i < n - 1; i++ ) {
		int min_index = find_min_index(A, n, i);
		if ( i != min_index ) {
			int tmp = A[i];
			A[i] = A[min_index];
			A[min_index] = tmp;
		}
	}
	
	for ( int i = 0; i < n; i++ ) {
		printf("%d ", A[i]);
	}
	printf("\n");
  return 0;
}


int find_min_index(int A[], int n, int head)
{
	int min_index = head;
	for ( int i = head; i < n; i++ ) {
		if ( A[min_index] > A[i]) min_index = i;
	}
	return min_index;
}
