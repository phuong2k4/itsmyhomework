#include <bits/stdc++.h>
using namespace std;

#define INF 1e9

struct Edge {
    int u, v, w; // u -> v có trọng số w
};

vector<int> bellman_ford(int n, int start, vector<Edge>& edges) {
    vector<int> dist(n, INF);
    dist[start] = 0;

    // Lặp (n-1) lần để thư giãn các cạnh
    for (int i = 0; i < n - 1; i++) {
        for (const Edge& edge : edges) {
            if (dist[edge.u] != INF && dist[edge.u] + edge.w < dist[edge.v]) {
                dist[edge.v] = dist[edge.u] + edge.w;
            }
        }
    }

    // Kiểm tra chu trình âm
    for (const Edge& edge : edges) {
        if (dist[edge.u] != INF && dist[edge.u] + edge.w < dist[edge.v]) {
            cout << "Đồ thị có chu trình âm!\n";
            return {}; // Trả về rỗng nếu có chu trình âm
        }
    }
    return dist;
}