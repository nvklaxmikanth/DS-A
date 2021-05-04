#include<stdio.h>
#include<stdlib.h>
struct queue{
	int front,rear;
	int size;
	int* array;
};
struct queue* createqueue(int size){
	struct queue* q = (struct queue*)malloc(sizeof(struct queue));
	q->size = size;
	q->front = q->rear = -1;
	q->array = (int*)malloc(q->size * sizeof(int));
    return q;
}
int isfull(struct queue* q){
	return((q->rear+1)%q->size == q->front);
}
int isempty(struct queue* q){
	return(q->front == -1);
}
void EnQueue(struct queue* q,int data){
	if(isfull(q)) {
		printf("Queue is full\n");
	}
	else{
		q->rear = (q->rear + 1)%q->size;
		q->array[q->rear] = data;
		if(q->front == -1)
			q->front = q->rear;
	}
}
int DeQueue(struct queue* q){
	int data = 0;
	if(isempty(q)){
		printf("Queue is empty\n");
	}
	else{
		data = q->array[q->front];
        if(q->front == q->rear)
        	q->front = q->rear = -1;
        else
        	q->front = (q->front+1)%q->size;
	}
	return data;
}
void deletequeue(struct queue* q){
	if(q){
		if(q->array)
			free(q->array);
		free(q);
	}
}
int main(){
	struct queue* q = createqueue(6);
	int i,data;
	EnQueue(q,10);
	EnQueue(q,20);
	EnQueue(q,30); 
	EnQueue(q,40);
	EnQueue(q,50);
	EnQueue(q,60);
	EnQueue(q,70);// Empty queue Exception
	while(!isempty(q)){
		data = DeQueue(q);
        printf("%d ",data);
	}
    EnQueue(q,100);
    EnQueue(q,460);
    printf("\n");
	while(!isempty(q)){
		data = DeQueue(q);
        printf("%d ",data);
	}
    printf("\n");
	data = DeQueue(q);// Full queue Exception
	return(0);
}