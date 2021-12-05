#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

const int MAX = 100;

int store[MAX], n;
int graph[MAX][MAX];


int d[MAX];


bool is_clique(int b)
{
	
	for (int i = 1; i < b; i++) {
		for (int j = i + 1; j < b; j++)

			
			if (graph[store[i]][store[j]] == 0)
				return false;
	}
	return true;
}



int findCliques(int i, int l, int s)
{
	
	for (int j = i + 1; j <= n - (s - l); j++)

		
		if (d[j] >= s - 1) {

			
			store[l] = j;

			
			if (is_clique(l + 1))

				
				if (l < s)

					
					findCliques(j, l + 1, s);

				
				else
					return 1;
		}
}

int main()
{
	int edges[][7] = { { 0, 1, 0, 1, 1, 0, 0},
					   { 1, 0, 1, 1, 0, 1, 1},
					   { 0, 1, 0, 1, 0, 1, 1},
					   { 1, 1, 1, 0, 1, 1, 1},
					   { 1, 0, 0, 1, 0, 1, 0},
					   { 0, 1, 1, 1, 1, 0, 1}, 
                       { 0, 1, 1, 1, 0, 1, 0}};
		int k = 5;
	int size = sizeof(edges) / sizeof(edges[0]);
	n = 5;

	for (int i = 0; i < size; i++) {
		graph[edges[i][0]][edges[i][1]] = 1;
		graph[edges[i][1]][edges[i][0]] = 1;
		d[edges[i][0]]++;
		d[edges[i][1]]++;
	}

	findCliques(0, 1, k);

	return 0;
}
