// Program to print Vertex Cover of a given undirected graph 
#include<stdio.h>
#include<stdlib.h>
  

class Graph 
{ 
    int V;    // No. of vertices 
    list<int> *adj;  // Pointer to an array containing adjacency lists 
public: 
    Graph(int V);  // Constructor 
    void addEdge(int v, int w); // function to add an edge to graph 
    void printVertexCover();  // prints vertex cover 
}; 
  
Graph::Graph(int V) 
{ 
    this->V = V; 
    adj = new list<int>[V]; 
} 
  
void Graph::addEdge(int v, int w) 
{ 
    adj[v].push_back(w); // Add w to v’s list. 
    adj[w].push_back(v); // Since the graph is undirected 
} 
  
// The function to print vertex cover 
void Graph::printVertexCover() 
{ 
    // Initialize all vertices as not visited. 
    bool visited[V]; 
    for (int i=0; i<V; i++) 
        visited[i] = false; 
  
    list<int>::iterator i; 
  
   
    for (int u=0; u<V; u++) 
    { 
         
        if (visited[u] == false) 
        { 
            
            for (i= adj[u].begin(); i != adj[u].end(); ++i) 
            { 
                int v = *i; 
                if (visited[v] == false) 
                { 
                     
                     visited[v] = true; 
                     visited[u]  = true; 
                     break; 
                } 
            } 
        } 
    } 
  
    // Print the vertex cover 
    for (int i=0; i<V; i++) 
        if (visited[i]) 
          cout << i << " "; 
} 
  
// Driver program to test methods of graph class 
int main() 
{ 
    // Create a graph given in the above diagram 
    Graph g(7); 
    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 3); 
    g.addEdge(3, 4); 
    g.addEdge(4, 5); 
    g.addEdge(5, 6); 
  
    g.printVertexCover(); 
  
    return 0; 
} 