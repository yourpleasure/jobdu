#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int N;
unsigned long long L1, L2, L3, C1, C2, C3;
unsigned long long *length = NULL;
unsigned long long *w = NULL;

int main()
{
	int A, B;
	int count;
	int i;
	int j;
	unsigned long long length1, length2;
	unsigned long long min, temp;

	while(scanf ("%llu%llu%llu%llu%llu%llu%d%d%d", &L1, &L2, &L3, &C1, &C2, &C3, &A, &B, &N) != EOF){
		if(A > B){
			A ^= B;
			B ^= A;
			A ^= B;
		}
		j = 1;
		count = B - A;
		length = (unsigned long long*)malloc ((count + 1) * sizeof(unsigned long long));
		w = (unsigned long long *)malloc((count + 1) * sizeof(unsigned long long));
		memset(w, '\0', (count + 1) * sizeof(unsigned long long));
		for(i = 0; i < A - 2; i++) scanf ("%llu", &temp);
		if(A == 1) length[0] = 0;
		else scanf ("%llu", length);
		for(i = A - 1; i < B - 1; i++, j++){
			scanf ("%llu", length+j);
			length[j - 1] = length[j] - length[j-1];
		}
		for(i = B - 1; i < N - 1; i++) scanf ("%llu", &temp);

		w[0] = 0;
		for(i = 1; i <= count; i++){
			min = w[i-1] + C3;
			length1 = 0;
			temp = 0;
			for(j = i-1; j >= 0; j--){
				length1 += length[j];
				if(length1 <= L1){
					temp = w[j] + C1;
				}
				else if(length1 <= L2){
					temp = w[j] + C2;
				}
				else if(length1 <= L3){
					temp = w[j] + C3;
				}
				else
					break;
				if(temp < min) min = temp;
			}
			w[i] = min;
		}
		printf("%llu\n", w[count]);
		free(length);
		free(w);
		length = w = NULL;
	}
	exit(0);
}
