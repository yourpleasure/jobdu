#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX 1000000001
unsigned long prime[4000];
unsigned long j;
unsigned long haha(unsigned long a)
{
	unsigned long result = 1;
	unsigned long temp;
	unsigned long k = 0;

	while(a > 1){
		temp = 1;
		while(!(a%prime[k])){
			temp ++;
			a /= prime[k];
		}
		k++;
		if(k == j) return result * 2;
		result *= temp;
	}
	return result;
}

int main()
{
	unsigned long N;
	unsigned long *A, *B;
	unsigned long *C;
	unsigned long a;
	unsigned long i;

	a = sqrt(MAX);
	C = (unsigned long *)malloc((a + 1) * sizeof(unsigned long));

	memset(C, '\0', (a+1) * sizeof(unsigned long));
	C[2] = 0;
	for(i = 2; i < a + 1; i += 2){
		if(!C[i]){
			for(j = 2 * i; j < a + 1; j += i){
				C[j] = 1;
			}
		}
		if(i == 2) i++;
	}
	j = 0;
	for(i = 2; i < a + 1; i++){
		if(!C[i]){
			prime[j] = i;
			j++;
		}
	}

	while(scanf ("%lu", &N) != EOF){
		A = (unsigned long *)malloc(N * sizeof(unsigned long));
		B = (unsigned long *)malloc(N * sizeof(unsigned long));
		for(i = 0; i < N; i++){
			scanf ("%lu", A + i);
		}
		for(i = 0; i < N; i++){
			if(A[i] == 1) B[i] = 1;
			else B[i] = haha(A[i]);
		}

		for(i = 0; i < N; i++){
			printf("%lu\n", B[i]);
		}

		free(A);
		free(B);
		A = B = NULL;
	}
	exit(0);
}
