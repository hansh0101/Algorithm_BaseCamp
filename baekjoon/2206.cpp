#include <iostream>
#include <cstring>
#include <limits.h>
#include <queue>

using namespace std;

int n, m;
string str;
int arr[1000][1000];
bool visit[1000][1000][2];
queue<pair<pair<int, int>, pair<int, int>>> q;
int mr[4] = {0, 1, 0, -1};
int mc[4] = {1, 0, -1, 0};

int bfs() {
    int result = INT_MAX;
    while (!q.empty()) {
        int curr = q.front().first.first;
        int curc = q.front().first.second;
        int curw = q.front().second.first;
        int curcnt = q.front().second.second;
        q.pop();

        if (curr == n - 1 && curc == m - 1) {
            result = min(result, curcnt);
        }

        for (int i = 0; i < 4; i++) {
            int nr = curr + mr[i];
            int nc = curc + mc[i];
            int ncnt = curcnt + 1;

            if (nr < 0 || nc < 0 || nr >= n || nc >= m) {
                continue;
            }

            if (arr[nr][nc] == 1 && !visit[nr][nc][curw] && curw < 1) {
                q.push({{nr, nc},{curw + 1, ncnt}});
                visit[nr][nc][curw] = true;
            } else if (arr[nr][nc] == 0 && !visit[nr][nc][curw]) {
                q.push({{nr,   nc},{curw, ncnt}});
                visit[nr][nc][curw] = true;
            }
        }
    }
    return (result == INT_MAX ? -1 : result);
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> str;
        for (int j = 0; j < m; j++) {
            arr[i][j] = str[j] - '0';
        }
    }

    q.push({{0, 0},{0, 1}});
    visit[0][0][0] = true;
    cout << bfs() << "\n";
    return 0;
}