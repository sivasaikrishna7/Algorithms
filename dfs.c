#include <stdio.h>
#include <stdlib.h>
int SIZE=40;
struct queue {
int keys[40];
int forward;
int backwards;

};
struct node
{
int ver;
struct node* neighbour;
};
struct Graph
{
int no_ver;
struct node** adjLists;
int* visited;
};
struct Graph* createGraph(int vertices)
{
struct Graph* graph = malloc(sizeof(struct Graph));
graph->no_ver = vertices;
graph->adjLists = malloc(vertices * sizeof(struct node*));
graph->visited = malloc(vertices * sizeof(int));

int i;
for (i = 0; i < vertices; i++) {
graph->adjLists[i] = NULL;
graph->visited[i] = 0;
}
return graph;
}

struct node* createNode(int v)
{
struct node* newNode = malloc(sizeof(struct node));
newNode->ver = v;
newNode->neighbour = NULL;
return newNode;
}
void addEdge(struct Graph* graph, int src, int dest)
{
struct node* newNode = createNode(dest);
newNode->neighbour = graph->adjLists[src];
graph->adjLists[src] = newNode;
newNode = createNode(src);
newNode->neighbour = graph->adjLists[dest];
graph->adjLists[dest] = newNode;
}
struct queue* craeteQ() {
struct queue* q = malloc(sizeof(struct queue));
q->forward = -1;
q->backwards = -1;
return q;
}
int isEmpty(struct queue* q) {
if(q->backwards == -1)
return 1;
else
return 0;
}
void EnQ(struct queue* q, int value){

if(q->backwards == SIZE-1)
printf("\nQueue is Full!!");
else {
if(q->forward == -1)
q->forward = 0;
q->backwards++;
q->keys[q->backwards] = value;
}
}
int Dq(struct queue* q){
int item;
if(isEmpty(q)){
printf("queue is null");
item = -1;
}
else{
item = q->keys[q->forward];
q->forward++;
if(q->forward > q->backwards){
q->forward = q->backwards = -1;
}
}
return item;
}
void prtQ(struct queue *q) {
int i = q->forward;
if(isEmpty(q)) {
printf("Queue is empty");
} else {
printf("\nQueue contains:");
for(i = q->forward; i < q->backwards + 1; i++) {
printf("%d ", q->keys[i]);

}
}
}
void bfs(struct Graph* graph, int startVertex) {
struct queue* q = craeteQ();
graph->visited[startVertex] = 1;
EnQ(q, startVertex);
while(!isEmpty(q)){
prtQ(q);
int currentVertex = Dq(q);
struct node* temp = graph->adjLists[currentVertex];
while(temp) {
int adjVertex = temp->ver;
if(graph->visited[adjVertex] == 0){
graph->visited[adjVertex] = 1;
EnQ(q, adjVertex);
}
temp = temp->neighbour;
}
}
}
int main()
{
int no_of_vertices,no_of_edges,v1,v2,i;
printf("Enter the no.of vertices:");
scanf("%d",&no_of_vertices);
struct Graph* graph = createGraph(no_of_vertices);
printf("Enter the no.of edges:");

scanf("%d",&no_of_edges);
for(i=0;i<no_of_edges;i++)
{

printf("Enter the vertices of edge %d:",i+1);
scanf("%d%d",&v1,&v2);
addEdge(graph, v1, v2);

}
bfs(graph, 0);

return 0;
}
