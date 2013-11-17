#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct node{
	int num;
	struct node *next;
}node;
int main()
{
	int n;
	int max;
	node *head = NULL;
	node *p;
	node *q;
	int i;
	int j;
	int sum;
	int t;

	max = 6;
	p = (node *)malloc(sizeof(node));
	p->next = NULL;
	p->num = 6;
	head = p;
	while(scanf("%d", &n) != EOF){
		if(n <= max){
			for(q = head; q != NULL; q = p->next){
				if(q->num <= n){
					printf("%d", p->num);
					q = q->next;
					while(q != NULL){
						printf(" %d", q->num);
						q = q->next;
					}
					printf("\n");
					break;
				}
			}
		}
		else{
			for(i = max+1; i <= n; i++){
				sum = 1;
				t = (int)sqrt(i);
				if(i == t * t) sum += t;
				for(j = 2; j < t; j++)
					if(!(i%j)) sum = sum + j + i/j;
				if(sum == i){
					q = (node *)malloc(sizeof(node));
					q->next = NULL;
					p->next = q;
					p = q;
					q->num = i;
				}
			}
			printf("%d", head->num);
			for(q = head->next; q != NULL; q = q->next)
				printf(" %d", q->num);
			printf("\n");
			max = n;
		}
	}
	exit(0);
}
