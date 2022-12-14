#include <iostream>
#include <cstring>
#include <limits.h>
#include <queue>

using namespace std;

int t, l;
int sr, sc, er, ec;
int visit[300][300];
int result;
queue<pair<pair<int, int>, int>> q;
int mr[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
int mc[8] = {2, 1, -1, -2, -2, -1, 1, 2};

void bfs() {
    while (!q.empty()) {
        int curr = q.front().first.first;
        int curc = q.front().first.second;
        int curCount = q.front().second;
        if (curr == er && curc == ec) {
            result = curCount < result ? curCount : result;
            q.pop();
            continue;
        }
        q.pop();

        for (int i = 0; i < 8; i++) {
            int nr = curr + mr[i];
            int nc = curc + mc[i];

            if (nr < 0 || nc < 0 || nr >= l || nc >= l) {
                continue;
            }
            if (!visit[nr][nc]) {
                q.push({{nr, nc}, curCount + 1});
                visit[nr][nc] = true;
            }
        }
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> t;
    while (t--) {
        memset(visit, false, sizeof(visit));
        result = INT_MAX;
        cin >> l;
        cin >> sr >> sc >> er >> ec;
        q.push({{sr, sc}, 0});
        visit[sr][sc] = true;
        bfs();
        cout << result << "\n";
    }
    return 0;
}