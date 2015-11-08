#include <stdio.h>
#include <stdlib.h>

unsigned long long root(unsigned long long x, unsigned long long y, unsigned long long k)
{
	unsigned long long result = 1;

	while(y){
		if(y & 1) result = (result *x) % k;
		x = (x * x) % k;
		y >>= 1;
	}
	return result ? result : k;
}

int main()
{
	unsigned long long x, y, k;
	while(scanf("%llu%llu%llu", &x, &y, &k) != EOF){
		printf("%llu\n", root(x, y, k - 1));
	}
	exit(0);
}
