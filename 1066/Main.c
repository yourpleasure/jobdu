#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	char A[21];
	int i, j;
	char c;

	while(scanf("%s", A) != EOF){
		for(i = strlen(A) - 1; i > 0; i--){
			for(j = 0; j < i; j++)
				if(A[j] > A[j+1]){
					c = A[j+1];
					A[j+1] = A[j];
					A[j] = c;
				}
		}
		puts(A);
	}
	exit(0);
}
