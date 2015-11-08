#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int L, M;
	char *A;
	int i;
	int a, b;

	while(scanf ("%d%d", &L, &M) != EOF){
		A = (char *)malloc ((L+1) * sizeof(char));
		memset (A, 1, (L+1));
		for(i = 0; i < M; i++){
			scanf ("%d%d", &a, &b);
			if(a > b){
				a ^= b;
				b ^= a;
				a ^= b;
			}
			if((a >= 0) && (b <= L))
				memset (A + a, 0, b - a + 1);
			else if(b <= L)
				memset (A, 0, b + 1);
			else if(a >= 0)
				memset (A, 0, L - a + 1);
		}
		a = 0;
		for(i = 0; i <= L; i++)
			if(A[i]) a++;
		printf("%d\n", a);
		free(A);
		A = NULL;
	}
	exit(0);
}
