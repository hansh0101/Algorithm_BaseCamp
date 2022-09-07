#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

vector<int> vec[101];

void bfs(int s, int d) {
    queue<pair<int, int>> q; // first: 정점 번호 / second: 거리

    bool visit[101];
    for (int i = 0; i < 101; i++) {
        visit[i] = false;
    }

    visit[s] = true;
    q.push({s, 0});

    while (!q.empty()) {
        int cur = q.front().first;
        int curDist = q.front().second;
        q.pop(); // q.pop() 꼭 해야됨

        if (cur == d) {
            cout << curDist << "\n";
            return;
        }

        for (int i = 0; i < vec[cur].size(); i++) {
            int next = vec[cur][i];
            int nextDist = curDist + 1;

            if (!visit[next]) {
                visit[next] = true;
                q.push({next, nextDist});
            }
        }
    }
    cout << "0\n";
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;

        for (int i = 0; i < m; i++) {
            int s, d;
            cin >> s >> d;

            vec[s].push_back(d);
            vec[d].push_back(s);
        }

        for (int i = 0; i < k; i++) {
            int s, d;
            cin >> s >> d;
            bfs(s, d);
        }

        for (int i = 0; i < 101; i++) {
            vec[i].clear();
        }
    }

    return 0;
}