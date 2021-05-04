#include<stdio.h>
#include<malloc.h>
struct Heap{
	int *array;
	int *vertices;
	int count;
	int size;
};
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
	printf("%d\n",i);
	op = h->array[i];
	h->array[i] = p;
	if(p < op)
		percolateup(h,i);
	else
		percolatedown(h,i);
}
int main(){
	struct Heap* h = createheap(10);
	insert(h,5,10); 
	insert(h,3,2);
	insert(h,8,1);
	insert(h,6,0);
	insert(h,1,9); 
	insert(h,8,1);
	changepriority(h,6,12);
	changepriority(h,5,1);
    for (int i = 0;h->count; ++i)
    	printf("%d ",deletemin(h));
}