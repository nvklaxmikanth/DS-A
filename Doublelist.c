#include<stdio.h>
#include<stdlib.h>
struct list{
	int data;
	struct list* next;
	struct list* prev;
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
	int k = 1;
	struct list* temp;
	struct list* newnode = (struct list*)malloc(sizeof(struct list));
	newnode->data = data;
	if(position == 1){
		newnode->next = *head;
	    newnode->prev = NULL;
	    if(*head)
	    	(*head)->prev = newnode;
	    *head = newnode;
	    return;
    }
    temp = *head;
    while((k < position-1) && temp->next){
    	temp = temp->next;
    	k++;
    }
    newnode->next = temp->next;
    newnode->prev = temp;
    if(temp->next)
    	temp->next->prev = newnode;
    temp->next = newnode;
    return;
}
void delete(struct list** head,int position){
	struct list *current,*temp;
	int k=1;
	current = *head;
	if(*head == NULL){
		printf("list is empty");
		return;
	}
	if(position == 1){
		*head = (*head)->next;
		free(current);
		return;
	}
	while((k < position) &&  current->next != NULL){
		current = current->next;
		k++;
	}
	if(k != position){
		printf("Not in the list");
	}
	temp = current->prev;
	temp->next = current->next;
	if(current->next)
		current->next->prev = temp;
	free(current);
	return;
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
    insert(&root,20,1);
    insert(&root,40,2);
    insert(&root,10,1);
    insert(&root,50,4);
    insert(&root,60,5);
    insert(&root,30,3);
    display(root);
    delete(&root,3);
    printf("\n");
    delete(&root,5);
    delete(&root,1);
    display(root);
    deletelist(&root);
    return(0);
}