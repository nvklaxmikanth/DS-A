#include<stdio.h>
#include<malloc.h>
struct Node{
    char key;
    int value;
};
struct Heap{
    struct Node* array;
    int count;
    int size;
};
struct tree{
    struct Node* data;
    struct tree* left;
    struct tree* right;
};
struct Heap* createheap(int size){
    struct Heap* h = (struct Heap*)malloc(sizeof(struct Heap));
    h->count = 0;
    h->size = size;
    h->array = (struct Node*)malloc(sizeof(struct Node)*size);
    return(h);
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
void percolatedown(struct Heap* h,int i){
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	int l,r,max;
	l = leftchild(h,i);
	r = rightchild(h,i);
	if(l!=-1 && h->array[l].value < h->array[i].value)
		max = l;
	else
		max = i;
	if(r!=-1 && h->array[r].value < h->array[max].value)
		max = r;
	if(max!=i){
		temp->value = h->array[i].value;
		h->array[i].value = h->array[max].value;
		h->array[max].value = temp->value;
		temp->key = h->array[i].key;
		h->array[i].key = h->array[max].key;
		h->array[max].key = temp->key;
	    percolatedown(h,max);
	}
}
struct Node* deletemin(struct Heap* h){
    struct Node *data = (struct Node*)malloc(sizeof(struct Node));
	if(h->count==0)
		return(NULL);
	data->key = h->array[0].key;
	data->value = h->array[0].value;
	h->array[0].value = h->array[h->count-1].value;
	h->array[0].key = h->array[h->count-1].key;
	h->count--;
	percolatedown(h,0);
	return(data);
}
void insert(struct Heap* h,char key,char value){
	int i;
	h->count++;
	i = h->count-1;
	while(i > 0 && value < h->array[(i-1)/2].value){
		h->array[i] = h->array[(i-1)/2];
		i=(i-1)/2;
	}
	h->array[i].key = key;
	h->array[i].value = value;
}
void Huffman(struct Heap* h,int n){
	struct tree* t;
	for(int i=1;i<n;i++){
        t = (struct tree*)malloc(sizeof(struct tree));
        t->left = (struct Node*)malloc(sizeof(struct Node));
        t->data = (struct tree*)malloc(sizeof(struct tree));
        t->right = (struct tree*)malloc(sizeof(struct tree));
        t->left = deletemin(h);
        t->right = deletemin(h);
        t->data.value = t->left.value + t->right.value;
        t->data->key = '-';
        insert(h,t->data.key,t->data.value);
	}
	/*while(h->count !=0){
		struct Node* node =deletemin(h);
		printf("%d %d\n",node->key,node->value);
	}*/
    printf("%d\n",h->count);
}
int main(){
	int n;
	char key;
	int value;
	printf("Enter no of elements\n");
	scanf("%d\n",&n);
    struct Heap* h = createheap(n);
	for(int i=0;i<n;i++){
		scanf("%c %d\n",&key,&value);
		h->array[i].value = value;
		h->array[i].key = key;
	}
	h->count = n;
	for(int i=(n-1)/2;i>=0;i--)
		percolatedown(h,i);
    Huffman(h,n);
	return 0;
}