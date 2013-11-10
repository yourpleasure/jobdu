#include <stdio.h>
#include <stdlib.h>

int findrelation(int first, int second);
void printrelation(int j);
char A[26][2];
int main()
{
	int n, m;
	int i, j;
	char son, father, mother;
	char first, second;

	scanf("%d%d", &n, &m);
	while(n || m){
		getchar();
		for(i = 0; i < 26; i++) A[i][0] = A[i][1] = i;
		for(i = 0; i < n; i++){
			son = getchar();
			father = getchar();
			mother = getchar();
			getchar();
			son -= 'A';
			if(father != '-') A[(int)son][0] = father - 'A';
			if(mother != '-') A[(int)son][1] = mother - 'A';
		}
		for(i = 0; i < m; i++){
			first = getchar();
			second = getchar();
			getchar();
			first -= 'A';
			second -= 'A';
			if((j = findrelation(first, second)) != 0)
				printrelation(j);
			else printf("-\n");
		}
		scanf("%d%d", &n, &m);
	}
	exit(0);
}

int findrelation(int first, int second)
{
	int i, j, k, l, m;
	int result;
	int B[26];

	result = 0;
	for(i = 0; i < 26; i++) B[i] = 0;
	B[0] = first;
	i = 0;
	l = 1;
	while(i != l){
		result++;
		j = l;
		k = i;
		while(i != j){
			m = B[i];
			if(A[m][0] != m) B[l++] = A[m][0];
			if(A[m][1] != m) B[l++] = A[m][1];
			i++;
		}
		for(;k < j; k++)
			if(B[k] == second) return result;
	}

	result = 0;
	for(i = 0; i < 26; i++) B[i] = 0;
	B[0] = second;
	i = 0;
	l = 1;
	while(i != l){
		result++;
		j = l;
		k = i;
		while(i != j){
			m = B[i];
			if(A[m][0] != m) B[l++] = A[m][0];
			if(A[m][1] != m) B[l++] = A[m][1];
			i++;
		}
		for(;k < j; k++)
			if(B[k] == first) return -result;
	}

	return 0;
}

void printrelation(int j)
{
	int i;

	i = j > 0 ? j : -j;
	while(i-- > 3) printf("great-");
	if(i == 2 && j > 0) printf("grandchild\n");
	else if(i == 2 && j < 0) printf("grandparent\n");
	else if(i == 1 && j > 0) printf("child\n");
	else if(i == 1 && j < 0) printf("parent\n");
}

