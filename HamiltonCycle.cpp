//C++ 
#include <bits/stdc++.h>
using namespace std;

bool isHamiltonian(int pos, int n, vector<vector<int>> adj, vector<int> path, vector<bool> visited) {
    if (pos == n) return adj[path[pos - 1]][path[0]];
    for (int v = 1; v < n; v++) {
        if (!visited[v] && adj[path[pos - 1]][v]) {
            visited[v] = true; 
            path[pos] = v;
            if (isHamiltonian(pos + 1, n, adj, path, visited)) return true;
            visited[v] = false; 
        }
    }
    return false;
}

int main() {
    int T;
    cin >> T;

    for(int i = 0; i < T; i++) {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> adj(n, vector<int>(n, 0)); 
        for (int i = 0; i < m; ++i) {
            int u, v;
            cin >> u >> v;
            adj[u - 1][v - 1] = adj[v - 1][u - 1] = 1; 
        }

        vector<int> path(n);
        vector<bool> visited(n, false);
        path[0] = 0; 
        visited[0] = true;

        cout << (isHamiltonian(1, n, adj, path, visited) ? 1 : 0) << endl; 
    }

    return 0;
}
