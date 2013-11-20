#include<stdio.h>
#include<stdlib.h>

int main()
{
	int Y, M, D;
	int sum;

	while(scanf("%d%d%d", &Y, &M, &D) != EOF){
		sum = ((Y % 100) && (!(Y % 4))) || (!(Y % 400));
		switch(M){
			case 1:
				printf("%d\n", D);
				break;
			case 2:
				printf("%d\n", 31 + D);
				break;
			case 3:
				printf("%d\n", 59 + sum + D);
				break;
			case 4:
				printf("%d\n", 90 + sum + D);
				break;
			case 5:
				printf("%d\n", 120 + sum + D);
				break;
			case 6:
				printf("%d\n", 151 + sum + D);
				break;
			case 7:
				printf("%d\n", 181 + sum + D);
				break;
			case 8:
				printf("%d\n", 212 + sum + D);
				break;
			case 9:
				printf("%d\n", 243 + sum + D);
				break;
			case 10:
				printf("%d\n", 273 + sum + D);
				break;
			case 11:
				printf("%d\n", 304 + sum + D);
				break;
			case 12:
				printf("%d\n", 334 + sum + D);
				break;
			default:
				break;
		}
	}
	exit(0);
}
