#include<stdio.h>
#include<malloc.h>
struct trie{
	char data;
	int end;
	struct trie *child[26];
};
struct trie* insert(struct trie* root,char* word){
	int index;
	if(!*word)
		return root;
	if(!root){
		struct trie *node = (struct trie*)malloc(sizeof(struct trie));
		node->data = *word;
		for(int i=0;i<26;i++)
			node->child[i] = NULL;
		index = (int)*word+1 - 97;
		if(!*(word+1))
			node->end = 1;
		else
            node->child[index] = insert(node->child[index],word+1);
        return node;
	}
	index = (int)*word+1 - 97;
	root->child[index]= insert(root->child[index],word+1);
	return root;
}
int search(struct trie* root,char* word){
	if(!root){
		printf("movaa\n");
		return -1;
	}
	if(!*word){
		if(root->end)
			return 1;
		else
			return -1;
	}
	if(root->data == *word){
		printf("%c %c\n",root->data,*word);
		printf("%c\n",root->child[*word]->data);
		return search(root->child[*word],word+1);
	}
	else
		return -1;
}
int main(){
	struct trie* root = NULL;
	root = insert(root,"hello");
    root = insert(root,"hii");
	printf("%d",search(root,"hello"));
	return 0;
}