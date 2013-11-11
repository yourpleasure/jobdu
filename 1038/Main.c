#include <stdio.h>
#include <stdlib.h>
#include <string.h>
const unsigned long maxN = 1000000;

void initpackage(char *A);
int main()
{
	unsigned long n;
	char *A;

	A = (char *)malloc(maxN + 1);
	memset(A, '\0', maxN + 1);
	initpackage(A);
	while(scanf("%lu", &n) != EOF){
		if(A[n]) printf("YES\n");
		else printf("NO\n");
	}
	exit(0);
}

void initpackage(char *A)
{
	unsigned long B[10];
	unsigned long temp;
	int i;
	int k;

	temp = 1;
	i = 0;
	memset(B, '\0', sizeof(B));
	while(temp <= maxN){
		B[i] = temp;
		i++;
		temp *= i;
	}
	i--;

	A[0] = 1;
	for(k = 0; k < i; k++){
		for(temp = maxN; temp >= B[k]; temp--){
			if(A[temp-B[k]]) A[temp] = 1;
		}
	}
	A[0] = 0;
}
