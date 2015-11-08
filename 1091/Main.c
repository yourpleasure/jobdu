#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INF 1000000
int s[2], d[2];
int A[6][6];
int visit[6][6];
int dir[4][2] = {
	{0, -1},
	{1, 0},
	{0, 1},
	{-1, 0}
};
int minPri;
static void DFS(int s0, int s1, int val, int state);
int main()
{
	int n;
	int i, j;

	scanf("%d", &n);
	while(n-- > 0){
		for(i = 0; i < 6; i++)
			for(j = 0; j < 6; j++)
				scanf("%d", A[i]+j);
		memset(visit, '\0', sizeof(visit));
		scanf("%d%d%d%d", s, s+1, d, d+1);
		minPri = INF;
		DFS(s[0], s[1], 0, 1);
		printf("%d\n", minPri);
	}
	exit(0);
}

static void DFS(int s0, int s1, int val, int state)
{
	int t0, t1;
	int i;
	int price, tempstate;
	if(val > minPri) return;
	if((s0 == d[0]) && (s1 == d[1])){
		if(minPri > val) minPri = val;
		return;
	}
	for(i = 0; i < 4; i++){
		t0 = s0 + dir[i][0];
		t1 = s1 + dir[i][1];
		if(t0 < 0 || t0 > 5 || t1 < 0 || t1 > 5 || visit[t0][t1]) continue;
		price = state * A[t0][t1];
		tempstate = price % 4 + 1;
		price += val;
		visit[t0][t1] = 1;
		DFS(t0, t1, price, tempstate);
		visit[t0][t1] = 0;
	}
}
