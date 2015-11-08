#include <stdio.h>
#include <stdlib.h>

int main()
{
	int a[10], b[10];
	int sum;
	int i, j;
	int n, m;
	int c;

	c = getchar();
	while(c != EOF){
		i = j = 0;
		while(c != ' '){
			a[i++] = c - '0';
			c = getchar();
		}
		while(((c = getchar()) != '\n') && (c != EOF)){
			b[j++] = c - '0';
		}
		sum = 0;
		for(n = 0; n < i; n++){
			for(m = 0; m < j; m++){
				sum += a[n] * b[m];
			}
		}
		printf("%d\n", sum);
		if(c == EOF) break;
		else c = getchar();
	}
}
