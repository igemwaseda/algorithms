#include <stdio.h>

int h,w;

void dfs(char c[h][w], int seen[h][w], int i, int j)
{
	if (i < 0 || h  <= i || j < 0 || w <= j || c[i][j] == '#') return;
	if (seen[i][j] == 1) return;
	seen[i][j] = 1;
	dfs(c, seen, i + 1, j);
	dfs(c, seen, i - 1, j);
	dfs(c, seen, i, j + 1);
	dfs(c, seen, i, j - 1);
	return;
}

void showResults(int h, int w, int seen[h][w])
{
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (seen[i][j] == 1) printf("1 ");
			else printf("0 ");
		}
		printf("\n");
	}
}

int main()
{
	scanf("%d %d", &h, &w);
	char c[h][w];
	int seen[h][w];
	int si, sj, gi, gj;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			scanf(" %c", &c[i][j]);
			seen[i][j] = 0;
			if (c[i][j] == 'g') {
				gi = i;
				gj = j;
			} else if (c[i][j] == 's') {
				si = i;
				sj = j;
			}
		}
	}
	dfs(c, seen, si, sj);
	if (seen[gi][gj] == 1) printf("Yes\n");
	else printf("No\n");
  return 0;
}
