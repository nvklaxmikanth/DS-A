#include<stdio.h>
#include<malloc.h>
struct tnode{
	int data;
	struct tnode* left;
	struct tnode* right;
};
struct snode{
    struct tnode* tree;
    struct snode* next;
};
struct tnode* newnode(int data){
	struct tnode* tnode = (struct tnode*)malloc(sizeof(struct tnode));
	tnode->data = data;
	tnode->left = NULL;
	tnode->right = NULL;
	return(tnode);
}
void push(struct snode** topref,struct tnode* tree){
    struct snode* snode = (struct snode*)malloc(sizeof(struct snode));
    snode->tree = tree;
    snode->next = *topref;
    *topref = snode;
}
int isempty(struct snode* top){
	return (top == NULL) ? 1 : 0;
}
struct tnode* pop(struct snode** topref){
	struct tnode* res;
	struct snode* top;
    if(isempty(*topref)){
    	printf("Stack Overflow");
    }
    else{
    	top = *topref;
    	res = top->tree;
    	*topref = top->next;
    	return(res);
    }
}
struct tnode* top(struct snode* topref){
	if(isempty(topref))
		return NULL;
	return (topref->tree);
}
void preorder(struct tnode* root){
	if(root == NULL)
		return;
	struct snode* s = NULL;
    while(1){
    	while(root){
    		printf("%d ",root->data);
    		push(&s,root);
    		root = root->left;
    	}
    	if(isempty(s))
    		break;
    	root = pop(&s);
    	root = root->right;
    }
}
void inorder(struct tnode* root){
	struct snode* s = NULL;
    while(1){
    	while(root){
    		push(&s,root);
    		root = root->left;
    	}
    	if(isempty(s))
    		break;
    	root = pop(&s);
    	printf("%d ",root->data);
    	root = root->right;
    }
} 
void postorder(struct tnode* root){
	struct snode* s = NULL;
	do{
		while(root){
			if(root->right)
				push(&s,root->right);
			push(&s,root);
			root = root ->left;
		}
		root = pop(&s);
		if(root->right && top(s) == root->right){
			pop(&s);
			push(&s,root);
			root = root->right;
		}
		else{
			printf("%d ",root->data);
			root = NULL;
		}
	}while(!isempty(s));
}
int main(){
	struct tnode* root = newnode(1);
    root->left        = newnode(2); 
    root->right       = newnode(3); 
    root->left->left  = newnode(4); 
    root->left->right = newnode(5);
    root->right->left = newnode(6);
    root->right->right = newnode(7);
    preorder(root);
    printf("\n");
    inorder(root);
    printf("\n");
    postorder(root);
    printf("\n");
    return(0);
}