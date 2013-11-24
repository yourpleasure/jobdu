#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char A[27];
char B[27];
char C[27];
void trans(char *s1, char *s2, int first, int len);
int main()
{
	while(scanf("%s%s", A, B) != EOF){
		trans(A, B, 0, strlen(B));
		C[strlen(B)] = '\0';
		printf("%s\n", C);
	}
	exit(0);
}
void trans(char *s1, char *s2, int first, int len)
{
	int i;
	if(len == 0) return;
	C[first+len-1] = s1[0];
	if(len == 1) return;
	for(i = 0; i < len; i++){
		if(s2[i] == s1[0]) break;
	}
	trans(s1+1, s2, first, i);
	trans(s1+i+1, s2+i+1, first+i, len-i-1);
}
