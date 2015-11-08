#include <stdio.h>
#include <stdlib.h>
#include <string.h>
static void print(int i);
int main()
{
	unsigned int n;
	while(scanf("%u", &n) != EOF){
		print(n);
		putchar('\n');
	}
	exit(0);
}

static void print(int i)
{
	int A[16] = {0};
	int j = 0;
	int flag = 1;
	while(i){
		if(i & 1) A[j] = 1;
		j++;
		i >>= 1;
	}
	for(i = j - 1; i > 1; i--){
		if(A[i] && flag){
			printf("2(");
			print(i);
			printf(")");
			flag = 0;
		}
		else if(A[i]){
			printf("+2(");
			print(i);
			printf(")");
		}
	}
	if(A[1] == 0 && A[0] == 1){
		if(!flag) putchar('+');
		printf("2(0)");
		return ;
	}
	else if(A[1] == 1 && A[0] == 0){
		if(!flag) putchar('+');
		printf("2");
		return ;
	}
	else if(A[1] == 1 && A[0] == 1){
		if(!flag) putchar('+');
		printf("2+2(0)");
		return ;
	}
	return ;
}

