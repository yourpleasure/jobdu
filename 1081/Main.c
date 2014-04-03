#include<stdio.h>
#include<stdlib.h>
#include<string.h>
const int mod = 10000;
int T[2][2];
void mul(int A[2][2], int B[2][2]){
	int S[2][2];

	S[0][0] = A[0][0] * B[0][0] + A[0][1] * B[1][0];
	S[0][1] = A[0][0] * B[0][1] + A[0][1] * B[1][1];
	S[1][0] = A[1][0] * B[0][0] + A[1][1] * B[1][0];
	S[1][1] = A[1][0] * B[0][1] + A[1][1] * B[1][1];

	A[0][0] = S[0][0] % mod;
	A[0][1] = S[0][1] % mod;
	A[1][0] = S[1][0] % mod;
	A[1][1] = S[1][1] % mod;
}

void bi(int A[2][2], long long n)
{
	if(n == 1) return;
	if(n % 2){
		bi(A, n-1);
		mul(A, T);
	}
	else{
		bi(A, n/2);
		mul(A, A);
	}
}

int main()
{
	long long p, q;
	long long k;
	long long a0, a1;

	int p0, q0;
	int A[2][2];
	int a00, a11;

	while(scanf("%Ld%Ld%Ld%Ld%Ld", &a0, &a1, &p, &q, &k) != EOF){
		a00 = (int)(a0 % mod);
		a11 = (int)(a1 % mod);
		p0 = (int)(p % mod);
		q0 = (int)(q % mod);
		if(k == 0) printf("%d\n", a00);
		else if(k == 1) printf("%d\n", a11);
		else{
			A[0][0] = T[0][0] = p0;
			A[0][1] = T[0][1] = q0;
			A[1][0] = T[1][0] = 1;
			A[1][1] = T[1][1] = 0;
			bi(A, k-1);
			A[0][0] = A[0][0] * a11 + A[0][1] * a00;
			A[0][0] %= mod;
			printf("%d\n", A[0][0]);
		}
	}
	exit(0);
}
