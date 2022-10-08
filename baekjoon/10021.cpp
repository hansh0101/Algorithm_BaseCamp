#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, C;
int x, y;
vector<pair<int, int>> nodes;
vector<pair<int, pair<int, int>>> edges;
int p[2001];
long long result;

int Find(int v) {
    if (v == p[v]) return p[v];
    return p[v] = Find(p[v]);
}

void Union(int v1, int v2) {
    int v1Root = Find(v1);
    int v2Root = Find(v2);
    p[v1Root] = v2Root;
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> N >> C;
    for (int i = 0; i < N; i++) {
        cin >> x >> y;
        nodes.push_back({x, y});
        for (int j = 0; j < i; j++) {
            int xx = nodes[j].first;
            int yy = nodes[j].second;

            int cost = (xx - x) * (xx - x) + (yy - y) * (yy - y);
            if (cost >= C) {
                edges.push_back({cost, {min(i, j), max(i, j)}});
            }
        }
    }
    sort(edges.begin(), edges.end());

    for (int i = 1; i <= N; i++) {
        p[i] = i;
    }

    int count = 0;
    for (int i = 0; i < edges.size(); i++) {
        int cost = edges[i].first;
        int v1 = edges[i].second.first;
        int v2 = edges[i].second.second;

        if (Find(v1) != Find(v2)) {
            Union(v1, v2);
            count++;
            result += cost;
        }
    }

    cout << (count == N - 1 ? result : -1) << "\n";
    return 0;
}