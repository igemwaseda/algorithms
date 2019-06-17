#include <stdio.h>

int main()
{
	int n,m;
	scanf("%d %d", &n, &m);
	int left_max = 1;
	int right_min = 100000;
	int tmp_left, tmp_right;
	for ( int i = 0; i < m; i++ ) {
		scanf("%d %d", &tmp_left, &tmp_right);
		if ( tmp_left > left_max ) left_max = tmp_left;
		if ( tmp_right < right_min ) right_min = tmp_right;
	}
	int count = 0;
	for ( int i = 1; i <= n; i++ ) {
		if ( ( i >= left_max ) && ( i <= right_min ) ) count++;
	}
	printf("%d\n", count);
  return 0;
}
