#include<stdio.h>
#include<malloc.h>
struct Heap{
	int *array;
	int count;
	int size;
    int heaptype;
};
struct Heap* createheap(int size,int heaptype){
	struct Heap* h = (struct Heap*)malloc(sizeof(struct Heap));
	h->heaptype = heaptype;
	h->count = 0;
	h->size = size;
	h->array = (int*)malloc(sizeof(int)*h->size);
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
	if(l!=-1 && h->array[l] > h->array[i])
		max = l;
	else
		max = i;
	if(r!=-1 && h->array[r] > h->array[max])
		max = r;
	if(max!=i){
		temp = h->array[i];
		h->array[i] = h->array[max];
		h->array[max] = temp;
	    percolatedown(h,max);
	}
}
void resizeheap(struct Heap* h){
	int* temp = h->array;
	h->array = (int*)malloc(sizeof(int)*h->size*2);
	for(int i=0;i<h->size;i++)
		h->array[i] = temp[i];
	h->size *= 2;
	free(temp);
}
int deletemax(struct Heap* h){
	int data;
	if(h->count==0)
		return(-1);
	data = h->array[0];
	h->array[0] = h->array[h->count-1];
	h->count--;
	percolatedown(h,0);
	return(data);
}
int insert(struct Heap* h,int data){
	int i;
	if(h->count == h->size)
		resizeheap(h);
	h->count++;
	i = h->count-1;
	while(i>0 && data>h->array[(i-1/2)]){
		h->array[i] = h->array[(i-1)/2];
		i=(i-1)/2;
	}
	h->array[i] = data;
}
void destroyheap(struct Heap* h){
	if(h==NULL)
		return;
	free(h->array);
	free(h);
	h = NULL;
}
void buildheap(struct Heap* h,int a[],int n){
	if(h==NULL)
		return;
	while(n>h->size)
		resizeheap(h);
	for(int i=0;i<n;i++)
		h->array[i] = a[i];
	h->count = n;
	for(int i=(n-1)/2;i>=0;i--)
		percolatedown(h,i);
}
int main(){
	struct Heap* h;
	h = createheap(7,1);
    int a[] = { 1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17 }; 
   	buildheap(h,a,11);
	printf("Parent of last node %d\n",parent(h,9));
	printf("rightchild of node %d\n",rightchild(h,1));
	printf("leftchild of node %d\n",leftchild(h,1));
	printf("max value %d\n",getmax(h));
	for(int i=0;i<h->count;i++)
		printf("%d ",h->array[i]);
	deletemax(h);
	printf("\n");
	insert(h,19);
	for(int i=0;i<h->count;i++)
		printf("%d ",h->array[i]);
	printf("max after insert value %d\n",getmax(h));
	destroyheap(h);
	return 0; 
}