#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int t;
	int i;
	int len1, len2, len3;
	int *first, *second;
	int a, b, c, d;

	first = second = NULL;
	scanf("%d", &t);
	while(t-- > 0){
		scanf("%d%d", &len1, &len2);
		first = (int *)malloc(len1 * sizeof(int));
		second = (int *)malloc(len2 * sizeof(int));
		for(i = 0; i < len1; i++)
			scanf("%d", first + i);
		for(i = 0; i < len2; i++)
			scanf("%d", second + i);
		scanf("%d%d%d%d", &a, &b, &c, &d);
		len1 = b - a + 1;
		len2 = d - c + 1;
		len3 = len1 + len2;
		len3 = len3 % 2 + len3 / 2;
		if(len3 <= len1)
			printf("%d\n", first[a+len3-2]);
		else
			printf("%d\n", second[c-2+len3-len1]);
		free(first);
		free(second);
		first = second = NULL;
	}
	exit(0);
}
