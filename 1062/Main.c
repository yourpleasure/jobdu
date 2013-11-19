#include<stdio.h>
#include<stdlib.h>

int main()
{
	double y, x;

	while(scanf("%lf", &x) != EOF){
		if(x >= 0.0 && x < 2.0)
			y = (-1) * x + 2.5;
		else if(x >= 2.0 && x < 4.0)
			y = 2 - 1.5 * (x - 3.0) * (x - 3.0);
		else if(x >= 4.0 && x < 6.0)
			y = x / 2.0 - 1.5;
		printf("%.3lf\n", y);
	}
	exit(0);
}
