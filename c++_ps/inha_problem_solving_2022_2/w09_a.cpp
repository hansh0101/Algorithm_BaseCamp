#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int t, n, m, k, h, u, v;
int minHeight, startIndex;
vector<int> graph[1000];
queue<pair<int, int>> q;
int cost[1000];

void init() {
    minHeight = 1e9 + 1, startIndex = -1;
    for (int i = 0; i < 1000; i++) {
        graph[i].clear();
        cost[i] = -1;
    }
    while (!q.empty()) {
        q.pop();
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> t;
    while (t--) {
        init();

        cin >> n >> m >> k;
        for (int i = 0; i < n; i++) {
            cin >> h;
            if (minHeight > h) {
                minHeight = h;
                startIndex = i;
            }
        }

        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        cost[startIndex] = 0;
        q.push({startIndex, cost[startIndex]});
        while (!q.empty()) {
            int curIndex = q.front().first;
            int curCost = q.front().second;
            q.pop();

            for (int i = 0; i < graph[curIndex].size(); i++) {
                int nextIndex = graph[curIndex][i];
                int nextCost = curCost + 1;

                if (cost[nextIndex] == -1) {
                    cost[nextIndex] = nextCost;
                    q.push({nextIndex, nextCost});
                }
            }
        }

        for (int i = 0; i < k; i++) {
            cin >> u;
            cout << cost[u] << "\n";
        }
    }
}