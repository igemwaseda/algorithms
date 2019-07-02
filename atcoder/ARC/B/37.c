#include <stdio.h>
#include <stdbool.h>

int n, m;
int count = 0;
bool seen[100];
int edges[100][100];

#define rep(i, a, n) for (i = (a); i < (n); i++)

int dfs(bool seen[], int edges[100][100], int index, int from)
{
	int i;
	if (seen[index]) return 0;
	seen[index] = true;
	rep (i, 0, n) {
		if (edges[index][i] == 1 && i != from) {
			if (dfs(seen, edges, i, index) != 1) return 0;
		}
	}
	return 1;
}

int main()
{
	scanf("%d %d", &n, &m);
	int i, j, u, v; 
	rep (i, 0, m) {
		scanf("%d %d", &u, &v);
		u--; v--;
		edges[u][v] = edges[v][u] = 1;
	}
	rep (i, 0, n) count += dfs(seen, edges, i, -1);
	printf("%d\n", count);
	return 0;
}
