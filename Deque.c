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
void REnQueue(struct queue* q,int data){
	if(isfull(q)) {
		printf("Queue is full\n");
	}
	else{
		if(q->front == -1)
			q->front = q->rear = 0;
		else
			q->rear = (q->rear + 1)%q->size;
		q->array[q->rear] = data;
	}
}
void FEnQueue(struct queue* q,int data){
	if(isfull(q)) {
		printf("Queue is full\n");
	}
	else{
		if(q->front == -1)
			q->front = q->rear = 0;
		else
			q->front = (q->front +q->size - 1)%q->size;
		q->array[q->front] = data;
	}
}
void FDeQueue(struct queue* q){
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
	printf("%d Front DeQueue Data\n",data);
}
void RDeQueue(struct queue* q){
	int data = 0;
	if(isempty(q)){
		printf("Queue is empty\n");
	}
	else{
		data = q->array[q->rear];
        if(q->front == q->rear)
        	q->front = q->rear = -1;
        else
        	q->rear = (q->rear +q->size - 1)%q->size;
	}
	printf("%d Rear DeQueue Data\n",data);
}
int main(){
	struct queue* q = createqueue(6);
	int i,data;
	FEnQueue(q,10);
	REnQueue(q,20);
	RDeQueue(q);
	FEnQueue(q,30); 
	FDeQueue(q);
	REnQueue(q,40);
	FEnQueue(q,50);
	FDeQueue(q);
	REnQueue(q,60);
	FEnQueue(q,70);
	RDeQueue(q);
	return(0);
}