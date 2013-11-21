#include<stdio.h>
#include<stdlib.h>
int yanghui(int m, int n);
int main()
{
	int n;

	while(scanf("%d", &n) != EOF)
		yanghui(n-1, n-1);
	exit(0);
}

int yanghui(int m, int n)
{
	int result;

	result = 1;
	if(m == 0 && n == 1){
		printf("1");
		return result;
	}
	else if(m == 0){
	   yanghui(n-1, n-1);
	   printf("1");
	   return result;
	}
	else{
		result = yanghui(m-1, n) * (n-m+1)/m;
		printf(" %d", result);
	}

	if(m == n) putchar('\n');
	return result;
}
