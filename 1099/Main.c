#include <stdio.h>
#include <stdlib.h>
#include <string.h>
static void mysort(char **a, int size);
int main()
{
	char origin[100];
	int len;
	char **a;
	int i;
	while(scanf("%s", origin) != EOF){
		len = strlen(origin);
		a = (char **)malloc(len * sizeof(char *));
		for(i = 0; i < len; i++){
			a[i] = origin+i;
		}
		mysort(a, len);
		for(i = 0; i < len; i++){
			printf("%s\n", a[i]);
		}
		free(a);
		a = NULL;
	}
	exit(0);
}

static void mysort(char **a, int size)
{
	int i, j;
	int tempswappos = size-1;
	int lastswappos;
	char *temp;

	for(i = 0; i < size; i++){
		lastswappos = tempswappos;
		for(j = 0; j < lastswappos; j++){
			if(strcmp(a[j], a[j+1]) > 0){
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
				tempswappos = j;
			}
		}
		if(lastswappos == tempswappos) return;
	}
}
