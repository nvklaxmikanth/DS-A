#include<stdio.h>
#include<stdlib.h>
struct Stack{
	int top;
	int size;
	int* array;
};
struct Stack* createstack(int size){
	struct Stack* s = (struct Stack*)malloc(sizeof(struct Stack));
    s->size = size;
    s->top = -1;
    s->array = (int*)malloc(s->size*(sizeof(int)));
    return(s);
}
int isempty(struct Stack* s){
	return(s->top == -1);
}
int isfullstack(struct Stack* s){
	return(s->top == s->size-1);
}
void push(struct Stack* s,int data){
	if(isfullstack(s))
		printf("stack overflow while pushing %d\n",data);
	else
		s->array[++s->top] = data;
}
int pop(struct Stack* s){
	if(isempty(s))
		printf("stack underflow while popping\n");
    else
    	return(s->array[s->top--]);
}
void deletestack(struct Stack* s){
	if(s){
		if(s->array)
			free(s->array);
		free(s);
	}
}
int main(){
	struct Stack* s = createstack(6);
	int data;
	push(s,3);
    push(s,5);
    push(s,9);
    push(s,1);
    push(s,12);
    push(s,15);
    push(s,20);//stack overflow
    while(!isempty(s)){
    	data = pop(s);
    	printf("%d ",data);
    }
    printf("\n");
    data = pop(s);//stack underflow
    return(0);
}