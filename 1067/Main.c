#include<stdio.h>
#include<stdlib.h>

int main()
{
	unsigned long long A[20];
	int n;
	int i;

	A[0] = 1;
	for(i = 1; i < 20; i++){
		A[i] = A[i-1] * (i + 1);
	}
	while(scanf("%d", &n) != EOF)
		printf("%Lu\n", A[n-1]);
	exit(0);
}
