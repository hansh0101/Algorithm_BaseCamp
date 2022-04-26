#include <iostream>
#include <queue>

using namespace std;

int n, m;
int arr[50][50];
int r, c, d;
int result;

int mr[4] = {-1, 0, 1, 0};
int mc[4] = {0, -1, 0, 1};
bool visit[50][50];
queue<pair<pair<int, int>, int>> q;

void clean() {
    while (!q.empty()) {
        int curr = q.front().first.first;
        int curc = q.front().first.second;
        int curd = q.front().second;

        // my test
//        cout << curr << "," << curc << "\n";

        q.pop();
        if(!visit[curr][curc]) {
            visit[curr][curc] = true;
            result++;
        }

        bool skip = true;
        for (int i = 0; i < 4; i++) {
            int nd = (curd + 1 + i) % 4;
            int nr = curr + mr[nd];
            int nc = curc + mc[nd];

            if (nr < 0 || nc < 0 || nr >= n || nc >= m) {
                continue;
            }
            if (arr[nr][nc] == 1) {
                continue;
            }

            if (!visit[nr][nc]) {
                skip = false;
                q.push({{nr, nc}, nd});
                break;
            }
        }

        if (skip) {
            int nd = (curd + 2) % 4;
            int nr = curr + mr[nd];
            int nc = curc + mc[nd];

            if (arr[nr][nc] != 1) {
                q.push({{nr, nc}, curd});
            } else {
                break;
            }
        }
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    cin >> r >> c >> d;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    if (d == 1) {
        d = 3;
    } else if (d == 3) {
        d = 1;
    }
    q.push({{r, c}, d});
    clean();
    cout << result;
    return 0;
}