#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char A[201];
	int i;
	char temp;
	int len;

	while(scanf("%s", A) != EOF){
		len = strlen(A) - 1;
		i = 0;
		while(i < len){
			temp = A[i];
			A[i++] = A[len];
			A[len--] = temp;
		}
		printf("%s\n", A);
	}
	exit(0);
}
