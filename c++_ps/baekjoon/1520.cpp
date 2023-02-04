#include <iostream>
#include <cstring>

using namespace std;

int m, n;
int arr[500][500];
int dp[500][500];
bool visited[500][500];
int mr[4] = {0, 0, 1, -1};
int mc[4] = {1, -1, 0, 0};

bool isNotInRange(int r, int c) {
    if (r < 0 || r >= m || c < 0 || c >= n) {
        return true;
    }
    return false;
}

int dfs(int curr, int curc) {
    int result = 0;
    visited[curr][curc] = true;

    if (curr == m - 1 && curc == n - 1) {
        return ++result;
    }

    for (int i = 0; i < 4; i++) {
        int nr = curr + mr[i];
        int nc = curc + mc[i];

        if (isNotInRange(nr, nc)) {
            continue;
        }

        if (!visited[nr][nc] && arr[curr][curc] > arr[nr][nc]) {
            if (dp[nr][nc] == -1) {
                result += dfs(nr, nc);
                visited[nr][nc] = false;
            } else {
                result += dp[nr][nc];
            }
        }
    }

    return dp[curr][curc] = result;
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> m >> n;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    memset(dp, -1, sizeof(dp));
    cout << dfs(0, 0) << "\n";

    return 0;
}