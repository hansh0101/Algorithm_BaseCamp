#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int N, Q;
int p, q, r;
int k, v;
vector<pair<int, int>> vec[50001];
queue<int> que;
bool visit[50001];

int bfs() {
    int result = -1;
    while(!que.empty()) {
        int cur = que.front();
        que.pop();
        result++;

        for (int i = 0 ; i < vec[cur].size(); i++) {
            int nxt = vec[cur][i].first;
            int nxtK = vec[cur][i].second;

            if (nxtK < k) continue;
            if (!visit[nxt]) {
                que.push(nxt);
                visit[nxt] = true;
            }
        }
    }
    return result;
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> N >> Q;
    for (int i = 0; i < N - 1; i++) {
        cin >> p >> q >> r;
        vec[p].emplace_back(q, r);
        vec[q].emplace_back(p, r);
    }
    for (int i = 0 ; i < Q; i++) {
        memset(visit, false, sizeof(visit));
        cin >> k >> v;
        visit[v] = true;
        que.push(v);
        cout << bfs() << "\n";
    }
    return 0;
}