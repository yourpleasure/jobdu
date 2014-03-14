#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

int M, N;
char Mm[1000];
char Nn[1000];
unsigned long long sum[100];
int k;
const unsigned long long max = 1e15;
void Mto10(int M);
int tentoN(int N);
void print(int i);
int main()
{
	while(scanf("%d%d", &M, &N) != EOF){
		scanf("%s", Mm);
		Mto10(M);
		print(tentoN(N));
	}
	exit(0);
}

void Mto10(int M)
{
	int i;
	int j;
	unsigned long long c;

	i = 0;
	k = 0;
	while(Mm[i] != '\0'){
		c = 0;
		for(j = 0; j <= k; j++){
			sum[j] *= M;
			sum[j] += c;
			if(sum[j] > max){
				c = sum[j] / max;
				sum[j] %= max;
			}
			else c = 0;
		}
		if(c != 0){
			k++;
			sum[k] = c;
		}
		for(j = 0; j <= k; j++){
			if(j == 0){
				if(isdigit(Mm[i])) sum[j] += Mm[i] - '0';
				else sum[j] += Mm[i] - 'A' + 10;
			}
			if(sum[j] > max){
				sum[j+1] += sum[j] / max;
				k = (k >= (j+1) ? k : (j+1));
				sum[j] %= max;
			}
			else break;
		}
		i++;
	}
}

int tentoN(int N)
{
	int i;
	int j;

	i = 999;

	Nn[i] = '\0';
	i--;
	while(k != -1){
		for(j = k; j > 0; j--){
			sum[j - 1] += (sum[j] % N) * max;
			sum[j] /= N;
		}
		Nn[i] = sum[0] % N;
		sum[0] /= N;

		if(Nn[i] < 10) Nn[i] += '0';
		else Nn[i] = Nn[i] - 10 + 'a';
		i--;
		if(0 == sum[k]) k--;
	}

	i++;
	return i;
}

void print(int i)
{
	printf("%s\n", Nn+i);
}
