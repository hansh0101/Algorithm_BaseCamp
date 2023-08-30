#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

struct Position {
    int r;
    int c;
    int count;

    Position(int r, int c, int count) {
        this->r = r;
        this->c = c;
        this->count = count;
    }
};

int n, m;
int arr[1000][1000];
queue<Position> q;
bool visited[1000][1000];
int mr[4] = {1, 0, -1, 0};
int mc[4] = {0, 1, 0, -1};
int result[1000][1000];

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 1) {
                result[i][j] = -1;
            } else if (arr[i][j] == 0) {
                result[i][j] = 0;
            } else if (arr[i][j] == 2) {
                q.push(Position(i, j, 0));
                visited[i][j] = true;
            }
        }
    }

    while (!q.empty()) {
        Position p = q.front();
        q.pop();

        int curr = p.r;
        int curc = p.c;
        int curCount = p.count;

        result[curr][curc] = curCount;

        for (int i = 0; i < 4; i++) {
            int nr = curr + mr[i];
            int nc = curc + mc[i];
            int nCount = curCount + 1;

            if (nr < 0 || nr >= n || nc < 0 || nc >= m) {
                continue;
            }

            if (arr[nr][nc] != 0 && !visited[nr][nc]) {
                q.push(Position(nr, nc, nCount));
                visited[nr][nc] = true;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << result[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}