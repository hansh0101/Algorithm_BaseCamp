#include <string>
#include <vector>
#include <cstring>
#include <queue>

#define INF 1e9

using namespace std;

int mr[4] = {0, 1, 0, -1};
int mc[4] = {1, 0, -1, 0};

bool check(int r, int c, int rr, int cc) {
    if (r < 0 || c < 0 || r >= rr || c >= cc) return false;
    else return true;
}

vector<vector<int>> solution(vector<string> wall) {
    vector<vector<int>> answer;

    int arr[500][500];
    for (int i = 0; i < 500; i++) {
        for (int j = 0; j < 500; j++) {
            arr[i][j] = INF;
        }
    }

    int r = wall.size();
    int c = wall[0].length();

    queue<pair<pair<int, int>, int>> q;
    q.push({{r - 1, 0}, 1});
    arr[r - 1][0] = 1;

    while (!q.empty()) {
        int curr = q.front().first.first;
        int curc = q.front().first.second;
        int curcnt = q.front().second;
        q.pop();

        int nr, nc;
        // 0. 상하좌우
        for (int i = 0; i < 4; i++) {
            nr = curr + mr[i];
            nc = curc + mc[i];

            if (!check(nr, nc, r, c)) continue;
            if (wall[nr][nc] == 'H' && arr[nr][nc] > curcnt + 1) {
                q.push({{nr, nc}, curcnt + 1});
                arr[nr][nc] = curcnt + 1;
            }
        }

        // 1. 좌로 2칸
        nr = curr;
        nc = curc - 2;
        if (check(nr, nc, r, c)) {
            if (wall[nr][nc] == 'H' && wall[nr][nc + 1] == '.' && arr[nr][nc] > curcnt + 1) {
                if(nr -1 >= 0) {
                    bool flag = true;
                    for(int i = nc; i<=curc; i++) {
                        if(wall[nr-1][i] != '.') flag = false;
                    }
                    if(flag) {
                        q.push({{nr, nc}, curcnt + 1});
                        arr[nr][nc] = curcnt + 1;
                    }
                }
            }
        }

        // 2. 우로 2칸
        nr = curr;
        nc = curc + 2;
        if (check(nr, nc, r, c)) {
            if (wall[nr][nc] == 'H' && wall[nr][nc - 1] == '.' && arr[nr][nc] > curcnt + 1) {
                if (nr - 1 >= 0) {
                    bool flag = true;
                    for(int i = curc; i<=nc; i++) {
                        if(wall[nr-1][i] != '.') flag = false;
                    }
                    if(flag) {
                        q.push({{nr, nc}, curcnt + 1});
                        arr[nr][nc] = curcnt + 1;
                    }
                }
            }
        }

        // 3. 좌로 3칸
        nr = curr;
        nc = curc - 3;
        if (check(nr, nc, r, c)) {
            if (wall[nr][nc] == 'H' && wall[nr][nc + 1] == '.' && wall[nr][nc + 2] == '.' && arr[nr][nc] > curcnt + 1) {
                if (nr - 1 >= 0) {
                    bool flag = true;
                    for (int i = nc; i <= curc; i++) {
                        if (wall[nr - 1][i] != '.') flag = false;
                    }
                    if (flag) {
                        q.push({{nr, nc}, curcnt + 1});
                        arr[nr][nc] = curcnt + 1;
                    }
                }
            }
        }

        // 4. 우로 3칸
        nr = curr;
        nc = curc + 3;
        if (check(nr, nc, r, c)) {
            if (wall[nr][nc] == 'H' && wall[nr][nc - 1] == '.' && wall[nr][nc - 2] == '.' && arr[nr][nc] > curcnt + 1) {
                if (nr - 1 >= 0) {
                    bool flag = true;
                    for (int i = curc; i <= nc; i++) {
                        if (wall[nr - 1][i] != '.') flag = false;
                    }
                    if (flag) {
                        q.push({{nr, nc}, curcnt + 1});
                        arr[nr][nc] = curcnt + 1;
                    }
                }
            }
        }

        // 5. 위로 2칸
        nr = curr - 2;
        nc = curc;
        if (check(nr, nc, r, c)) {
            if (wall[nr][nc] == 'H' && wall[nr + 1][nc] == '.' && arr[nr][nc] > curcnt + 1) {
                q.push({{nr, nc}, curcnt + 1});
                arr[nr][nc] = curcnt + 1;
            }
        }

        // 6. 좌상단
        nr = curr - 1;
        nc = curc - 1;
        if (check(nr, nc, r, c)) {
            if (wall[nr][nc] == 'H' && wall[nr + 1][nc] == '.' && wall[nr][nc + 1] == '.' && arr[nr][nc] > curcnt + 1) {
                q.push({{nr, nc}, curcnt + 1});
                arr[nr][nc] = curcnt + 1;
            }
        }

        // 7. 우상단
        nr = curr - 1;
        nc = curc + 1;
        if (check(nr, nc, r, c)) {
            if (wall[nr][nc] == 'H' && wall[nr + 1][nc] == '.' && wall[nr][nc - 1] == '.' && arr[nr][nc] > curcnt + 1) {
                q.push({{nr, nc}, curcnt + 1});
                arr[nr][nc] = curcnt + 1;
            }
        }
    }

    answer.resize(r, vector<int>(c, 0));
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (arr[i][j] == INF) {
                if (wall[i][j] == '.' || wall[i][j] == 'X') {
                    answer[i][j] = 0;
                } else {
                    answer[i][j] = -1;
                }
            } else {
                answer[i][j] = arr[i][j];
            }
        }
    }

    return answer;
}