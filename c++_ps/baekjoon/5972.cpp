#include <iostream>
#include <vector>
#include <queue>
#define INF 1e9

using namespace std;

int n, m;
int a, b, c;
vector<pair<int, int>> vec[50001];
priority_queue<pair<int, int>> pq;
int dist[50001];

void getInput();
void solve();
void printResult();

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    getInput();
    solve();
    printResult();
}

void getInput() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        vec[a].push_back({c, b});
        vec[b].push_back({c, a});
    }
}

void solve() {
    for (int i = 1; i <= n; i++) {
        dist[i] = INF;
    }
    dist[1] = 0;
    pq.push({-dist[1], 1});

    while (!pq.empty()) {
        pair<int, int> p = pq.top();
        pq.pop();
        int cur = p.second;
        int curDist = -p.first;

        for (int i = 0; i < vec[cur].size(); i++) {
            int nxt = vec[cur][i].second;
            int nxtDist = vec[cur][i].first;

            if (dist[nxt] > curDist + nxtDist) {
                dist[nxt] = curDist + nxtDist;
                pq.push({-dist[nxt], nxt});
            }
        }
    }
}

void printResult() {
    cout << dist[n] << "\n";
}