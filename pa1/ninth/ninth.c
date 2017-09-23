#include<stdio.h>
#include<stdlib.h>


typedef struct node{
	int key;
	
	struct node * left;
	struct node * right;

}Node;

Node * root = NULL;

void insert(int key);
void insertNode(int key, Node * ptr, int height);
void search(int key, Node * ptr, int height);
void deleteNode(int key, Node * ptr, Node * parent);
void freeNodes(Node * ptr);

void insert(int key){
	int height = 1;
	if(root == NULL){
		root = (Node *) malloc(sizeof(Node));
		root->key = key;
		root->left = NULL;
		root->right = NULL;
		printf("inserted %d\n", height);
	}
	
	else{
		insertNode(key, root, height);
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
			
			printf("inserted %d\n", height);
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
			printf("inserted %d\n", height);
			ptr->left->left = NULL;
			ptr->left->right = NULL;			
			ptr = ptr->left->left;
			
		}
	}
	else{
		printf("duplicate\n");
	}

}

void search(int key, Node * ptr, int height){
	if(ptr == NULL){
		printf("absent\n");
		return;
	}
	else if(key > ptr->key){
		height++;
		search(key, ptr->right, height);
	}
	else if(key < ptr->key){
		height++;
		search(key, ptr->left, height);
	}
	else if(key == ptr->key){
		printf("present %d\n", height);
	}
}

void deleteNode(int key, Node * ptr, Node * parent){
	//not found
	if(ptr == NULL){
		printf("fail\n");
		
		return;
	}
	
	//found
	else if(key == ptr->key){
		//no children
		if(ptr->left == NULL && ptr->right == NULL){
			//check root
			if(parent == NULL){
				root = NULL;
			}
			else if(parent->left == ptr){
				parent->left = NULL;
			}
			else{
				parent->right = NULL;
			}
		}
		//two children - traverse down left side of right tree, replace ptr with that element
		else if(ptr->left != NULL && ptr->right != NULL){
			Node * target = (Node *) malloc(sizeof(Node));
			Node * parentTarget = (Node *) malloc(sizeof(Node));
			
			target = ptr->right;
			
			
			//all the way to smallest on right side 
			while(target->left != NULL){
				parentTarget = target;
				target = target->left;
			}
			//check root
			if(parent == NULL){
				root->key = target->key;
				
				parentTarget->left = target->right;
			}
			
			else{
				ptr->key = target->key;
				
				parentTarget->left = target->right;
			}
			
		}
		//one child - left
		else if(ptr->left != NULL){
			//check root
			if(parent == NULL){
				root = root->left;
			}
			else if(parent->left == ptr){
				parent->left = ptr->left;
			}
			else{
				parent->right = ptr->left;
			}
		
		}
		//one child - right 
		else{
			//check root
			if(parent == NULL){
				root = root->right;
			}
			else if(parent->left == ptr){
				parent->left = ptr->right;
			}
			else{
				parent->right = ptr->right;
			}
		}
		
		
		printf("success\n");
		return;
	}
	//traverse right
	else if(key > ptr->key){
		deleteNode(key, ptr->right, ptr);
	}
	//traverse left
	else if(key < ptr->key){
		deleteNode(key, ptr->left, ptr);
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
	Node * parent = (Node*) malloc(sizeof(Node));
	parent = NULL;
	int height = 1;
	
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
			search(key, root, height);
		}
		else if (operation == 'd'){
			deleteNode(key, root, parent);
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
