#include <stdio.h>
#include <stdlib.h>

int main()
{
	int A[200];
	int n;
	int i;
	int x;
	while(scanf("%d", &n) != EOF){
		for(i = 0; i < n; i++) scanf("%d", A + i);
		scanf("%d", &x);
		for(i = 0; i < n; i++){
			if(x == A[i]){
				printf("%d\n", i);
				break;
			}
		}
		if(i == n) printf("-1\n");
	}
	exit(0);
}
