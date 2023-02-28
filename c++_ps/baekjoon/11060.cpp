#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<int> vec = vector<int>(n);
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }

    queue<pair<int, int>> q;
    vector<bool> visited = vector<bool>(n, false);
    q.push({0, 0});
    visited[0] = true;

    int result = -1;
    while (!q.empty()) {
        int curPos = q.front().first;
        int curCnt = q.front().second;
        q.pop();

        if (curPos == n - 1) {
            result = curCnt;
            break;
        }

        int maxPos = vec[curPos];
        for (int i = 1; i <= maxPos; i++) {
            if (curPos + i >= n) {
                continue;
            }

            if (!visited[curPos + i]) {
                q.push({curPos + i, curCnt + 1});
                visited[curPos + i] = true;
            }
        }
    }

    cout << result << "\n";
    return 0;
}