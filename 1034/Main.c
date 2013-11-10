#include <stdio.h>
#include <stdlib.h>

void mysort1(int m, int *A);
void myinsert(int m, int temp, int *A);
void mysort2(int m, int *A);
void myswap(int *a, int *b);

int main()
{
	int n, m;
	int *A = NULL;
	int i;
	int temp;

	scanf("%d%d", &n, &m);
	while(n || m){
		m = m < n ? m : n;
		A = (int *)malloc(m * sizeof(int));
		for(i = 0; i < m; i++) scanf("%d", A + i);
		mysort1(m, A);
		for(; i < n; i++){
			scanf("%d", &temp);
			myinsert(m, temp, A);
		}
		mysort2(m, A);
		if(m) printf("%d", A[0]);
		for(i = 1; i < m; i++) printf(" %d", A[i]);
		putchar('\n');
		free(A);
		A = NULL;
		scanf("%d%d", &n, &m);
	}
	exit(0);
}

void mysort1(int m, int *A)
{
	int j;
	int k;
	int s;

	for(j = m / 2; j > -1; j--){
		k = j;
		s = 2 * j + 1;
		while(s + 1 <= m){
			if(s + 1 < m && A[s] > A[s+1]) s++;
			if(A[k] > A[s]){
				myswap(A + k, A + s);
				k = s;
				s = 2 * k + 1;
			}
			else break;
		}
	}
}

void myinsert(int m, int temp, int *A)
{
	int k;
	int s;

	if(temp > A[0]){
		A[0] = temp;
		k = 0;
		s = 1;
		while(s + 1 <= m){
			if(s + 1 < m && A[s] > A[s + 1]) s++;
			if(A[k] > A[s]){
				myswap(A + k, A + s);
				k = s;
				s = 2 * k + 1;
			}
			else break;
		}
	}
}

void mysort2(int m, int *A)
{
	int i;
	int k, s;
	int temp;

	for(i = m - 1; i > -1; i--){
		temp = A[i];
		A[i] = A[0];
		A[0] = temp;
		k = 0;
		s = 1;
		while(s + 1 <= i){
			if(s + 1 < i && A[s] > A[s+1]) s++;
			if(A[k] > A[s]){
				myswap(A + k, A + s);
				k = s;
				s = 2 * k + 1;
			}
			else break;
		}
	}
}

void myswap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
