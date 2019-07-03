#include <stdio.h>
#include <stdbool.h>

#define MAX_H 500
#define MAX_W 500
#define rep(i, a, n) for (i = (a); i < (n); i++)

int gy, gx;
int h, w;
int costs[MAX_H][MAX_W];
char map[MAX_H][MAX_W];
bool seen[MAX_H][MAX_W];

struct node {
	int i;
	int j;
	int cost;
};

struct node nodes[MAX_H * MAX_W];
int head = -1, tail = -1;

void push(int i, int j, int cost)
{
	tail++;
	nodes[tail].i = i;
	nodes[tail].j = j;
	nodes[tail].cost = cost;
}

struct node pop()
{
	return nodes[++head];
}

bool isEmpty()
{
	return head == tail;
}

void bfs()
{
	while(1) {
		if (isEmpty()) break;
		struct node current_node = pop();
		int i = current_node.i;
		int j = current_node.j;
		int cost = current_node.cost;
		if (i < 0 || j < 0 || h <= i || w <= j)  continue;
		if (map[i][j] != '.') continue;
		if (seen[i][j]) continue;
		seen[i][j] = true;
		costs[i][j] = cost;
		push(i, j + 1, cost + 1);
		push(i, j - 1, cost + 1);
		push(i + 1, j, cost + 1);
		push(i - 1, j, cost + 1);
	}
}

int main()
{
	scanf("%d %d", &h, &w);
	int sy, sx;
	scanf("%d %d ", &sy, &sx);
	sy--; sx--;
	scanf("%d %d ", &gy, &gx);
	gy--; gx--;
	int i, j; 
	rep (i, 0, h) {
		rep (j, 0, w) scanf(" %c", &map[i][j]);
		costs[i][j] = 0;
		seen[i][j] = false;
	}	
	push(sy, sx, 0);
	bfs();
	printf("%d\n", costs[gy][gx]);
	return 0;
}
