#include <iostream>
#include <queue>

using namespace std;

int m, n, k;
int arr[100][100];
bool visit[100][100];
queue<pair<int, int>> q;
priority_queue<int, vector<int>, greater<>> pq;
int mr[4] = {0, 1, 0, -1};
int mc[4] = {1, 0, -1, 0};

void bfs() {
    int result = 0;
    while (!q.empty()) {
        int curr = q.front().first;
        int curc = q.front().second;
        result++;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = curr + mr[i];
            int nc = curc + mc[i];
            if (nr < 0 || nr >= m || nc < 0 || nc >= n) {
                continue;
            }

            if (arr[nr][nc] == 0 && !visit[nr][nc]) {
                q.push({nr, nc});
                visit[nr][nc] = true;
            }
        }
    }
    pq.push(result);
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> m >> n >> k;
    for (int i = 0; i < k; i++) {
        int ltc, ltr, rbc, rbr;
        cin >> ltc >> ltr >> rbc >> rbr;
        for (int r = ltr; r < rbr; r++) {
            for (int c = ltc; c < rbc; c++) {
                arr[r][c] = 1;
            }
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] == 0 && !visit[i][j]) {
                q.push({i, j});
                visit[i][j] = true;
                bfs();
            }
        }
    }

    cout << pq.size() << "\n";
    while (!pq.empty()) {
        cout << pq.top() << "\n";
        pq.pop();
    }

    return 0;
}