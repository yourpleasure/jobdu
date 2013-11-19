#include<stdio.h>
#include<stdlib.h>

int main()
{
	int N;
	int sum;

	while(scanf("%d", &N) != EOF){
		if(N > 0)
			sum = (N + 2 * N) * (N + 1) / 2;
		else
			sum = (N + 2 * N) * (1 - N) / 2;
		printf("%d\n", sum);
	}
	exit(0);
}
