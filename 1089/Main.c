#include <stdio.h>
#include <stdlib.h>
int reverse(int a)
{
	int k;

	k = 0;
	while(a){
		k = k * 10 + a % 10;
		a /= 10;
	}
	return k;
}

int main()
{
	int a, b;
	int n;
	int i;

	while(scanf ("%d", &n) != EOF){
		for(i = 0; i < n; i++){
			scanf ("%d%d", &a, &b);
			if(reverse(a + b) == reverse(a) + reverse(b))
				printf("%d\n", a+b);
			else printf("NO\n");
		}
	}
	exit(0);
}
