#include <stdio.h>
#include <stdbool.h>

#define rep(i, a, n) for (i = (a); i < (n); i++)
#define MAX_H 50
#define MAX_W 50
#define QUEUE_SIZE ( MAX_H * MAX_W )
#define QUEUE_NEXT(n) (((n) + 1) % QUEUE_SIZE)

char map[MAX_H][MAX_W];
bool seen[MAX_H][MAX_W];
int costs[MAX_H][MAX_W];
int h, w;
int si = 0, sj = 0;
int gi, gj;

struct node {
	int i;
	int j;
	int cost;
};

struct node nodes[MAX_H * MAX_W];
int head = -1, tail = -1;

void push(int i, int j, int cost)
{
	tail = QUEUE_NEXT(tail);
	nodes[tail].i = i;
	nodes[tail].j = j;
	nodes[tail].cost = cost;
}

struct node pop()
{
	head = QUEUE_NEXT(head);
	return nodes[head];
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
		if (i < 0 || j < 0 || h  <= i || w <= j)  continue;
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
	gi = h - 1; gj = w - 1; 
	int i,j, white_counter = 0;
	rep(i, 0, h) {
		rep(j, 0, w) {
			scanf(" %c", &map[i][j]);
			seen[i][j] = false;
			if (map[i][j] == '.') white_counter++;
		}
	}
	push(si, sj, 0);
	bfs();
	int result = costs[gi][gj];
	if (result == 0) printf("-1\n");
	else printf("%d\n", white_counter - result - 1);
	return 0;
}
