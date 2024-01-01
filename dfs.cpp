#include <bits/stdc++.h>
#include "graph.h"
using namespace std;

void dfs_recursive(Graph, int, vector<bool>&);
void dfs(Graph, int);

int main() {
    char filename[] = "input.txt";
    Graph graph = createNewGraph(filename);
    graph.printGraph();

    int vertices = graph.getVertices();

    for (int vertex = 0; vertex < vertices; vertex++) {
        
        cout << "iterative dfs(" << vertex << "): ";
        dfs(graph, vertex);
        
        cout << "\n";
        
        cout << "dfs_recursive(" << vertex << "): ";
        vector<bool> visited(vertices, false);
        dfs_recursive(graph, vertex, visited);

        cout << "\n\n";
    }

    return 0;
}

void dfs_recursive(Graph graph, int vertex, vector<bool> &visited) {
    cout << vertex << " ";
    visited[vertex] = true;

    vector<int> neighbours = graph.getNeighboursOf(vertex);

    for (int neighbour : neighbours) {
        if (!visited[neighbour]) {
            dfs_recursive(graph, neighbour, visited);
        }
    }
}

void dfs(Graph graph, int vertex) {
    stack<int> s;
    s.push(vertex);

    vector<bool> visited(graph.getVertices(), false);

    while (!s.empty()) {
        int current = s.top();
        s.pop();

        if (!visited[current]) {
            cout << current << " ";
            visited[current] = true;
        
            vector<int> neighbours = graph.getNeighboursOf(current);

            for (int neighbour : neighbours) {
                if (!visited[neighbour]) {
                    s.push(neighbour);
                }
            }
        }
    }
}

