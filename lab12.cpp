#include <iostream>
#include <limits.h>
using namespace std;
  
// Number of vertices in the graph
#define V 6
  
int min_Distance(int dist[], bool sptSet[])
{
    int min = INT_MAX, min_index;   // Initialize min value
    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;
    return min_index;
}
  
void print_Solution(int dist[])
{
    cout << "Vertex \t           Distance from Source" << endl;
    for (int i = 0; i < V; i++)
        cout << i << " \t\t\t\t" << dist[i] << endl;
}

void dijkstra(int graph[V][V], int src)
{
    int dist[V];
    bool sptSet[V]; 
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;
    
    dist[src] = 0;      // Distance of source vertex from itself is always 0
 
    for (int count = 0; count < V - 1; count++)      // Find shortest path for all vertices
    {
        int u = min_Distance(dist, sptSet);
        sptSet[u] = true;   // Mark the picked vertex as processed
 
        for (int v = 0; v < V; v++)  // Update dist value of the adjacent vertices of the picked vertex.
 
            if (!sptSet[v] && graph[u][v]
                && dist[u] != INT_MAX
                && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }
    
    print_Solution(dist);    // print the constructed distance array
}
  
int main()
{
    int graph[V][V] = { { 0,10,0,0,15,5 },
                        { 10,0,10,30,0,0},
                        { 0,10,0,12,5,0 },
                        { 0,30,12,0,0,20 },
                        { 15,0,5,0,0,0 },
                        { 5,0,0,20,0,0 },
                         };
 
    dijkstra(graph, 5);  // Function call
    return 0;
}
