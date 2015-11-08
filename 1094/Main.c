#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char T[1000000];
static char P[1000000];
static unsigned long len;
static int *next = NULL;
static void init();
static int kmp();
int main()
{
	while(scanf("%s%s", T, P) != EOF){
		len = strlen(P);
		next = (int *)malloc(len * sizeof(int));
		memset(next, '\0', sizeof(int) * len);
		init();
		printf("%d\n", kmp());
		free(next);
		next = NULL;
	}
	exit(0);
}

static void init()
{
	int i, j;
	i = 0;
	j = -1;
	next[0] = -1;
	while(P[i] != '\0'){
		if(j == -1 || P[i] == P[j]){
			i++;
			j++;
			if(P[i] != P[j]) next[i] = j;
			else next[i] = next[j];
		}
		else{
			j = next[j];
		}
	}
}

static int kmp()
{
	int i, j;
	int count;

	i = 0;
	j = 0;
	count = 0;
	while(T[i] != '\0'){
		if(j == -1 || T[i] == P[j]){
			i++;
			j++;
			if(j == (int)len){
				count++;
				i -= len - 1;
				j = 0;
			}
		}
		else j = next[j];
	}
	return count;
}
