#include<stdio.h>
#include<stdlib.h>
#include <string.h>
int n;
int *N;
int result;
int s;
int k;
int mycmp(const void *a, const void *b)
{
	const unsigned int *s = a;
	const unsigned int *t = b;
	if(*s > *t) return -1;
	else if(*s == *t) return 0;
	else return 1;
}

void decide(unsigned int a)
{
	if(N[a] == 0){
		N[a] = 1;
		s--;
		if(s == 0){
			k++;
			memset(N, '\0', sizeof(n));
			s = n;
		}
	}
}

int main()
{
	int m;
	int i;
	unsigned char *p;
	unsigned int *proxy;
	unsigned destination[2];
	int (*cmp)(const void *, const void *);
	unsigned int *result;
	int flag;

	while(EOF != scanf("%d", &n)){
		s = n;
		k = 0;
		proxy = (unsigned int *)malloc((n+1) * sizeof(unsigned int));
		N = (int *)malloc(n * sizeof(int));

		memset(N, '\0', n * sizeof(int));
		for(i = 0; i < n; i++){
			p = (unsigned char *)&proxy[i];
			scanf("%u.%u.%u.%u",p, p+1, p+2, p+3);
		}

		cmp = mycmp;
		qsort(proxy, n, sizeof(unsigned int), cmp);

		scanf("%d", &m);

		flag = 0;
		for(i = 0; i < m; i++){
			p = (unsigned char *)&destination[0];
			scanf("%u.%u.%u.%u", p, p+1, p+2, p+3);
			if(flag) continue;
			result = bsearch((const void *)&destination[0], (const void *)proxy, n, sizeof(unsigned int), cmp);
			if(NULL != result){
				if(n != 1) decide((unsigned int) (result - proxy));
				else flag = 1;

			}
		}
		if(flag)
			printf("-1\n");
		else
			printf("%d\n", k);
		k = 0;


		free(proxy);
		proxy = NULL;
	}

	exit(0);
}
