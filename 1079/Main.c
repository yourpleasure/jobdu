#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char map[26];
char map2[26];
void init();
int main()
{
	char test[101];
	int i;
	int sum;
	int len;
	
	init();
	while(scanf("%s", test) != EOF){
		len = strlen(test);
		for(i = 0; i < len; i++)
			test[i] -= 'a';
		sum = map2[(int)test[0]];
		for(i = 1; i < len; i++){
			if(map[(int)test[i]] == map[(int)test[i-1]])
				sum += 2 + map2[(int)test[i]];
			else
				sum += map2[(int)test[i]];
		}
		printf("%d\n", sum);
	}
	exit(0);
}

void init()
{
	map[0] = map[1] = map[2] = 1;
	map[3] = map[4] = map[5] = 2;
	map[6] = map[7] = map[8] = 3;
	map[9] = map[10] = map[11] = 4;
	map[12] = map[13] = map[14] = 5;
	map[15] = map[16] = map[17] = map[18] = 6;
	map[19] = map[20] = map[21] = 7;
	map[22] = map[23] = map[24] = map[25] = 8;
	map2[0] = map2[3] = map2[6] = map2[9] = map2[12] = map2[15] = map2[19] = map2[22] = 1;
	map2[1] = map2[4] = map2[7] = map2[10] = map2[13] = map2[16] = map2[20] = map2[23] = 2;
	map2[2] = map2[5] = map2[8] = map2[11] = map2[14] = map2[17] = map2[21] = map2[24] = 3;
	map2[18] = map2[25] = 4;
}
