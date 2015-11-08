#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main()
{
	int c;
	int cal[26];
	int i;
	c = getchar();
	while(c != EOF){
		memset(cal, '\0', sizeof(cal));
		while((c != '\n') && (c != EOF)){
			if(isupper(c)) cal[c-'A']++;
			c = getchar();
		}
		for(i = 0; i < 26; i++){
			printf("%c:%d\n", i+'A', cal[i]);
		}
		if(c == '\n') c = getchar();
	}
	exit(0);
}
