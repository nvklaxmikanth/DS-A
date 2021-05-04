#include <stdio.h>
#include <stdlib.h>
struct graph{
	int v;
	int e;
	int **adj;
};
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
struct graph* creategraph(){
	int i,u,v;
	struct graph* g = (struct graph*)malloc(sizeof(struct graph));
    printf("Enter Vetrices and Edges");
    scanf("%d %d",&g->v,&g->e);
    g->adj = (int **)calloc(g->v,sizeof(int *));
    for (i=0;i<g->v;i++)
    	g->adj[i] = (int *)calloc(g->v,sizeof(int));
    for(i=0;i<g->e;i++){
    	scanf("%d %d",&u,&v);
    	g->adj[u][v] = 1;
    	g->adj[v][u] = 1; //Undirected
    }
    return g;
}
void BFS(struct graph* g,int u,int vi[]){
	int v;
	struct queue *q = createqueue(100);
	EnQueue(q,u);
    while(!isempty(q)){
    	u = DeQueue(q);
    	printf("%d ",u);
    	vi[u] = 1;
    	for(v = 0;v<g->v;v++){
			if(!vi[v] && g->adj[u][v]){
				vi[v] = 1;
			    EnQueue(q,v);
			}
    	}
    }
}
void bfstraversal(struct graph* g,int vi[]){
	for(int i=0;i<g->v;i++)
		if(!vi[i])
			BFS(g,i,vi);
}
int main(){
	struct graph* g = creategraph();
	int vi[g->v];
	for(int i=0;i<g->v;i++)
		vi[i] = 0;
    bfstraversal(g,vi);
    printf("\n");
    //BFS(g,2,vi); //At any Vertex
	return 0;
}