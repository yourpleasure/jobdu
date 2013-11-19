#include<stdio.h>
#include<stdlib.h>

int main()
{
	int h;
	int i;
	int j;
	int t;
	int l;

	while(scanf("%d", &h) != EOF){
		j = h;
		t = h + 2 * (h - 1);
		for(i = 0; i < h; i++){
			j = h + 2 * i;
			printf("%*c", t - j + 1, '*');
			for(l = 0; l < j - 1; l++) putchar('*');
			putchar('\n');
		}
	}
	exit(0);
}
