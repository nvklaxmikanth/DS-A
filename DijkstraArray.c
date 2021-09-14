#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
struct graph{
	int v,e;
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
int findmin(int a[],int n){
	int min = -1;
	for(int i=0;i<n;i++){
		if(a[i] != -1){
			if(min == -1){
				min = i;
			}
			if(a[min] < a[i]){
				min = i;
			}
		}
	}
	return min;
}
int isempty(int a[],int n){
	for(int i=0;i<n;i++){
		if(a[i] != -1)
		    return 0;
	}
	return 1;
}
void dijkstra(struct graph* g,int s,int dest){
	int dist[g->v];
	int path[g->v];
	int a[g->v];
	int d;
	memset(a,-1,sizeof(a));
	memset(dist,-1,sizeof(dist));
	memset(path,-1,sizeof(path));
	dist[s] = 0;
    path[s] = 0;
    a[s] = 1;
	while(!isempty(a,g->v)){
        int u = findmin(a,g->v);
		a[u] = -1;
		for(int v=0;v<g->v;v++){
			if(g->adj[u][v]){
                d = dist[u] + g->adj[u][v];
				if(dist[v] == -1){
                    dist[v] = d;
					path[v] = u;
					a[v] = d;
				}
				if(dist[v] > d){
					dist[v] = d;
					path[v] = u;
					a[v] = d;
				}
			}
		}
	}
	printf("%d\n",dist[dest]);
}
int main(){
    struct graph* g = creategraph();
	int u,v,q;
	scanf("%d",&q);
	for(int i=0;i<q;i++){
		scanf("%d %d",&u,&v);
		dijkstra(g,u,v);
	}
	return 0;
}