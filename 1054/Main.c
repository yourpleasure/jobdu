#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char A[201];
	char B[26] = {0};
	int i;

	while(scanf("%s", A) != EOF){
		for(i = 0; A[i] != '\0'; i++)
			B[A[i] - 'a']++;
		for(i = 0; i < 26; i++){
			while(B[i]){
				printf("%c", 'a'+i);
				B[i]--;
			}
		}
		putchar('\n');
	}
	exit(0);
}
