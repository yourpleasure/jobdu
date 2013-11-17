#include <stdio.h>
#include <stdlib.h>

int main()
{
	int A[20];
	int i;
	int max, maxi;
	int min, mini;
	int n;

	while(scanf("%d", &n) != EOF){
		scanf("%d", A);
		max = min = *A;
		maxi = mini = 0;
		for(i = 1; i < n; i++){
			scanf("%d", A + i);
			if(max < A[i]){
				max = A[i];
				maxi = i;
				continue;
			}
			if(min > A[i]){
				min = A[i];
				mini = i;
				continue;
			}
		}
		i = A[maxi];
		A[maxi] = A[mini];
		A[mini] = i;
		printf("%d", *A);
		for(i = 1; i < n; i++)
			printf(" %d", *(A + i));
		putchar('\n');
	}
	exit(0);
}
