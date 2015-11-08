#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int A[500001];
int main()
{
	int N;
	int i;
	int mod = 1000000000;

	memset(A, 0, sizeof(A));
	A[0] = 1;
	for(i = 1; i < 500001; i++){
		A[i] = (A[i-1] + A[i/2]) % mod;
	}

	while(scanf("%d", &N) != EOF){
		printf("%d\n", A[N/2]);
	}
	exit(0);
}
