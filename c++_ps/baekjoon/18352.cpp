#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

int n, m, k, x;
int a, b;
vector<int> graph[300001];
queue<pair<int, int>> q;
bool visited[300001];
vector<int> result;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m >> k >> x;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        graph[a].push_back(b);
    }

    q.push({x, 0});
    visited[x] = true;
    while (!q.empty()) {
        int curPos = q.front().first;
        int curCost = q.front().second;
        q.pop();

        if (curCost == k) {
            result.push_back(curPos);
            continue;
        }

        for (int i = 0; i < graph[curPos].size(); i++) {
            int nextPos = graph[curPos][i];
            int nextCost = curCost + 1;

            if (!visited[nextPos]) {
                q.push({nextPos, nextCost});
                visited[nextPos] = true;
            }
        }
    }

    sort(result.begin(), result.end());
    if (result.empty()) {
        result.push_back(-1);
    }
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << "\n";
    }

    return 0;
}