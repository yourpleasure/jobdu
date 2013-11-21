#include<stdio.h>
#include<stdlib.h>
unsigned long A[10000];
void digui(int n);
int main()
{
	int n;

	while(scanf("%d", &n) != EOF)
		digui(n);
	exit(0);
}

void digui(int n)
{
	int i;
	if(n == 1){
		A[0] = 0;
	}
	else if(n == 2){
		digui(1);
		A[1] = 1;
		A[2] = 1;
	}
	else{
		digui(n-1);
		A[2*n-3] = A[2*n-4] + A[2*n-5];
		A[2*n-2] = A[2*n-3] + A[2*n-4];
	}
	printf("%lu", A[0]);
	for(i = 1; i < 2*n-1; i++)
		printf(" %lu", A[i]);
	putchar('\n');
}

