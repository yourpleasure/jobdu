#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
	double x0, y0, z0, x1, y1, z1;
	double r, V;
	double PI = acos(-1.0);
	
	while(scanf("%lf%lf%lf%lf%lf%lf", &x0, &y0, &z0, &x1, &y1, &z1) != EOF){
		x1 -= x0;
		y1 -= y0;
		z1 -= z0;
		r = x1 * x1 + y1 * y1 + z1 * z1;
		r = sqrt(r);
		V = PI * r * r * r * 4.0 / 3.0;
		printf("%.3lf %.3lf\n", r, V);
	}
	exit(0);
}
