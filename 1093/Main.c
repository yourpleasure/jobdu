#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char s1[] = "WERTYUIOP[]\\SDFGHJKL;'XCVBNM,./1234567890-= \n";
char s2[] = "QWERTYUIOP[]ASDFGHJKL;ZXCVBNM,.`1234567890- \n";
int main()
{
	int c;
	char *p;
	while((c = getchar()) != EOF){
		p = strchr(s1, c);
		if(p != NULL)
			putchar(s2[p-s1]);
	}
	exit(0);
}
