#include <iostream>
#include <queue>
using namespace std;

int f, s, g, u, d;
queue<pair<int, int>> q;
bool visited[1000001];
int result = -1;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> f >> s >> g >> u >> d;

    q.push({s, 0});
    visited[s] = true;

    while (!q.empty()) {
        int curPos = q.front().first;
        int curCnt = q.front().second;
        q.pop();

        if (curPos == g) {
            result = curCnt;
            break;
        }

        int upPos = curPos + u;
        if (upPos <= f && !visited[upPos]) {
            q.push({upPos, curCnt + 1});
            visited[upPos] = true;
        }
        int downPos = curPos - d;
        if (downPos >= 1 && !visited[downPos]) {
            q.push({downPos, curCnt + 1});
            visited[downPos] = true;
        }
    }

    if (result == -1) {
        cout << "use the stairs\n";
    } else {
        cout << result << "\n";
    }

    return 0;
}