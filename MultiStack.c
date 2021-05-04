#include<stdio.h>
#include<malloc.h>
struct multistack{
	int* array;
	int size;
	int top1,top2;
};
struct multistack* createstack(int size){
	struct multistack* s = (struct multistack*)malloc(sizeof(struct multistack));
    s->size = size;
    s->top1 = -1;
    s->top2 = size;
    s->array = (int*)malloc(s->size * sizeof(int));
    return s;
}
void push1(struct multistack* s,int data){
	if(s->top1 < s->top2 - 1){
		s->array[++s->top1] = data;
	}
	else{
		printf("Stack 1 overflow\n");
	}
}
void push2(struct multistack* s,int data){
	if(s->top1 < s->top2 - 1){
		s->array[--s->top2] = data;
	}
	else{
		printf("Stack 2 overflow\n");
	}
}
int pop1(struct multistack* s){
	if(s->top1 >= 0){
		int data = s->array[s->top1--];
		return data;
	}
	else{
		printf("Stack 1 underflow\n");
	}
}
int pop2(struct multistack* s){
	if(s->top2 < s->size){
		int data = s->array[s->top2++];
		return data;
	}
	else{
		printf("Stack 2 underflow\n");
	}
}
int main(){
	struct multistack* s = createstack(5);
	push1(s,18);
	push2(s,10);
	push2(s,333);
	push1(s,17);
	push2(s,7);
	push1(s,1);
	push2(s,4);
	while(s->top1 >= 0){
		printf("%d ",pop1(s));
	}
	printf("\n");
	while(s->top2 < s->size){
		printf("%d ",pop2(s));
	}
	pop1(s);
	pop2(s);
	return 0;
}