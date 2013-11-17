#include<stdio.h>
#include<stdlib.h>

int main()
{
	char A[5];
	char temp;

	while(scanf("%s", A) != EOF){
		temp = A[0];
		A[0] = A[3];
		A[3] = temp;
		temp = A[1];
		A[1] = A[2];
		A[2] = temp;
		printf("%s", A);
		putchar('\n');
	}
	exit(0);
}
