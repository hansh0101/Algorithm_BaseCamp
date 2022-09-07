#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int w, h;
int arr[50][50];
bool visit[50][50];
queue<pair<int, int>> q;
int result = 0;
int mw[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int mh[8] = {0, -1, -1, -1, 0, 1, 1, 1};

void bfs() {
    while (!q.empty()) {
        int curh = q.front().first;
        int curw = q.front().second;
        q.pop();

        for (int i = 0; i < 8; i++) {
            int nh = curh + mh[i];
            int nw = curw + mw[i];

            if (nh < 0 || nw < 0 || nh >= h || nw >= w) {
                continue;
            }
            if (arr[nh][nw] == 1 && !visit[nh][nw]) {
                q.push({nh, nw});
                visit[nh][nw] = true;
            }
        }
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    while (true) {
        cin >> w >> h;
        if (w == 0 && h == 0) {
            break;
        }

        memset(arr, 0, sizeof(arr));
        memset(visit, false, sizeof(visit));
        result = 0;

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cin >> arr[i][j];
            }
        }

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (arr[i][j] == 1 && !visit[i][j]) {
                    q.push({i, j});
                    visit[i][j] = true;
                    bfs();
                    result++;
                }
            }
        }

        cout << result << "\n";
    }
    return 0;
}