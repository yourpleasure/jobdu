#include <stdio.h>
#include <stdlib.h>

int main()
{
	int N, X, Y, Z;
	int sum;
	int temp1;
	int temp2;
	int i, j;
	int state;

	while(scanf("%d%d%d%d", &N, &X, &Y, &Z) != EOF){
		state = 0;
		sum = X * 1000 + Y * 100 + Z * 10;
		for(j = 9; j > 0; j--){
			temp1 = sum + j * 10000;
			for(i = 9; i > -1; i--){
				temp2 = temp1 + i;
				if(!(temp2 % N)){
					printf("%d %d %d\n", j, i, temp2 / N);
					state = 1;
					break;
				}
			}
			if(state) break;
		}
		if(!state) printf("0\n");
	}
	exit(0);
}
