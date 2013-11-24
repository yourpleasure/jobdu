#include<stdio.h>
#include<stdlib.h>

int main()
{
	long N;
	long i;
	long long *A = NULL;
	long long max;
	long long tempmax;
	long long tempsum;

	while(scanf("%ld", &N) != EOF){
		A = (long long *)malloc(N * sizeof(long long));
		for(i = 0; i < N; i++)
			scanf("%Ld", A+i);
		i = 0;
		while(i < N && A[i++] < 0);
		if(i == N){
			max = A[0];
			for(i = 1; i < N; i++){
				if(A[i] > max) max = A[i];
			}
		}
		else{
			i--;
			while(A[--N] < 0);
			max = 0;
			for(; i <= N; i++){
				tempmax = 0;
				tempsum = 0;
				while(i <= N && tempsum >= 0){
					tempsum += A[i];
					if(tempmax < tempsum) tempmax = tempsum;
					i++;
				}
				if(tempmax > max) max = tempmax;
				i--;
			}
		}
		printf("%Ld\n", max);
		free(A);
		A = NULL;
	}
	exit(0);
}
