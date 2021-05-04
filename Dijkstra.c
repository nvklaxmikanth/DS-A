#include<stdio.h>
#include<malloc.h>
struct Heap{
	int *array;
	int *vertices;
	int count;
	int size;
};
struct graph{
	int v;
	int e;
	int **adj;
};
struct graph* creategraph(){
	int i,u,v,w;
	struct graph* g = (struct graph*)malloc(sizeof(struct graph));
    printf("Enter Vetrices and Edges");
    scanf("%d %d",&g->v,&g->e);
    g->adj = (int **)calloc(g->v,sizeof(int *));
    for (i=0;i<g->v;i++)
    	g->adj[i] = (int *)calloc(g->v,sizeof(int));
    for(i=0;i<g->e;i++){
    	scanf("%d %d %d",&u,&v,&w);
    	g->adj[u][v] = w;
    	g->adj[v][u] = w; //Undirected
    }
    return g;
}
struct Heap* createheap(int size){
	struct Heap* h = (struct Heap*)malloc(sizeof(struct Heap));
	h->count = 0;
	h->size = size;
	h->array = (int*)malloc(sizeof(int)*h->size);
	h->vertices = (int*)malloc(sizeof(int)*h->size);
	return(h);
}
int parent(struct Heap* h,int i){
	if(i<=0 || i>=h->count)
		return(-1);
	return((i-1)/2);
}
int leftchild(struct Heap* h,int i){
	int left = 2*i + 1;
	if(left >= h->count)
		return(-1);
	return(left);
}
int rightchild(struct Heap* h,int i){
	int right = 2*i + 2;
	if(right >= h->count)
		return -1;
	return(right);
}
int getmax(struct Heap* h){
	if(h->size == 0)
		return -1;
	return(h->array[0]);
}
void percolatedown(struct Heap* h,int i){
	int l,r,max,temp;
	l = leftchild(h,i);
	r = rightchild(h,i);
	if(l!=-1 && h->array[l] < h->array[i])
		max = l;
	else
		max = i;
	if(r!=-1 && h->array[r] < h->array[max])
		max = r;
	if(max!=i){
		temp = h->array[i];
		h->array[i] = h->array[max];
		h->array[max] = temp;
		temp = h->vertices[i];
		h->vertices[i] = h->vertices[max];
		h->vertices[max] = temp;
	    percolatedown(h,max);
	}
}
void percolateup(struct Heap* h,int i){
	int data = h->array[i];
	int v = h->vertices[i];
	while(i>0 && data < h->array[(i-1)/2]){
		h->array[i] = h->array[(i-1)/2];
		h->vertices[i] = h->vertices[(i-1)/2];
		i=(i-1)/2;
	}
	h->array[i] = data;
	h->vertices[i] = v;
}
int deletemin(struct Heap* h){
	int data,v;
	if(h->count==0)
		return(-1);
	data = h->array[0];
	v = h->vertices[0];
	h->array[0] = h->array[h->count-1];
	h->vertices[0] = h->vertices[h->count-1];
	h->count--;
	percolatedown(h,0);
	return(v);
}
void insert(struct Heap* h,int v,int data){
	int i;
	h->count++;
	i = h->count-1;
	while(i > 0 && data < h->array[(i-1)/2]){
		h->array[i] = h->array[(i-1)/2];
		h->vertices[i] = h->vertices[(i-1)/2];
		i=(i-1)/2;
	}
	h->array[i] = data;
	h->vertices[i] = v;
}
void destroyheap(struct Heap* h){
	if(h==NULL)
		return;
	free(h->array);
	free(h);
	h = NULL;
}
void changepriority(struct Heap* h,int v,int p){
	int i,op;
	for(i = 0;i<h->count;i++){
		if(h->vertices[i] == v){
			break;
		}
	}
	op = h->array[i];
	h->array[i] = p;
	if(p < op)
		percolateup(h,i);
	else
		percolatedown(h,i);
}
void Dijkstra(struct graph* g,struct Heap* h,int s){
	int v,w;
	int d;
	int distance[g->v],path[g->v];
	insert(h,s,s);
	for(int i = 0;i < g->v;i++){
		distance[i] = -1;
	    path[i] = -1;
	}
    distance[s] = 0;
    path[s] = 0;
    while(h->count != 0){
    	v = deletemin(h);
    	for(w = 0;w < g->v ;w++){
    		if(g->adj[v][w]){
	    		d = distance[v] + g->adj[v][w];
	            if(distance[w] == -1){
	            	distance[w] = d;
	            	insert(h,w,d);
	            	path[w] = v;
	            }
	            if(distance[w] > d){
	            	distance[w] = d;
	            	changepriority(h,w,d);
	            	path[w] = v;
	            }
	         }
    	}
    }
    for(int i = 0;i<g->v;i++){
    	printf("%d %d %d\n",i,distance[i],path[i]);
    }
}
int main(){
	struct graph* g = creategraph();
	struct Heap* h = createheap(g->v);
	Dijkstra(g,h,0);
	return 0;                             
}