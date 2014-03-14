#include<stdio.h>
#include<stdlib.h>
#include<string.h>

const int mod = 10000;
int main()
{
	int p, q;
	int k;
	int i;
	int A[100002];

	memset(A, '\0', sizeof(A));
	while(scanf("%d%d%d%d%d", A, A+1, &p, &q, &k) != EOF){
		A[0] %= mod;
		A[1] %= mod;

		for(i = 2; i <= k; i++){
			A[i] = p * A[i-1] + q * A[i-2];
			A[i] %= mod;
			if(i == 100001){
				A[0] = A[100000];
				A[1] = A[100001];
				i = 1;
				k -= 100000;
			}
		}

		printf("%d\n", A[k]);
		memset(A, '\0', sizeof(A));
	}
	exit(0);
}
