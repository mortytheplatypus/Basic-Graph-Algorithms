#include <bits/stdc++.h>
#include "graph.h"
using namespace std;

/*
https://www.geeksforgeeks.org/topological-sorting/

    Prerequisite: DFS
        We can modify DFS to find the Topological Sorting of a graph. In DFS, we start from a vertex, we first print it, and then recursively call DFS for its adjacent vertices. 

    In topological sorting:
        We use a temporary stack. 
        We don’t print the vertex immediately, 
        We first recursively call topological sorting for all its adjacent vertices, then push it to a stack. 
        Finally, print the contents of the stack. 

    Note: A vertex is pushed to stack only when all of its adjacent vertices (and their adjacent vertices and so on) are already in the stack
*/

void topologicalSortUtil(Graph, int, vector<bool>&, stack<int>&);

void dfs(Graph, int, vector<bool>&, vector<int>&);
void topologicalSort(Graph);

int main() {
    char filename[] = "topsort.txt";
    Graph graph = createNewGraph(filename);
    graph.printGraph();
    
    topologicalSort(graph);

    return 0;
}

void dfs(Graph graph, int vertex, vector<bool>& visited, vector<int>& topologicalOrdering) {
    visited[vertex] = true;

    vector<int> neighbours = graph.getNeighboursOf(vertex);

    for (int neighbour : neighbours) {
        if (!visited[neighbour]) {
            dfs(graph, neighbour, visited, topologicalOrdering);
        }
    }

    topologicalOrdering.push_back(vertex);
}

void topologicalSort(Graph graph) {
    int vertices = graph.getVertices();

    vector<bool> visited(vertices, false);
    vector<int> topologicalOrdering;

    for (int vertex = 0; vertex < vertices; vertex++) {
        if (!visited[vertex]) {
            dfs(graph, vertex, visited, topologicalOrdering);
        }
    }

    reverse(topologicalOrdering.begin(), topologicalOrdering.end());
    for (int vertex : topologicalOrdering) {
        cout << vertex << " ";
    }
}

/* 
    vertices = 6, edges = 5

    1 -> 2
    2 -> 4
    3 -> 0
    4 -> 5
    5 -> 0

    topological ordering: 3 1 2 4 5 0
*/