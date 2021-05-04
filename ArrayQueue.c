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
	q->front = q->rear = 0;
	q->array = (int*)malloc(q->size * sizeof(int));
    return q;
}
void EnQueue(struct queue* q,int data){
	if(q->size == q->rear) {
		printf("Queue is full\n");
	}
	else{
		q->array[q->rear++] = data;
	}
}
int DeQueue(struct queue* q){
	int data;
	if(q->front == q->rear){
		printf("Queue is empty\n");
	}
	else{
		data = q->array[0];
		for(int i=0;i < q->rear-1;i++){
			q->array[i] = q->array[i+1];
		}
		q->rear--;
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
	while(q->front != q->rear){
		data = DeQueue(q);
        printf("%d ",data);
	}
	printf("\n");
    EnQueue(q,100);
    EnQueue(q,460);
	data = DeQueue(q);// Full queue Exception
	return(0);
}