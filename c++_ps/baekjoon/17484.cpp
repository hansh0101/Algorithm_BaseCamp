#include <iostream>
#define INF 1e9

using namespace std;

int n, m;
int arr[6][6];
int memo[6][6][3];
int result = INF;

int mr[3] = {1, 1, 1};
int mc[3] = {-1, 0, 1};

bool isOut(int c) {
    return c < 0 || c >= m;
}

void dfs(int curr, int curc, int dir, int sum) {
    if (curr == n) {
        result = min(result, sum);
        return;
    }

    for (int i = 0; i < 3; i++) {
        if (dir == i) {
            continue;
        }

        int nr = curr + mr[i];
        int nc = curc + mc[i];

        if (isOut(nc)) {
            continue;
        }

        if (nr == n) {
            dfs(nr, nc, i, sum);
        } else {
            dfs(nr, nc, i, sum + arr[nr][nc]);
        }
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < m; i++) {
        dfs(0, i, -1, arr[0][i]);
    }

    cout << result << "\n";
    return 0;
}