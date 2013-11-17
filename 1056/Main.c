#include<stdio.h>
#include<stdlib.h>

int main()
{
	int a, b;
	int c;
	
	while(scanf("%d%d", &a, &b) != EOF){
		if(a < b){
			c = a;
			a = b;
			b = c;
		}
		while(a % b){
			c = a % b;
			a = b;
			b = c;
		}

		printf("%d\n", b);
	}
	exit(0);
}
