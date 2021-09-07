#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
struct trie{
	bool end;
	struct trie *array[26];
};
struct trie* getnode(int v){
	struct trie* t = (struct trie*)malloc(sizeof(struct trie));
	t->end = false;
	for(int i=0;i<26;i++)
		t->array[i] = NULL;
	return t;
}
void insert(struct trie* t,char* s,int n){
	struct trie* temp = t;
	int idx;
	for(int i=0;i<n;i++){
        idx = s[i] - 'a';
		if(!temp->array[idx])
		    temp->array[idx] = getnode(0);
		temp = temp->array[idx];
	}
	temp->end = true;
}
int search(struct trie* root,char* word,int n){
	struct trie* trie = root;
	for(int i=0;i<n;i++){
		int idx = word[i] - 'a';
		if(!trie->array[idx])
		    return false;
		trie = trie->array[idx];
	}
	return (trie->end);
}
int main(){
	struct trie* t = getnode(0);
	int n;
	scanf("%d",&n);
	char s[1000000];
	for(int i=0;i<n;i++){
		scanf("%s",s);
		insert(t,s,strlen(s));
	}
	scanf("%s",s);
	printf("%d",search(t,s,strlen(s)));
	return 0;
}