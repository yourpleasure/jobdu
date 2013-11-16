#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int i, j;
	int a, b;
	char A[101];
	char B[101];
	char C[101][101];

	while(scanf("%s%s", A, B) != EOF){
		memset(C, '\0', sizeof(C));
		a = strlen(A);
		b = strlen(B);
		for(i = 0; i < a; i++)
			if(A[i] == B[0]){
				C[0][i++] = 1;
				while(i < a) C[0][i++] = 1;
				break;
			}
		for(j = 1; j < b; j++){
			if(A[0] == B[j]) C[j][0] = 1;
			else C[j][0] = C[j-1][0];
			for(i = 1; i < a; i++){
				if(A[i] == B[j])
					C[j][i] = C[j-1][i-1] + 1;
				else C[j][i] = C[j][i-1] > C[j-1][i] ? C[j][i-1] : C[j-1][i];
			}
		}
		printf("%d\n", C[b-1][a-1]);
	}
	exit(0);
}
