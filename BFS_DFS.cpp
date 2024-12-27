#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

class Graph {
    int V; // Number of vertices
    vector<vector<int>> adj; // Adjacency list

public:
    Graph(int V);
    void addEdge(int v, int w);
    void BFS(int s);
    void DFS(int s);
    void DFSUtil(int s, vector<bool>& visited);
};

Graph::Graph(int V) {
    this->V = V;
    adj.resize(V);
}

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w);
}

void Graph::BFS(int s) {
    vector<bool> visited(V, false);
    queue<int> q;

    visited[s] = true;
    q.push(s);

    while (!q.empty()) {
        s = q.front();
        cout << s << " ";
        q.pop();

        for (auto i : adj[s]) {
            if (!visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }
}

void Graph::DFSUtil(int s, vector<bool>& visited) {
    visited[s] = true;
    cout << s << " ";

    for (auto i : adj[s]) {
        if (!visited[i]) {
            DFSUtil(i, visited);
        }
    }
}

void Graph::DFS(int s) {
    vector<bool> visited(V, false);
    DFSUtil(s, visited);
}

int main() {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout << "BFS starting from vertex 2:\n";
    g.BFS(2);

    cout << "\nDFS starting from vertex 2:\n";
    g.DFS(2);

    return 0;
}
