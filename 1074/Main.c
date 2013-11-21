#include<stdio.h>
#include<stdlib.h>

int main()
{
	int i;
	long j;
	int temp;

	for(i = 0; i < 256; i++){
		j = i * i;
		if(j >= 10000){
			if(j / 10000 == j % 10){
				temp = j - (j / 10000) * 10000;
				temp /= 10;
				if(temp / 100 == temp % 10)
					printf("%d\n", i);
			}
		}
		else if(j >= 1000){
			if(j / 1000 == j % 10){
				temp = j - (j / 1000) * 1000;
				temp /= 10;
				if(temp / 10 == temp % 10)
					printf("%d\n", i);
			}
		}
		else if(j >= 100){
			if(j / 100 == j % 10)
				printf("%d\n", i);
		}
		else if(j >= 10){
			if(j / 10 == j % 10)
				printf("%d\n", i);
		}
		else printf("%d\n", i);
	}
	exit(0);
}
