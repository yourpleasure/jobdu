#include <stdio.h>
#include <stdlib.h>
#include <string.h>
static void print(const char *current, int j);
int main(void)
{
	int n;
	int i, j, k, l;
	char **route = NULL;
	char tempRoute[50];
	int len;
	int result;

	scanf("%d", &n);
	while(n){
		k = 0;
		route = (char **)malloc(n * sizeof(char *));
		for(i = 0; i < n; i++){
			scanf("%s", tempRoute);
			len = strlen(tempRoute);
			if(tempRoute[len-1] == '\\')
				tempRoute[len-1] = '\0';
			for(j = 0; j < i; j++){
				result = strcmp(tempRoute, route[j]);
				if(result == 0)
					break;
				else if(result < 0){
					l = k;
					while (l > j) {
						route[l] = route[l-1];
						l--;
					}
					route[l] = (char *)malloc((len+1)*sizeof(char));
					strcpy(route[l], tempRoute);
					k++;
					break;
				}
			}
			if(j == i){
				route[j] = (char *)malloc((len+1) * sizeof(char));
				strcpy(route[j], tempRoute);
				k++;
			}
		}
		print(route[0], 0);
		for(i = 1; i < k; i++){
			j = 0;
			while(route[i][j] == route[i-1][j]) j++;
			while((j >= 0) && (route[i][j] != '\\')) j--;
			if(j == 0) print(route[i], 0);
			else print(route[i], j+1);
		}
		for(i = 0; i < k; i++){
			free(route[i]);
			route[i] = NULL;
		}
		free(route);
		route = NULL;
		putchar('\n');
		scanf("%d", &n);
	}
	exit(0);
}

static void print(const char *current, int j){
	const char *p = current + j;
	int i;
	for(i = 0; i < p-current; i++) putchar(' ');
	while(*p != '\0'){
		if(*p == '\\'){
			putchar('\n');
			p++;
			for(i = 0; i < p-current; i++) putchar(' ');
		}
		else{
			putchar(*p);
			p++;
		}
	}
	putchar('\n');
}
