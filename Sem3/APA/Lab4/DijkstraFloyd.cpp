#include <iostream>
#include <limits.h>
#include <iomanip>
#define V 100
int iter1 = 0, iter2 = 0;
int randGraph[V][V];
void GenRandomGraphs(int Margine, int Vertex)
{
    for (size_t i = 0; i < Vertex; i++)
        for (size_t j = 0; j < Vertex; j++)
            randGraph[i][j] = 0;
    int count = 0;
    int i, j;
    while (count < Margine)
    {
        i = rand() % Vertex;
        j = rand() % Vertex;
        if (i == j || randGraph[i][j] || randGraph[j][i])
            continue;
        randGraph[i][j] = randGraph[j][i] = rand() % 100;
        count++;
    }
}
//Djikstra
int MinDistance(int distance[], bool visited[])
{
    int min = INT_MAX, minIndex;
    for (size_t v = 0; v < V; v++)
    {
        if (!visited[v] && distance[v] < min)
        {
            min = distance[v];
            minIndex = v;
        }
    }
    return minIndex;
}
void PrintDijkstraSolution(int src, int distance[])
{
    std::cout << "Distance from Source (Dijkstra)" << std::endl;
    for (size_t v = 0; v < V; v++)
    {
        if (distance[v] != INT_MAX)
            std::cout << src << "->" << v << " : " << distance[v] << std::endl;
    }
}
void Dijkstra(int graph[V][V], int source)
{
    int distance[V];
    bool visited[V];
    for (size_t i = 0; i < V; i++)
    {
        distance[i] = INT_MAX, visited[i] = false;
    }
    distance[source] = 0;
    for (size_t edge = 0; edge < V - 1; edge++)
    {
        int u = MinDistance(distance, visited);
        visited[u] = true;
        for (size_t v = 0; v < V; v++)
        {
            if (!visited[v] && graph[u][v] && distance[u] != INT_MAX && distance[u] + graph[u][v] < distance[v])
            {
                distance[v] = distance[u] + graph[u][v];
            }
        }
    }
    PrintDijkstraSolution(source, distance);
}
//Floyd
void PrintFloydSolution(int distance[V][V], int src)
{
    std::cout << "Distance from Source (Floyd)" << std::endl;
    for (size_t v = 0; v < V; v++)
        if (distance[src][v] != INT_MAX)
            std::cout << src << "->" << v << " : " << distance[src][v] << std::endl;
}
void Floyd(int graph[V][V], int source)
{
    int distance[V][V];
    for (size_t i = 0; i < V; i++)
        for (size_t j = 0; j < V; j++)
            if (i == j)
                distance[i][j] = 0;
            else if (graph[i][j] == 0)
                distance[i][j] = INT_MAX;
            else
                distance[i][j] = graph[i][j];
    for (size_t k = 0; k < V; k++)
        for (size_t u = 0; u < V; u++)
            for (size_t v = 0; v < V; v++)
            {
                if (distance[u][v] > distance[u][k] + distance[k][v] && distance[u][k] != INT_MAX && distance[k][v] != INT_MAX)
                    distance[u][v] = distance[u][k] + distance[k][v];
            }
    PrintFloydSolution(distance, source);
}
int main()
{
    double timeTaken;
    GenRandomGraphs(4950, V);
    std::cout << "Algoritmul Dijkstra" << std::endl;
    Dijkstra(randGraph, 0);
    std::cout << std::endl;
    std::cout << "Algoritmul Floyd" << std::endl;
    Floyd(randGraph, 0);
    std::cout << std::endl;
    return 0;
}
