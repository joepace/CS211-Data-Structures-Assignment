#include<stdio.h>
#include<stdlib.h>


typedef struct node{
	int key;
	int height;
	
	struct node * left;
	struct node * right;

}Node;

Node * root = NULL;

void insert(int key);
void insertNode(int key, Node * ptr, int height);
void search(int key, Node * ptr);
void freeNodes(Node * ptr);

void insert(int key){
	if(root == NULL){
		root = (Node *) malloc(sizeof(Node));
		root->key = key;
		root->height = 1;
		root->left = NULL;
		root->right = NULL;
		printf("inserted %d\n", root->height);
	}
	
	else{
		insertNode(key, root, root->height);
	}
}

void insertNode(int key, Node * ptr, int height){
	height++;
	if (ptr == NULL){
		return;
	}
	else if(key > ptr->key){
		if(ptr->right != NULL){
			insertNode(key, ptr->right, height);
		}
		else{
			ptr->right = (Node *) malloc(sizeof(Node));
			ptr->right->key = key;
			ptr->right->height = height;
			printf("inserted %d\n", ptr->right->height);
			ptr->right->left = NULL;
			ptr->right->right = NULL;
			ptr = ptr->right->right;
			
		}
	}
	else if(key < ptr->key){
		if(ptr->left != NULL){
			insertNode(key, ptr->left, height);
		}
		else{
			ptr->left = (Node *) malloc(sizeof(Node));
			ptr->left->key = key;
			ptr->left->height = height;
			printf("inserted %d\n", ptr->left->height);
			ptr->left->left = NULL;
			ptr->left->right = NULL;			
			ptr = ptr->left->left;
			
		}
	}
	else{
		printf("duplicate\n");
	}

}

void search(int key, Node * ptr){
	if(ptr == NULL){
		printf("absent\n");
		return;
	}
	else if(key > ptr->key){
		search(key, ptr->right);
	}
	else if(key < ptr->key){
		search(key, ptr->left);
	}
	else if(key == ptr->key){
		printf("present %d\n", ptr->height);
	}
}

void freeNodes(Node * ptr){
	if(ptr == NULL){
		free(ptr);
		return;
	}
	freeNodes(ptr->left);
	freeNodes(ptr->right);
}

int main(int argc, char** argv){
	if (argc != 2){
		printf("error\n");
	}
	char* filename = argv[1];
	FILE* file;
	char operation;
	int key = 0;
	
	file = fopen(filename, "r");
	
	if (file == NULL){
		printf("error\n");
		exit(0);
	}
	
	while(fscanf(file, "%c %d\n", &operation, &key) != EOF){
		if (operation == 'i'){
			insert(key);
		}
		else if (operation == 's'){
			search(key, root);
		}
		else{
			printf("error\n");
			exit(0);
		}
	}
	
	freeNodes(root);
	free(root);
	fclose(file);
	return 0;
}
