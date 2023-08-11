#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m, k;
int r, c;
char arr[101][101];
bool visited[101][101];
int mr[4] = {1, 0, -1, 0};
int mc[4] = {0, 1, 0, -1};
int result;

struct QueueElement {
    int r;
    int c;

    QueueElement(int r, int c) {
        this->r = r;
        this->c = c;
    }
};

void bfs(int r, int c) {
    int count = 0;

    queue<QueueElement> q;
    q.push(QueueElement(r, c));
    visited[r][c] = true;
    while (!q.empty()) {
        QueueElement elem = q.front();
        q.pop();

        count++;

        for (int i = 0; i < 4; i++) {
            int nr = elem.r + mr[i];
            int nc = elem.c + mc[i];

            if (nr < 1 || nc < 1 || nr > n || nc > m) {
                continue;
            }

            if (!visited[nr][nc] && arr[nr][nc] == '#') {
                q.push(QueueElement(nr, nc));
                visited[nr][nc] = true;
            }
        }
    }

    result = max(result, count);
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            arr[i][j] = '.';
        }
    }

    for (int i = 0; i < k; i++) {
        cin >> r >> c;
        arr[r][c] = '#';
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (arr[i][j] == '#' && !visited[i][j]) {
                bfs(i, j);
            }
        }
    }

    cout << result << "\n";
    return 0;
}