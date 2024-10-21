//Find Minimum Spanning Tree
#include <iostream>
#include <vector>

using namespace std;

struct Edge { int u, v, w; };

int find(int u, int parent[]) {
    return (parent[u] == u) ? u : find(parent[u], parent);
}

void sortEdges(Edge edges[], int M) {
    for (int i = 0; i < M - 1; i++)
        for (int j = 0; j < M - i - 1; j++)
            if (edges[j].w > edges[j + 1].w)
                swap(edges[j], edges[j + 1]);
}

int main() {
    int N, M, mstWeight = 0;
    cin >> N >> M;
    Edge edges[M];
    for (int i = 0; i < M; i++)
        cin >> edges[i].u >> edges[i].v >> edges[i].w;

    int parent[N + 1];
    for (int i = 1; i <= N; i++)
        parent[i] = i;

    sortEdges(edges, M);

    for (int i = 0; i < M; i++) {
        int rootU = find(edges[i].u, parent);
        int rootV = find(edges[i].v, parent);
        if (rootU != rootV) {
            mstWeight += edges[i].w;
            parent[rootU] = rootV;  // Kết hợp hai tập hợp
        }
    }

    cout << mstWeight << endl;
    return 0;
}
