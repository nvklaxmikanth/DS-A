#include<stdio.h>
#include<stdlib.h>
struct list{
	int data;
	struct list* next;
};
void display(struct list* head){
	struct list* current = head;
	while(current != NULL){
		printf("%d ",current->data);
		current = current->next;
	}
	printf("\n");
}
void insert(struct list** head,int data,int position){
	struct list *p,*q,*newnode;
	int k = 1;
	newnode = (struct list*)malloc(sizeof(struct list));
	newnode->data = data;
	newnode->next = NULL;
	p = *head;
	if(position == 1){
		newnode->next = p;
		*head = newnode;
	}
	else{
		while((p != NULL) && (k < position)){
			k++;
			q = p;
			p = p->next;
		}
		q->next = newnode;
		newnode->next = p;
	}
}
void delete(struct list** head,int position){
	int k = 1;
	struct list *p,*q;
	if(*head == NULL){
		printf("Empty List");
		return;
	}
	p = *head;
	if(position == 1){
		*head = (*head)->next;
		free(p);
		return;
	}
	else{
		while((p != NULL) && (k < position)){
			k++;
			q = p;
			p = p->next;
		}
		if(p == NULL)
			printf("Not in the list");
		else{
			q->next = p->next;
			free(p);
		}
	}
}
void deletelist(struct list** head){
	struct list *temp,*itr;
	itr = *head;
	while(itr){
		temp = itr->next;
		free(itr);
		itr = temp;
	}
	*head = NULL;
}
int main(){
	struct list* root = NULL;
    insert(&root,10,1);
    insert(&root,20,2);
    insert(&root,40,3);
    insert(&root,50,4);
    insert(&root,60,5);
    insert(&root,30,3);
    display(root);
    delete(&root,6);
    delete(&root,1);
    delete(&root,3);
    display(root);
    deletelist(&root);
    return(0);
}