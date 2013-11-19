#include<stdio.h>
#include<stdlib.h>

int main()
{
	int b, c;
	int num;
	int renum;

	for(b = 0; b < 10; b++)
		for(c = 0; c < 10; c++){
			num = 1009 + 100 * b + 10 * c;
			renum = 9001 + 100 * c + 10 * b;
			if(num * 9 == renum) printf("1%d%d9\n", b, c);
		}
	exit(0);
}
