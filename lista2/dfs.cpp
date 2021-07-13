#include <iostream>
#include <vector>

typedef std::vector<std::vector<int>> matrix;

void printMatrix(matrix& m){
    int n = m.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << m[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void nextNode(int u, matrix& adj, std::vector<bool>& visited){
    visited[u] = true;
    std::cout << u << " ";
    for (int i=0; i<adj[u].size(); i++)
        if (!visited[adj[u][i]])
            nextNode(adj[u][i], adj, visited);
}

void DFS(matrix& adj, int V){
    std::vector<bool> visited(adj.size(), false);
    for (int u=0; u<adj.size(); u++)
        if (!visited[u])
            nextNode(u, adj, visited);
}


int main(){
    int V = 4;
    matrix adj = {
            {1, 4, 0, 0},
            {0, 2, 3, 4},
            {1, 3, 0, 0},
            {1, 2, 4, 0}
    };
    printMatrix(adj);
    DFS(adj, V);
    return 0;
}