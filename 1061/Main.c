#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct student{
	char name[101];
	int age;
	int score;
	struct student *next;
}student;
int compare(student *a, student *b);
int main()
{
	int N;
	int i;
	student *studentlist = NULL;
	student *p = NULL;
	student *q = NULL;
	student *r = NULL;

	studentlist = (student *)malloc(sizeof(student));
	studentlist->next = NULL;
	while(scanf("%d", &N) != EOF){
		for(i = 0; i < N; i++){
			p = (student *)malloc(sizeof(student));
			scanf("%s%d%d", p->name, &(p->age), &(p->score));
			for(r = studentlist; r != NULL; r = r->next){
				q = r->next;
				if(q == NULL){
					r->next = p;
					p->next = NULL;
					break;
				}
				else if(compare(p, q) > 0){
					p->next = q;
					r->next = p;
					break;
				}
			}
		}
		r = studentlist->next;
		while(r != NULL){
			printf("%s %d %d\n", r->name, r->age, r->score);
			q = r;
			r = r->next;
			free(q);
			q = r;
		}
		studentlist->next = NULL;
	}
	free(studentlist);
	studentlist = NULL;

	exit(0);
}

int compare(student *a, student *b)
{
	int c;

	if(a->score != b->score) return b->score - a->score;
	else {
		c = strcmp(b->name, a->name);
		if(c != 0) return c;
		else return b->age - a->age;
	}
}
