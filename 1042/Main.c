#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int longest(int a, int b);
char A[101];
char B[101];
int main()
{

	while(scanf("%s%s", A, B) != EOF){
		printf("%d\n", longest(strlen(A), strlen(B)));
	}
	exit(0);
}

int longest(int a, int b)
{
	int i, j;

	if(a == 0 || b == 0)
		return 0;
	if(A[a-1] == B[b-1])
		return longest(a-1, b-1) + 1;
	else{
		i = longest(a-1, b);
		j = longest(a, b-1);
		return i > j ? i: j;
	}
}
