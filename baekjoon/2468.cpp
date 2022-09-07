#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int n;
int arr[100][100];
bool visit[100][100];
queue<pair<int, int>> q;
int result = 0;
int mr[4] = {0, -1, 0, 1};
int mc[4] = {1, 0, -1, 0};

void bfs(int h) {
    while (!q.empty()) {
        int curr = q.front().first;
        int curc = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = curr + mr[i];
            int nc = curc + mc[i];

            if (nr < 0 || nc < 0 || nr >= n || nc >= n) {
                continue;
            }
            if (arr[nr][nc] > h && !visit[nr][nc]) {
                q.push({nr, nc});
                visit[nr][nc] = true;
            }
        }
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    for (int h = 0; h <= 100; h++) {
        memset(visit, false, sizeof(visit));

        int tmpResult = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (arr[i][j] > h && !visit[i][j]) {
                    q.push({i, j});
                    visit[i][j] = true;
                    bfs(h);
                    tmpResult++;
                }
            }
        }

        result = tmpResult > result ? tmpResult : result;
    }

    cout << result << "\n";
    return 0;
}