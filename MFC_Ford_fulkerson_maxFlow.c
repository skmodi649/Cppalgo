// C program for implementation of the ford fulkerson algorithm for maximum flow in the graph
#include<stdio.h>
#include<limits.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

#define V 6

// first we will have to create a queue using arrays

struct Queue {
    int front, rear, size;
    unsigned capacity;
    int* array;
};
 

struct Queue* createQueue(unsigned capacity)
{
    struct Queue* queue = (struct Queue*)malloc(
        sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
 
    // This is important, see the enqueue
    queue->rear = capacity - 1;
    queue->array = (int*)malloc(
        queue->capacity * sizeof(int));
    return queue;
}
 

int isFull(struct Queue* queue)
{
    return (queue->size == queue->capacity);
}
 
// Queue is empty when size is 0
int isEmpty(struct Queue* queue)
{
    return (queue->size == 0);
}
 

void enqueue(struct Queue* queue, int item)
{
    if (isFull(queue))
        return;
    queue->rear = (queue->rear + 1)
                  % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size = queue->size + 1;
}
 

int dequeue(struct Queue* queue)
{
    if (isEmpty(queue))
        return INT_MIN;
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1)
                   % queue->capacity;
    queue->size = queue->size - 1;
    return item;
}
 

int front(struct Queue* queue)
{
    if (isEmpty(queue))
        return INT_MIN;
    return queue->array[queue->front];
}
 

int rear(struct Queue* queue)
{
    if (isEmpty(queue))
        return INT_MIN;
    return queue->array[queue->rear];
}




bool bfs(int rGraph[V][V], int s, int t, int parent[])
{

	bool visited[V];
	memset(visited, 0, sizeof(visited));

	
	struct Queue* queue = createQueue(1000);
	enqueue(queue , s);
	visited[s] = true;
	parent[s] = -1;

	
	while (!isEmpty(queue)) {
        int u = front(queue);
        dequeue(queue);
		for (int v = 0; v < V; v++) {
			if (visited[v] == false && rGraph[u][v] > 0) {
				
				if (v == t) {
					parent[v] = u;
					return true;
				}
				enqueue(queue , v);
				parent[v] = u;
				visited[v] = true;
			}
		}
	}

	
	return false;
}

int min(int a , int b){
    if(a < b)
    return a;
    else
    return b;
}

int fordFulkerson(int graph[V][V], int s, int t)
{
	int u, v;

	
	int rGraph[V]
			[V]; 
	for (u = 0; u < V; u++)
		for (v = 0; v < V; v++)
			rGraph[u][v] = graph[u][v];

	int parent[V]; 

	int max_flow = 0; 
	while (bfs(rGraph, s, t, parent)) {
	
		int path_flow = INT_MAX;
		for (v = t; v != s; v = parent[v]) {
			u = parent[v];
			path_flow = min(path_flow, rGraph[u][v]);
		}

		for (v = t; v != s; v = parent[v]) {
			u = parent[v];
			rGraph[u][v] -= path_flow;
			rGraph[v][u] += path_flow;
		}

		max_flow += path_flow;
	}

	// Return the overall flow
	return max_flow;
}

// Driver program to test above functions
int main()
{
	// Let us create a graph shown in the above example
	int graph[V][V]
		= { { 0, 2, 0, 3, 0, 0 }, { 0, 0, 5, 0, 3, 0 },
			{ 0, 0, 0, 0, 0, 2 }, { 0, 0, 1, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 4 }, { 0, 0, 0, 0, 0, 0 } };

    printf("Maximum flow is %d",fordFulkerson(graph, 0, 5));

	return 0;
}
