#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char A[105];
	int a;
	int n;
	int c;
	int i;
	int temp;
	int j;

	while(scanf("%d%d", &a, &n) != EOF){
		memset(A, '\0', sizeof(A));
		c = 0;
		A[104] = '\0';
		A[103] = '\n';
		j = 102;
		for(i = 0; i < n; i++){
			temp = (n - i) * a + c;
			A[j--] = temp % 10;
			c = temp / 10;
		}
		while(c){
			A[j--] = c % 10;
			c /= 10;
		}

		i = 0;
		while(A[i] == '\0') i++;
		for(j = i; j < 103; j++) A[j] += '0';
		printf("%s", &A[i]);
	}
	exit(0);
}
