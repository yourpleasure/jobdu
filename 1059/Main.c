#include<stdio.h>
#include<stdlib.h>

int main()
{
	int a, b, c;
	int A;
	int B;

	for(a = 1; a < 10; a++){
		for(b = 1; b < 10; b++){
			for(c = 0; c < 10; c++){
				A = 100 * a + 10 * b + c;
				B = 100 * b + 10 * c + c;
				if(A + B == 532)
					printf("%d %d %d\n", a, b, c);
			}
		}
	}
	exit(0);
}
