
#include <iostream>
#include <stack>
#include <queue>
using namespace std;

class Graph {
    int n;
    int adj[10][10];

public:
    Graph(int vertices) {
        n = vertices;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                adj[i][j] = 0;
            }
        }
    }

    void addEdge(int u, int v) {
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    void DFS(int start) {
        int visited[10] = {0};
        stack<int> s;

        s.push(start);

        cout << "DFS Traversal: ";

        while (!s.empty()) {
            int node = s.top();
            s.pop();

            if (!visited[node]) {
                visited[node] = 1;
                cout << node << " ";

               
                for (int i = n - 1; i >= 0; i--) {
                    if (adj[node][i] == 1 && !visited[i]) {
                        s.push(i);
                    }
                }
            }
        }
        cout << endl;
    }

    void BFS(int start) {
        int visited[10] = {0};
        queue<int> q;

        visited[start] = 1;
        q.push(start);

        cout << "BFS Traversal: ";

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            cout << node << " ";

            for (int i = 0; i < n; i++) {
                if (adj[node][i] == 1 && !visited[i]) {
                    visited[i] = 1;
                    q.push(i);
                }
            }
        }
        cout << endl;
    }
};

int main() {
    Graph g(6);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5);
    g.addEdge(4, 5);

    g.DFS(0);
    g.BFS(0);

    return 0;
}
