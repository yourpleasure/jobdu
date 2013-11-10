#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char *sum(int i, int j);
char *sub(char *A, char *B, int i, int j);
char *mul(int i, int j);
int compare(int i, int j);
void init(int i);
void mysum(char *MUL, int k, int j, int i);
char A[402];
char B[402];
char C[402];
char SUM[403];
char SUB[403];
char MUL[803];
char tempmul[9][403];
int state;
int main()
{
	char c;
	char Aflag, Bflag;
	int i, j;
	char comp;

	while(scanf("%s%s", A, B) != EOF){
		memset(SUM, '\0', sizeof(SUM));
		memset(SUB, '\0', sizeof(SUB));
		memset(MUL, '\0', sizeof(MUL));
		memset(tempmul, '\0', sizeof(tempmul));
		state = 0;
		i = 0;
		c = A[0];
		Aflag = 1;
		if(c == '-') Aflag = -1;
		else if(c == '+') Aflag = 1;
		if(!isdigit(c)){
			while(A[i+1] != '\0'){
				A[i] = A[i+1] - '0';
				i++;
			}
			A[i] = '\0';
		}
		else{
			while(A[i] != '\0'){
				A[i] -= '0';
				i++;
			}
		}

		j = 0;
		c = B[0];
		Bflag = 1;
		if(c == '-') Bflag = -1;
		else if(c == '+') Bflag = 1;
		if(!isdigit(c)){
			while(B[j+1] != '\0'){
				B[j] = B[j+1] - '0';
				j++;
			}
			B[j] = '\0';
		}
		else{
			while(B[j] != '\0'){
				B[j] -= '0';
				j++;
			}
		}

		comp = compare(i, j);
		if(Aflag > 0){
			if(Bflag > 0){
				printf("%s\n", sum(i, j));
				if(comp >= 0) printf("%s\n", sub(A, B, i, j));
				else printf("-%s\n", sub(B, A, j, i));
				printf("%s\n", mul(i, j));
			}
			else if(Bflag < 0){
				if(comp >= 0) printf("%s\n", sub(A, B, i, j));
				else printf("-%s\n", sub(B, A, j, i));
				printf("%s\n", sum(i, j));
				mul(i, j);
				if(!state)
					printf("-%s\n", MUL);
				else printf("0\n");
			}
		}
		else{
			if(Bflag > 0){
				if(comp > 0) printf("-%s\n", sub(A, B, i, j));
				else printf("%s\n", sub(B, A, j, i));
				printf("-%s\n", sum(i, j));
				mul(i, j);
				if(!state)
					printf("-%s\n", MUL);
				else printf("0\n");
			}
			else{
				printf("-%s\n", sum(i, j));
				if(comp > 0) printf("-%s\n", sub(A, B, i, j));
				else printf("%s\n", sub(B, A, j, i));
				printf("%s\n", mul(i, j));
			}
		}
	}
	exit(0);
}

char *sum(int i, int j)
{
	int k;
	char c;
	char temp;
	int m;

	k = 401;
	c = 0;
	SUM[k--] = '\0';
	if(i != j){
		i--;
		j--;
		while(i > -1 && j > -1){
			temp = A[i] + B[j] + c;
			SUM[k--] = temp % 10;
			c = temp / 10;
			i--;
			j--;
		}
		if(i == -1 && j != -1){
			while(j > -1){
				temp = B[j] + c;
				SUM[k--] = temp % 10;
				c = temp / 10;
				j--;
			}
		}
		else if(i != -1 && j == -1){
			while(i > -1){
				temp = A[i] +c;
				SUM[k--] = temp % 10;
				c = temp / 10;
				i--;
			}
		}
	}
	else{
		while(i-- > 0){
			temp = A[i] + B[i] + c;
			SUM[k--] = temp %10;
			c = temp / 10;
		}
	}
	if(c)
		SUM[k] = c;
	else k++;

	for(m = k; m < 401; m++) SUM[m] += '0';
	return SUM + k;
}

char *sub(char *A,  char *B, int i, int j)
{
	int k;
	char c;
	char temp;
	int m;

	k = 401;
	SUB[k--] = '\0';
	c = 0;
	i--;
	while(j-- > 0){
		temp = A[i] + c - B[j];
		if(temp >= 0){
			c = 0;
			SUB[k--] = temp;
		}
		else{
			c = -1;
			SUB[k--] = temp + 10;
		}
		i--;
	}
	while(i >= 0){
		temp = A[i] + c;
		if(temp >= 0){
			c = 0;
			SUB[k--] = temp;
			i--;
			while(i >= 0){
				SUB[k--] = A[i];
				i--;
			}
			break;
		}
		else{
			c = -1;
			SUB[k--] = temp + 10;
		}
		i--;
	}

	k = 0;
	while(!SUB[k] && k < 402) k++;
	if(k == 402){
		SUB[401] = '0';
		return SUB+401;
	}
	for(m = k; m < 401; m++) SUB[m] += '0';
	return SUB + k;
}

int compare(int i, int j)
{
	int k;

	if(i > j) return 1;
	else if(i < j) return -1;
	else{
		k = 0;
		while(k < i){
			if(A[k] != B[k]) return A[k] - B[k];
			k++;
		}
	}
	return 0;
}

char *mul(int i, int j)
{
	int k;
	int m;
	char temp;

	init(i);
	k = 0;
	while(k < j){
		mysum(MUL, k, j, i);
		k++;
	}

	for(k = 802; k > -1; k--) if(MUL[k]) break;
	if(k == -1){
		state = 1;
		MUL[0] = '0';
		MUL[1] = '\0';
		return MUL;
	}
	m = k;
	while(m >= 0) MUL[m--] += '0';
	for(m = 0; m < k; m++){
		temp = MUL[m];
		MUL[m] = MUL[k];
		MUL[k] = temp;
		k--;
	}
	return MUL;
}

void init(int i)
{
	int j;
	int k;
	char c;
	char temp;

	for(j = 0; j < i; j++) tempmul[0][j] = A[i-j-1];
	for(k = 2; k < 10; k++){
		c = 0;
		for(j = 0; j < i; j++){
			temp = tempmul[0][j] * k + c;
			tempmul[k-1][j] = temp % 10;
			c = temp / 10;
		}
		tempmul[k-1][j] = c;
	}
}

void mysum(char *MUL, int k, int j, int i)
{
	int l;
	char temp;
	char c;
	char tempmulti;

	c = 0;
	if(B[j-k-1] == 0) return;
	tempmulti = B[j-k-1] - 1;
	for(l = 0; l <= i; l++){
		temp = tempmul[tempmulti][l] + MUL[k] + c;
		MUL[k++] = temp % 10;
		c = temp / 10;
	}
}
