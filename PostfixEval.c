#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
struct stack{
	int top;
	int size;
	int* array;
};
struct stack* createstack(int size){
	struct stack* s = (struct stack*)malloc(sizeof(struct stack));
    s->size = size;
    s->top = -1;
    s->array = (int*)malloc(s->size*(sizeof(int)));
    return(s);
}
int isempty(struct stack* s){
	return(s->top == -1);
}
int isfullstack(struct stack* s){
	return(s->top == s->size-1);
}
void push(struct stack* s,int data){
	if(isfullstack(s))
		return;
	else
		s->array[++s->top] = data;
}
int peek(struct stack* s){
	return s->array[s->top];
}
int pop(struct stack* s){
	if(isempty(s))
		return -1;
    else
    	return(s->array[s->top--]);
}
int isoperand(char ch){
	return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}
int evalpostfix(char* exp){
	struct stack* s = createstack(strlen(exp));
	int i;
	for(i=0;exp[i];++i){
		if(isdigit(exp[i])){
			push(s,exp[i]-'0');
		}	
        else{
        	int v1 = pop(s);
        	int v2 = pop(s);
        	switch(exp[i]){
                case '+': push(s,v2+v1); break; 
                case '-': push(s,v2-v1); break; 
                case '*': push(s,v2*v1); break; 
                case '/': push(s,v2/v1); break; 
        	}
        }
	}
	return pop(s);
}
int main() 
{ 
    char exp[] = "976*3/+4-"; 
    printf ("postfix evaluation: %d", evalpostfix(exp));
    return 0; 
} 