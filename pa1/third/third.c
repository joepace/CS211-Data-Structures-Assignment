#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int key;
	int value;
	
	struct node* next;
} Node;

Node * hashtable[10000];

void insert(int target, int key);
void search(int target, Node * ptr);
int hash(int target);

void insert(int target, int key){
	Node * newNode = (Node*) malloc(sizeof(Node));
	newNode->key = key;
	newNode->value = target;
	Node * ptr = (Node*) malloc(sizeof(Node));
	ptr = hashtable[key];
	
	if(ptr == NULL){
		hashtable[key] = newNode;
		hashtable[key]->next = NULL;
		printf("inserted\n");
		return;
	}
	
	Node * prev = NULL;
	
	while(ptr != NULL){
		
		if(ptr-> value == target){
			printf("duplicate\n");
			return;
		}
		
		else if(ptr->value > target){
			//printf("inserted\n");
			newNode = (Node*) malloc(sizeof(Node));
			newNode-> value = target;
			newNode-> key = key;
			newNode-> next = ptr;
			
			if(ptr->value == hashtable[key]->value){
				hashtable[key] = newNode;
				printf("inserted\n");
				return;
			}
			prev-> next = newNode;
			printf("inserted\n");
			return;
		}
	
		prev = ptr;
		
		ptr = ptr->next;
	
	}
	
	newNode = (Node*) malloc(sizeof(Node));
	newNode-> value = target;
	newNode-> next = NULL;
	prev->next = newNode;
	printf("inserted\n");

}

void search(int target, Node * ptr){
	
	while(ptr != NULL){
		if (target == ptr->value){
			printf("present\n");
			return;
		}
		else if (target > ptr->value){
			ptr = ptr->next;
		}
		else{
			break;
		}
	}

	printf("absent\n");
}

int hash(int target){
	if(target < 0){
		target = target * (-1);
	}
	return (target % 10000);
}

int main(int argc, char** argv){
	if (argc != 2){
		printf("error\n");
	}
	char* filename = argv[1];
	FILE* file;
	int target;
	char operation;
	int key = 0;
	
	file = fopen(filename, "r");
	
	while(fscanf(file, "%c %d\n", &operation, &target) != EOF){
		if (operation == 'i'){
			key = hash(target);
			insert(target, key);
		}
		else if (operation == 's'){
			key = hash(target);
			Node * ptr = hashtable[key];
			search(target, ptr);
		}
		else{
			printf("error\n");
		}
	}
	fclose(file);
	return 0;
}
