#include<stdio.h>
#include<stdlib.h>

int main()
{
	char maxi;
	int temp;
	char B[11];
	int i;

	while(scanf("%d", &temp) != EOF){
		for(i = 0; i < 11; i++) B[i] = 0;
		B[temp]++;
		for(i = 1; i < 20; i++){
			scanf("%d", &temp);
			B[temp]++;
		}
		temp = B[1];
		maxi = 1;
		for(i = 2; i < 11; i++)
			if(B[i] > temp){
				maxi = i;
				temp = B[i];
			}
		printf("%d\n", maxi);
	}
	exit(0);
}
