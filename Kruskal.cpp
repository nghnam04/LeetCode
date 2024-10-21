#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int u, v, w;
};

// Tìm cha của một đỉnh với path compression
int find(int u, int parent[]) {
    if (parent[u] != u)
        parent[u] = find(parent[u], parent);  // Path compression
    return parent[u];
}

// Sắp xếp cạnh dựa trên trọng số
bool compare(Edge a, Edge b) {
    return a.w < b.w;
}

int main() {
    int N, M, mstWeight = 0;
    cin >> N >> M;
    vector<Edge> edges(M);
    for (int i = 0; i < M; i++)
        cin >> edges[i].u >> edges[i].v >> edges[i].w;

    int parent[N + 1];
    for (int i = 1; i <= N; i++)
        parent[i] = i;

    // Sắp xếp cạnh theo trọng số bằng sort() của C++
    sort(edges.begin(), edges.end(), compare);

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
