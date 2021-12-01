// This program demonstrates the solution of Travelling Salesman problem using the approaximation algorithm
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define V 4


int min(int x, int y)
{
  return (x < y) ? x : y;
}

// implementation of traveling Salesman Problem
int travllingSalesmanProblem(int graph[][V], int s)
{
	// store all vertex apart from source vertex
	int v = 0;
	for (int i = 0; i < V; i++)
		if (i != s)
			v++;

    int *arr;
	arr = (int *)malloc(sizeof(int)*v);

	int c = 0;

	for (int i = 0; i < V; i++){
		if (i != s){
			arr[c] = i;
			c++;
		}
	}


	// store minimum weight Hamiltonian Cycle.
	int min_path = -99999;
	do {

		// store current Path weight(cost)
		int current_pathweight = 0;

		// compute current path weight
		int k = s;
		for (int i = 0; i < v; i++) {
			current_pathweight += graph[k][arr[i]];
			k = arr[i];
		}
		current_pathweight += graph[k][s];

		// update minimum
		min_path = min(min_path, current_pathweight);

	} while (
		next_permutation(0, v-1));

	return min_path;
}

// Driver Code
int main()
{
	// matrix representation of graph
	int graph[][V] = { { 0, 10, 15, 20 },
					{ 10, 0, 35, 25 },
					{ 15, 35, 0, 30 },
					{ 20, 25, 30, 0 } };
	int s = 0;
	printf(travllingSalesmanProblem(graph, s));
	return 0;
}
