#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m, r, u, v;
vector<int> graph[100001];
bool visited[100001];
int cnt;
int order[100001];
queue<int> q;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m >> r;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    visited[r] = true;
    q.push(r);
    while (!q.empty()) {
        int cur = q.front();
        order[cur] = ++cnt;
        q.pop();

        sort(graph[cur].begin(), graph[cur].end(), greater<>());

        for (int i = 0; i < graph[cur].size(); i++) {
            int nxt = graph[cur][i];

            if (!visited[nxt]) {
                visited[nxt] = true;
                q.push(nxt);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << order[i] << "\n";
    }

    return 0;
}