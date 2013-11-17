#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int main()
{
	int i, j;
	int t;
	int sum;
	int A[60];
	int B[60];
	int e, g;

	e = g = 0;
	memset(A, '\0', sizeof(A));
	memset(B, '\0', sizeof(B));
	for(i = 2; i <= 60; i++){
		sum = 1;
		t = (int)sqrt(i);
		for(j = 2; j <= t; j++){
			if(!(i%j)) sum += j + i/j;
		}
		if(t * t == i) sum -= t;
		if(sum == i) A[e++] = i;
		else if(sum > i) B[g++] = i;
	}
	printf("E:");
	for(i = 0; A[i] != 0; i++) printf(" %d", A[i]);
	putchar('\n');
	printf("G:");
	for(i = 0; B[i] != 0; i++) printf(" %d", B[i]);
	putchar('\n');
	exit(0);
}
