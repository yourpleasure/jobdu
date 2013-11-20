#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct student_{
	char ID[101];
	char name[101];
	char sex[5];
	int age;
}student;
	
int main()
{
	int N, M;
	int i;
	int j;
	char tempID[101];
	student *studentlist = NULL;

	while(scanf("%d", &N) != EOF){
		studentlist = (student *)malloc(N * sizeof(student));
		for(i = 0; i < N; i++)
			scanf("%s%s%s%d", studentlist[i].ID, studentlist[i].name, studentlist[i].sex, &(studentlist[i].age));
		scanf("%d", &M);
		for(i = 0; i < M; i++){
			scanf("%s", tempID);
			for(j = 0; j < N; j++){
				if(!strcmp(tempID, studentlist[j].ID)){
					printf("%s %s %s %d\n", tempID, studentlist[j].name, studentlist[j].sex, studentlist[j].age);
					break;
				}
			}
			if(j == N) printf("No Answer!\n");
		}
		free(studentlist);
		studentlist = NULL;
	}
	exit(0);
}
