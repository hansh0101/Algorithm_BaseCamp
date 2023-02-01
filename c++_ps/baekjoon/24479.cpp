#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, r, u, v;
vector<int> graph[100001];
bool check[100001];
int cnt;
int order[100001];

void dfs(int cur) {
    check[cur] = true;
    order[cur] = ++cnt;
    sort(graph[cur].begin(), graph[cur].end());

    for (int i = 0; i < graph[cur].size(); i++) {
        int nxt = graph[cur][i];
        if (!check[nxt]) {
            dfs(nxt);
        }
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m >> r;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    dfs(r);

    for (int i = 1; i <= n; i++) {
        cout << order[i] << "\n";
    }
}