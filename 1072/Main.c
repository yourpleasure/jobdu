#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int i, j, k;
	char A[189];

	memset(A, '\0', 189);
	for(i = 0; i < 5; i++)
		for(j = 0; j < 6; j++)
			for(k = 0; k < 7; k++)
				A[i * 10 + j * 8 + k * 18] = 1;
	j = 0;
	for(i = 1; i < 189; i++)
		if(A[i]) j++;
	printf("%d\n", j);
	exit(0);
}
