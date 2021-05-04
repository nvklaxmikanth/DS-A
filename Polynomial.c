#include <stdio.h>
#include <stdlib.h>
typedef struct polynomial{
	int power;
	int coeff;
	struct polynomial* next;
}poly;
poly* create(poly* p,int coeff,int power){
	poly* n = (poly*)malloc(sizeof(poly));
	n->coeff = coeff;
	n->power = power;
	n->next = NULL;
	if(p==NULL)
		return n;
	poly* temp = p;
	while(temp->next != NULL)
		temp = temp->next;
	temp->next = n;
    return p;
}
void show(poly* node)
{
    while (node->next != NULL) {
       printf("%dx^%d", node->coeff, node->power); 
        if (node->power >= 0) {
            if (node->next != NULL)
                printf(" + ");
        } 
        node = node->next;  
    }
    printf("%dx^%d\n", node->coeff, node->power); 
}
void add(poly* n1,poly* n2){
	poly* p = NULL;
    while(n1 && n2){
	    if(n1->power > n2->power){
            p = create(p,n1->coeff,n1->power);
            n1 = n1->next;
	    }
	    else if(n1->power < n2->power){
            p = create(p,n2->coeff,n2->power);
            n2 = n2->next;
	    }
	    else{
            p = create(p,n1->coeff+n2->coeff,n1->power);
            n1 = n1->next;
            n2 = n2->next;
	    }
	}
	while(n1 || n2){
		if(n1->next){
			p = create(p,n1->coeff,n1->power);
			n1 = n1->next;
		}
		if(n2->next){
			p = create(p,n2->coeff,n2->power);
			n2 = n2->next;
		}
	}
	show(p);
}
int main(){
	poly *p = NULL,*p1 = NULL,*p2 = NULL;
	p1 = create(p1,5,2);
	p1 = create(p1,4,1);
	p1 = create(p1,2,0);
	p2 = create(p2,-5,1);
	p2 = create(p2,-5,0);
	add(p1,p2);
	show(p1);
	show(p2);
	return 0;
}