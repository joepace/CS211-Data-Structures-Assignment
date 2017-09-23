#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
	int num;
	
	struct node* next;
};

struct node* first = NULL;

void insert(int target);
void delete(int target);

void insert(int target){

	//printf("time to insert!\n");
	
	if(first == NULL){
		first = (struct node *) malloc(sizeof(struct node));
		first-> num = target;
		first-> next = NULL;
		//printf("%d insert success!\n", first->num);
		return;
	}

	struct node * prev = NULL;

	struct node * ptr = first;

	struct node * newNode = NULL;
	
	
	
	
	while(ptr != NULL){
		
		if(ptr-> num == target){
			return;
		}
		
		else if(ptr->num > target){
		
			newNode = (struct node*) malloc(sizeof(struct node));
			newNode-> num = target;
			newNode-> next = ptr;
			
			if(ptr == first){
				first = newNode;
				//printf("%d insert success!\n", first->num);
				return;
			}
			prev-> next = newNode;
			//printf("%d insert success!\n", newNode->num);
			return;
		}
	
		prev = ptr;
		
		ptr = ptr->next;
	
	}
	
	newNode = (struct node*) malloc(sizeof(struct node));
	newNode-> num = target;
	newNode-> next = NULL;
	prev->next = newNode;

}

void delete(int target){
	
	//printf("oh no time to delete!\n");
	struct node * prev = NULL;
	struct node * ptr = first;
	struct node * temp = NULL;
	
	while(ptr != NULL){
		if (ptr->num == target){
			if(ptr == first){
				temp = first->next;
				first = temp;
				//printf("delete first success!\n");
				return;
			}
			
			temp = ptr->next;
			prev->next = ptr->next;
			ptr = temp;
			//printf("delete success!\n");
			return;
		} 
		
		prev = ptr;
		ptr = ptr->next;
	}
}

int main(int argc, char** argv){
	if (argc != 2){
		printf("error\n");
	}
	char* filename = argv[1];
	FILE* file;
	int target;
	char operation;
	struct node * ptr = first;
	
	file = fopen(filename, "r");
	
	if (file == NULL){
		printf("error\n");
		exit(0);
	}
	
	while(fscanf(file, "%c %d\n", &operation, &target) != EOF){
		//printf("\ncheck loop running\n");
		ptr = first;
		//printf("current list: ");
		//while(ptr != NULL){
			//printf("%d\t", ptr->num);
		//	ptr = ptr->next;
		//}
		//printf("\n");
		//printf("%c %d\n", operation, target);
		if (operation == 'i'){
			insert(target);
		}
		else if (operation == 'd'){
			delete(target);
		}
		else{
			printf("error\n");
			exit(0);
		}
	}
	
	ptr = first;
	if(ptr == NULL)
	{
		printf("\n");
	}
	else{
		while(ptr){
			printf("%d\t", ptr->num);
			ptr = ptr->next;
		}
		printf("\n");
	}
	
	
	fclose(file);
	return 0;
}
