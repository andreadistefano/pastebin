#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

int main () {
	unsigned long long int total;							
	total = 0;                                              
	int counter = 1;										
	int sum;												
	int i = 0;												
	char names[50000];										
	char *temp;												
	char delims[] = " \",\" ";								
	struct node {                                           
		char name[30];                                      
		struct node *next;									
	};                                                      
	FILE *file;                                             
	file = fopen("names.txt", "r");							
	fgets(names, 50000, file);								
	temp = strtok(names, delims);							
	struct node *first = malloc(sizeof(struct node));		
	struct node *current = malloc(sizeof(struct node));
	struct node *newnode = malloc(sizeof(struct node));	
	struct node *save = malloc(sizeof(struct node));		
	strcpy(first->name, temp);								
	first->next = NULL;										
	//printf("%s\n", first->name);							
	int written;
	while ((temp = strtok(NULL, delims) )!= NULL) {
		written = 0;
        current = first;
		//printf("%s\n", temp);
        while (current->next != NULL && !written) {
			if (strcmp(current->name, temp) >= 0) {
				current = current->next;
			}
			else {
				save =  current->next;
				struct node *newname = malloc (sizeof(struct node));
				strcpy(newnode->name, temp);
				current->next = newname;
				newname->next = save;
				written = 1;
			}
		}
		if (!written) {
			struct node *newname = malloc (sizeof(struct node));
			strcpy(newnode->name, temp);
			current->next = newname;
		}
		//printf("%s\n", current->name);
	}
	current = first;
	while (current->next != NULL) {
		printf("%s\n", current->name);
		current = current->next;
	}
	fclose(file);										
	printf("%llu", total);									
	return 0;
}