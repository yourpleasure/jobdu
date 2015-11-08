#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i;
	int n;
	int A[31];
	A[0] = 0;
	A[1] = 1;
	for(i = 2; i <= 30; i++)
		A[i] = A[i-1] + A[i-2];
	while(scanf("%d", &n) != EOF)
		printf("%d\n", A[n]);
	exit(0);
}
