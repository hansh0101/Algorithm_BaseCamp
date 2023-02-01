#include <iostream>
#include <cstring>
using namespace std;

int n;
int arr[10][10];
bool visited[10];
int result = 1e9;

void dfs(int start, int cur, int sum, int dfsCount) {
    if (dfsCount == n + 1 && cur == start) {
        result = min(result, sum);
        return;
    }

    for (int i = 0; i < n; i++) {
        if (dfsCount < n && i == start) {
            continue;
        }

        if (arr[cur][i] != 0 && !visited[i]) {
            if (sum + arr[cur][i] > result) {
                continue;
            }
            visited[i] = true;
            dfs(start, i, sum + arr[cur][i], dfsCount + 1);
            visited[i] = false;
        }
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    for(int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        memset(visited, false, sizeof(visited));
        dfs(i, i, 0, 1);
    }

    cout << result << "\n";
}