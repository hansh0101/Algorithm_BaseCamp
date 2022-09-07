#include <iostream>
#include <queue>
#include <string.h>

#define pii pair<int, int>
using namespace std;

int t, m, n, k;
int arr[51][51];
bool visit[51][51];
queue<pii > q;
int mx[4] = {1, 0, -1, 0};
int my[4] = {0, 1, 0, -1};
int cnt;

void bfs(int x, int y) {
    q.push({x, y});
    visit[y][x] = true;

    while (!q.empty()) {
        int curx = q.front().first;
        int cury = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = curx + mx[i];
            int ny = cury + my[i];

            if (nx < 0 || ny < 0 || nx > m - 1 || ny > n - 1) {
                continue;
            }

            if (arr[ny][nx] == 1 && !visit[ny][nx]) {
                q.push({nx, ny});
                visit[ny][nx] = true;
            }
        }
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> t;
    while (t--) {
        memset(arr, 0, sizeof(arr));
        memset(visit, false, sizeof(visit));
        cnt = 0;

        cin >> m >> n >> k;
        for (int i = 0; i < k; i++) {
            int x = 0, y = 0;
            cin >> x >> y;
            arr[y][x] = 1;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (arr[i][j] == 1 && !visit[i][j]) {
                    bfs(j, i);
                    cnt++;
                }
            }
        }

        cout << cnt << "\n";
    }
    return 0;
}