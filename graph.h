#include <bits/stdc++.h>
using namespace std;

#define INPUT_FILE "input.txt"

struct Node {
    int vertex;
    double weight;

    Node(int vertex, double weight) {
        this->vertex = vertex;
        this->weight = weight;
    }
};

struct Comparator {
	bool operator()(Node const& first, Node const& second) {
		return first.weight > second.weight;
	}
};

struct Edge {
    int source, destination;
    double weight;

    Edge(int source, int destination, double weight) {
        this->source = source;
        this->destination = destination;
        this->weight = weight;
    }
};

class Graph {
    int vertices, edges;
    vector<vector<int>> adjacencyList;

public:
    Graph();
    Graph(int, int);
    int getVertices();
    vector<int> getNeighboursOf(int);
    void addEdge(int, int);
    void printGraph();

    // member functions
    void dfs_recursive(int, vector<bool>&);
    void dfs(int);
    void bfs(int);
};

Graph::Graph() {
    // do nothing
}

Graph::Graph(int vertices, int edges) {
    this->vertices = vertices;
    this->edges = edges;
    this->adjacencyList.resize(vertices);
}

int Graph::getVertices() {
    return this->vertices;
}

vector<int> Graph::getNeighboursOf(int vertex) {
    return this->adjacencyList[vertex];
}

void Graph::addEdge(int source, int destination) {
    adjacencyList[source].push_back(destination);
}

void Graph::printGraph() {
    for (int i = 0; i < vertices; i++) {
        cout << i << " -> ";

        for (int j : adjacencyList[i]) {
            cout << j << " -> ";
        }

        cout << "NULL\n";
    }
    cout << "\n";
}

Graph createNewGraph(char* filename) {
    FILE* input = freopen(filename, "r", stdin);

    int vertices, edges, source, destination;
    cin >> vertices >> edges;

    Graph graph(vertices, edges);

    for (int i = 0; i < edges; i++) {
        cin >> source >> destination;
        graph.addEdge(source, destination);
    }

    fclose(input);

    return graph;
}

// member functions
void Graph::dfs_recursive(int vertex, vector<bool> &visited) {
    cout << vertex << " ";
    visited[vertex] = true;

    vector<int> neighbours = getNeighboursOf(vertex);

    for (int neighbour : neighbours) {
        if (visited[neighbour]) {
            continue;
        }

        dfs_recursive(neighbour, visited);
    }
}

void Graph::dfs(int vertex) {
    stack<int> s;
    s.push(vertex);

    vector<bool> visited(getVertices(), false);

    while (!s.empty()) {
        int current = s.top();
        s.pop();

        if (visited[current]) {
            continue;
        }

        cout << current << " ";
        visited[current] = true;
    
        vector<int> neighbours = getNeighboursOf(current);

        for (int neighbour : neighbours) {
            if (!visited[neighbour]) {
                s.push(neighbour);
            }
        }
    }
}

void Graph::bfs(int vertex) {
    queue<int> q;
    q.push(vertex);

    vector<bool> visited(getVertices(), false);

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        if (visited[current]) {
            continue;
        }

        cout << current << " ";
        visited[current] = true;
    
        vector<int> neighbours = getNeighboursOf(current);

        for (int neighbour : neighbours) {
            if (!visited[neighbour]) {
                q.push(neighbour);
            }
        }
    }
}


