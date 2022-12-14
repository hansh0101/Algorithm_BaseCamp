#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int t, n, m, h, u, v;
vector<pair<int, int>> height;
vector<pair<int, int>> graph[1000];
bool visit[1000];

void init() {
    height.clear();
    for (int i = 0; i < 1000; i++) {
        graph[i].clear();
    }
    memset(visit, false, sizeof(visit));
}

void dfs(int cur) {
    visit[cur] = true;
    cout << cur << "\n";

    for (int i = 0; i < graph[cur].size(); i++) {
        int next = graph[cur][i].second;
        if (!visit[next]) {
            dfs(next);
        }
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> t;
    while (t--) {
        init();

        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            cin >> h;
            height.push_back({h, i});
        }
        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            graph[u].push_back({height[v].first, v});
            graph[v].push_back({height[u].first, u});
        }
        sort(height.begin(), height.end());
        for (int i = 0; i < n; i++) {
            sort(graph[i].begin(), graph[i].end());
        }

        for (int i = 0; i < n; i++) {
            if (!visit[height[i].second]) {
                dfs(height[i].second);
            }
        }
    }
}