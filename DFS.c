#include <stdio.h>
#include <stdlib.h>
struct graph{
	int v;
	int e;
	int **adj;
};
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
    	g->adj[v][u] = 1;
    }
    return g;
}
void DFS(struct graph* g,int u,int vi[]){
	vi[u] = 1;
	printf("%d ",u);
	for(int v = 0;v<g->v;v++){
		if(!vi[v] && g->adj[u][v]){
			DFS(g,v,vi);
		}
	}
}
void dfstraversal(struct graph* g,int vi[]){
	for(int i=0;i<g->v;i++)
		if(!vi[i])
			DFS(g,i,vi);
}
int main(){
	struct graph* g = creategraph();
	int vi[g->v];
	for(int i=0;i<g->v;i++)
		vi[i] = 0;
    dfstraversal(g,vi);
    printf("\n");
    //DFS(g,2,vi);
	return 0;
}