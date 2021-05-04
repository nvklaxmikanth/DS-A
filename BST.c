#include<stdio.h>
#include<stdlib.h>
struct bst{
	int data;
	struct bst* left;
	struct bst* right;
};
struct bst* find(struct bst* root,int data){
	if(root==NULL)
		return NULL;
	if(data < root->data)
		return find(root->left,data);
	else if(data > root->data)
		return find(root->right,data);
	else
		return root;
}
struct bst* findmin(struct bst* root){
	if(root == NULL)
		return NULL;
	else if(root->left == NULL)
		return root;
	else
		return(findmin(root->left));
}
struct bst* findmax(struct bst* root){
	if(root == NULL)
		return NULL;
	else if(root->right == NULL)
		return root;
	else
		return(findmax(root->right));
}
struct bst* insert(struct bst* root,int data){
	if(root == NULL){
		root = (struct bst*)malloc(sizeof(struct bst));
		root->data = data;
		root->left = root->right = NULL;
	}
	else{
		if(data < root->data)
			root->left = insert(root->left,data);
		else if(data > root->data)
			root->right = insert(root->right,data);
	}
	return(root);
}
struct bst* delete(struct bst* root,int data){
	struct bst* temp;
	if(root == NULL)
		printf("Not there in BST");
	else if(data < root->data)
		root->left = delete(root->left,data);
	else if(data > root->data)
		root->right = delete(root->right,data);
	else{
		if(root->left && root ->right){
			temp = findmax(root->left);
			root->data = temp->data;
			root->left = delete(root->left,root->data);
		}
		else{
			temp = root;
			if(root->left == NULL)
				root = root->right;
			else if(root->right == NULL)
				root = root->left;
			free(temp);
		}
	}
	return root;
}
void inorder(struct bst* root){
	if(root!=NULL){
		inorder(root->left);
		printf("%d ",root->data);
		inorder(root->right);
	}
}
int main(){
	struct bst* root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);
    inorder(root);
    printf("\n");
    root = delete(root,20);
    root = delete(root,30);
    root = delete(root,50);
    inorder(root);
    return 0;
}
