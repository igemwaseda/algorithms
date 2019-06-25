#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>

bool is_group (int n, int relations[n][n], int mem_num, int members[]);
void debug_members (int n, int members[]);
void debug_relations (int n, int relations[n][n]);

int main ()
{
	int n, m;
	scanf("%d %d", &n, &m);
	int x[m], y[m];
	int *member_cache = calloc (n, sizeof(int));
	int relations[n][n];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			relations[i][j] = 0;
		}
	}
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &x[i], &y[i]);
		member_cache[x[i]-1]++;
		member_cache[y[i]-1]++;
		relations[x[i]-1][y[i]-1] = 1;
		relations[y[i]-1][x[i]-1] = 1;
	}
	int max = 1;
	//debug_relations(n, relations);
	for (int i = 0; i < pow (2, n); i++) {
		int members[n];
		int mem_num = 0;
		bool is_broken = false;
		for (int j = 0; j < n; j++) {
			if (! ((i >> j) & 1)) continue;
		
			if (member_cache[j] == 0) {
				is_broken = true;
				goto LOOP_END;
			}
			members[mem_num] = j;
			mem_num++;
		}
		
		LOOP_END:
		if (is_broken == true) continue;
		if (mem_num <= max) continue;
		if (is_group (n, relations, mem_num, members) != true) continue;
		//debug_members(mem_num + 1, members);
		max = mem_num;
	}
	printf("%d\n", max);
	free(member_cache);
	return 0;
}

bool is_group (int n, int relations[n][n], int mem_num, int members[])
{
	if (mem_num <= 1) return false;
	for (int i = 0; i < mem_num - 1; i++) {
		for (int j = i + 1; j < mem_num; j++) {
			if (members[i] == members[j]) continue;
			if (relations[members[i]][members[j]] != 1) {
				return false;
			} 
			//printf ("same: %d %d\n", members[i], members[j]);
		}
	}
	return true;
}

void debug_members (int n, int members[])
{
	printf ("members: ");
	for (int i = 0; i < n; i++) {
		printf("%d ", members[i]);
	}
	printf("\n");
}

void debug_relations (int n, int relations[n][n])
{
	printf ("relations: \n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf ("%d ", relations[i][j]);
		}
		printf ("\n");
	}
}
