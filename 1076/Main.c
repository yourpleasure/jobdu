#include<stdio.h>
#include<stdlib.h>
#include<string.h>
unsigned long long ownmai = 1e16;
unsigned long long A[20];
unsigned long long B[982][162];
int C[1001];
void init();
void print(int n);
int main()
{
	int n;

	init();
	while(scanf("%d", &n) != EOF){
		print(n);
	}
	exit(0);
}

void init()
{
	int j;
	int k;
	int c;
	int l;
	unsigned long long i;

	A[0] = 1;
	for(j = 2; j < 21;j++){
		A[j-1] = A[j-2] * j;
	}
	memset(B, '\0', sizeof(B));
	B[0][0] = A[19] % ownmai;
	B[0][1] = A[19] / ownmai;
	C[20] = 1;
	for(j = 21; j < 1001; j++){
		c = 0;
		l = j - 20;
		for(k = 0; k <= C[j-1]; k++){
			i = B[l-1][k] * j + c;
			B[l][k] = i % ownmai;
			c = i / ownmai;
		}
		if(c){
			B[l][k] = c;
			C[j] = k;
		}
		else C[j] = k-1;
	}
}

void print(int n)
{
	int i;
	int j;
	if(n == 0) printf("1\n");
	else if(n < 20)
		printf("%Lu\n", A[n-1]);
	else{
		j = n - 20;
		i = C[n];
		printf("%Lu", B[j][i]);
		for(i = C[n] - 1; i > -1; i--){
			printf("%016Lu", B[n-20][i]);
		}
		putchar('\n');
	}
}
