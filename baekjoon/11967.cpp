#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

#define pii pair<int, int>
using namespace std;

int n, m;
int x, y, a, b;
int result;

vector<pii > switches[101][101];
bool arr[101][101];
queue<pii > q;
bool visit[101][101];
int mr[4] = {-1, 0, 1, 0};
int mc[4] = {0, -1, 0, 1};

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> x >> y >> a >> b;
        switches[x][y].emplace_back(a, b);
    }

    q.push({1, 1});
    visit[1][1] = true;
    arr[1][1] = true;
    result++;
    while (!q.empty()) {
        bool flag = false;
        int curr = q.front().first;
        int curc = q.front().second;
        q.pop();

        for (pii p: switches[curr][curc]) {
            int nr = p.first;
            int nc = p.second;
            if (!arr[nr][nc]) {
                arr[nr][nc] = true;
                result++;
                flag = true;
            }
        }
        switches[curr][curc].clear();

        if (flag) {
            memset(visit, false, sizeof(visit));
            visit[curr][curc] = true;
            while (!q.empty()) {
                q.pop();
            }
        }

        for (int i = 0; i < 4; i++) {
            int nr = curr + mr[i];
            int nc = curc + mc[i];
            if (nr < 1 || nr > n || nc < 1 || nc > n) {
                continue;
            }
            if (arr[nr][nc] && !visit[nr][nc]) {
                q.push({nr, nc});
                visit[nr][nc] = true;
            }
        }
    }

    cout << result << "\n";
    return 0;
}