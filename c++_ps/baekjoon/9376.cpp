#include <iostream>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;

int t, h, w;
char arr[102][102];
int visit[102][102][3];
priority_queue<pair<int, pair<int, int>>> pq;
int mx[4] = {1, 0, -1, 0};
int my[4] = {0, 1, 0, -1};
pair<int, int> start[3];

void solution() {
    for (int i = 0; i < 3; i++) {
        pq.push({0, {start[i].first, start[i].second}});
        visit[start[i].first][start[i].second][i] = 0;

        while (!pq.empty()) {
            int curcnt = -pq.top().first;
            int cury = pq.top().second.first;
            int curx = pq.top().second.second;
            pq.pop();

            for (int j = 0; j < 4; j++) {
                int nx = curx + mx[j];
                int ny = cury + my[j];

                if (arr[ny][nx] == '*' || nx < 0 || ny < 0 || nx > w + 1 || ny > h + 1) {
                    continue;
                }

                if (visit[ny][nx][i] == -1) {
                    if (arr[ny][nx] == '#') {
                        pq.push({-(curcnt+1), {ny,nx}});
                        visit[ny][nx][i] = curcnt+1;
                    }
                    else {
                        pq.push({-curcnt, {ny, nx}});
                        visit[ny][nx][i] = curcnt;
                    }
                }
            }
        }
    }

    int ans = 1e9;
    for (int i = 0; i <= h+1; i++) {
        for (int j = 0; j <= w+1; j++) {
            if (visit[i][j][0] != -1 && visit[i][j][1] != -1 && visit[i][j][2] != -1) {
                int tmp = visit[i][j][0] + visit[i][j][1] + visit[i][j][2];
                if(arr[i][j] == '#') {
                    tmp-=2;
                }
                ans = min(ans, tmp);
            }
        }
    }
    cout<<ans<<"\n";
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> t;
    while (t--) {
        for (int i = 0; i < 102; i++) {
            for (int j = 0; j < 102; j++) {
                arr[i][j] = '.';
            }
        }
        memset(visit, -1, sizeof(visit));

        cin >> h >> w;
        int num = 1;
        for (int i = 1; i <= h; i++) {
            string str;
            cin >> str;
            for (int j = 1; j <= w; j++) {
                arr[i][j] = str[j - 1];
                if (str[j - 1] == '$') {
                    start[num++] = {i, j};
                }
            }
        }

        solution();
    }
}