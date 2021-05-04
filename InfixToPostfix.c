#include<stdio.h>
#include<ctype.h>
#include<string.h>
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
char peek(struct stack* s){
	return s->array[s->top];
}
char pop(struct stack* s){
	if(isempty(s))
		return -1;
    else
    	return(s->array[s->top--]);
}
int isoperand(char ch){
	return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}
int pre(char ch){
    switch (ch) 
    { 
    case '+': 
    case '-': 
        return 1; 
  
    case '*': 
    case '/': 
        return 2; 
  
    case '^': 
        return 3; 
    } 
    return -1; 
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
	printf("Postfic evaluation %d",pop(s));
}
int infixtopostfix(char* exp){
	int i,k;
	struct stack* s = createstack(strlen(exp));
    for(i=0,k = -1;exp[i];++i){
    	if(isdigit(exp[i])){
    		exp[++k] = exp[i];
    	}
    	else if(exp[i] == '('){
    		push(s,exp[i]);
    	}
    	else if(exp[i] == ')'){
    		while(!isempty(s) && peek(s) != '('){
    			exp[++k] = pop(s);
    		}
    		if(!isempty(s) && peek(s) != '('){
    			return -1;
    		}
    		else
    			pop(s);
    	}
    	else{
    		while(!isempty(s) && pre(exp[i]) <= pre(peek(s))){
    			exp[++k] = pop(s);
    		}
    	    push(s,exp[i]);
    	}
    }
    while(!isempty(s)){
    	exp[++k] = pop(s);
    }
    exp[++k] = '\0';
    printf("Infix to Postfix %s\n",exp);
    evalpostfix(exp);
}
int main(){
	char exp[10]; 
	scanf("%s",exp);
	infixtopostfix(exp); 
    return 0; 
}