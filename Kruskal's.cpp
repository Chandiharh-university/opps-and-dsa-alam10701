#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Edge {
public:
    int src, dest, weight;
};

class Graph {
    int V, E;
    vector<Edge> edges;

public:
    Graph(int V, int E);
    void addEdge(int u, int v, int w);
    int find(vector<int>& parent, int i);
    void Union(vector<int>& parent, vector<int>& rank, int x, int y);
    void KruskalMST();
};

Graph::Graph(int V, int E) {
    this->V = V;
    this->E = E;
}

void Graph::addEdge(int u, int v, int w) {
    edges.push_back({u, v, w});
}

int Graph::find(vector<int>& parent, int i) {
    if (parent[i] != i)
        parent[i] = find(parent, parent[i]);
    return parent[i];
}

void Graph::Union(vector<int>& parent, vector<int>& rank, int x, int y) {
    int xroot = find(parent, x);
    int yroot = find(parent, y);

    if (rank[xroot] < rank[yroot])
        parent[xroot] = yroot;
    else if (rank[xroot] > rank[yroot])
        parent[yroot] = xroot;
    else {
        parent[yroot] = xroot;
        rank[xroot]++;
    }
}

void Graph::KruskalMST() {
    sort(edges.begin(), edges.end(), [](Edge a, Edge b) {
        return a.weight < b.weight;
    });

    vector<int> parent(V);
    vector<int> rank(V, 0);
    for (int i = 0; i < V; ++i)
        parent[i] = i;

    vector<Edge> result;
    int e = 0;
    int i = 0;

    while (e < V - 1 && i < E) {
        Edge next_edge = edges[i++];
        int x = find(parent, next_edge.src);
        int y = find(parent, next_edge.dest);

        if (x != y) {
            result.push_back(next_edge);
            Union(parent, rank, x, y);
            e++;
        }
    }

    cout << "Edge \tWeight\n";
    for (auto edge : result)
        cout << edge.src << " - " << edge.dest << "\t" << edge.weight << "\n";
}

int main() {
    int V = 4;
    int E = 5;
    Graph g(V, E);

    g.addEdge(0, 1, 10);
    g.addEdge(0, 2, 6);
    g.addEdge(0, 3, 5);
    g.addEdge(1, 3, 15);
    g.addEdge(2, 3, 4);

    g.KruskalMST();

    return 0;
}
