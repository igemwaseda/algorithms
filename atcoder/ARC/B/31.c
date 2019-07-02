#include <stdio.h>
#include <stdbool.h>

#define H 10
#define W 10
int A[H][W];
bool seen[H][W];
bool flag = false;

void dfs(int i, int j)
{
	if (i < 0 || H <= i || j < 0 || W <= j) return;
	if (A[i][j] == 0) return;
	if (seen[i][j]) return;
	seen[i][j] = true;
	dfs(i, j + 1);
	dfs(i, j - 1);
	dfs(i + 1, j);
	dfs(i - 1, j);
}

bool isSingleLand()
{
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (A[i][j] == 0) continue;
			if (!seen[i][j]) return false;
		}
	}
	return true;
}

void initializeSeen()
{
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			seen[i][j] = false;
		}
	}
}

void debugA()
{
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			printf("%d ", A[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	char tmp;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			scanf(" %c", &tmp);
			A[i][j] = (tmp == 'x') ? 0 : 1;
		}
	}
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			initializeSeen();
			if (A[i][j] == 1) continue;
			else {
				A[i][j] = 1;
				dfs(i, j);
				if (isSingleLand()) {
					flag = true;
					goto RESULT;
				}
				A[i][j] = 0;
			}
		}
	}
	RESULT:
	if (flag) printf("YES\n");
	else printf("NO\n");
  return 0;
}
