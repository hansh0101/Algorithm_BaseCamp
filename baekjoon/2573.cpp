#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int n, m;
pair<int, int> arr[300][300];
bool visit[300][300]; // 녹은 걸로 계산했는지
bool check[300][300]; // bfs 시 방문 여부
queue<pair<int, int>> q;
int mr[4] = {1, 0, -1, 0};
int mc[4] = {0, 1, 0, -1};
int result;

void bfs() {
    while (!q.empty()) {
        int curr = q.front().first;
        int curc = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = curr + mr[i];
            int nc = curc + mc[i];

            if (nr < 0 || nr >= n || nc < 0 || nc >= m) {
                continue;
            }

            if (arr[nr][nc].second > 0 && !check[nr][nc]) {
                q.push({nr, nc});
                check[nr][nc] = true;
            }
        }
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j].second;
            arr[i][j].first = arr[i][j].second;
        }
    }

    while (true) {
        int bfsCnt = 0;
        memset(visit, false, sizeof(visit));
        memset(check, false, sizeof(check));

        result++;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (arr[i][j].second != 0) {
                    arr[i][j].first = arr[i][j].second;
                    int cnt = 0;
                    for (int k = 0; k < 4; k++) {
                        int nr = i + mr[k];
                        int nc = j + mc[k];
                        if (nr < 0 || nr >= n || nc < 0 || nc >= m) {
                            continue;
                        }
                        if (visit[nr][nc]) {
                            if (arr[nr][nc].first == 0) {
                                cnt++;
                            }
                        } else {
                            if (arr[nr][nc].second == 0) {
                                cnt++;
                            }
                        }
                    }
                    arr[i][j].second -= cnt;
                    if (arr[i][j].second < 0) {
                        arr[i][j].second = 0;

                    visit[i][j] = true;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (arr[i][j].second != 0 && !check[i][j]) {
                    q.push({i, j});
                    bfs();
                    bfsCnt++;
                }
            }
        }

        if (bfsCnt >= 2) {
            cout << result << "\n";
            break;
        } else if (bfsCnt == 0) {
            cout << "0\n";
            break;
        }
    }
}