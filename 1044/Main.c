#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned long find(int m, char *s1, char *s2, int len);
unsigned long combination(int m, int n);
int main()
{
	int m;
	char s1[27];
	char s2[27];

	while(scanf("%d", &m) != EOF){
		if(!m) break;
		scanf("%s%s", s1, s2);
		printf("%lu\n", find(m, s1, s2, strlen(s1)));
	}
	exit(0);
}

unsigned long find(int m, char *s1, char *s2, int len)
{
	int numSubtree;
	int templen;
	char *temp1;
	char *temp2;
	char *temp3;
	unsigned long sum;

	if(len == 1) return 1;
	sum = 1;
	numSubtree = 0;
	temp1 = s1 + 1;
	temp2 = s2;
	while(temp1 - s1 < len){
		temp3 = strchr(s2, *temp1);
		templen = temp3 - temp2 + 1;
		sum *= find(m, temp1, temp2, templen);
		temp1 += templen;
		temp2 += templen;
		numSubtree++;
	}
	if(numSubtree == 0) return 1;
	sum *= combination(m, numSubtree);
	
	return sum;
}

unsigned long combination(int m, int n)
{
	int i;
	unsigned long temp;

	temp = 1;
	for(i = 1; i <= n; i++){
		temp *= m;
		m--;
	}
	for(i = 1; i <= n; i++) temp /= i;
	return temp;
}
