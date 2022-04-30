#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define UP 0
#define LEFT 1
#define DOWN 2
#define RIGHT 3

using namespace std;

int t, n;
int arr[100][100];
int result;

vector<pair<int, int>> bh;
vector<pair<int, int>> wh6;
vector<pair<int, int>> wh7;
vector<pair<int, int>> wh8;
vector<pair<int, int>> wh9;
vector<pair<int, int>> wh10;

int mr[4] = {-1, 0, 1, 0};
int mc[4] = {0, -1, 0, 1};

bool isInBlackHole(int r, int c) {
    for (int i = 0; i < bh.size(); i++) {
        if (r == bh[i].first && c == bh[i].second) {
            return true;
        }
    }
    return false;
}

int block1(int dir) {
    if (dir == UP) {
        return DOWN;
    } else if (dir == LEFT) {
        return UP;
    } else if (dir == RIGHT) {
        return LEFT;
    } else if (dir == DOWN) {
        return RIGHT;
    }
}

int block2(int dir) {
    if (dir == UP) {
        return RIGHT;
    } else if (dir == LEFT) {
        return DOWN;
    } else if (dir == RIGHT) {
        return LEFT;
    } else if (dir == DOWN) {
        return UP;
    }
}

int block3(int dir) {
    if (dir == UP) {
        return LEFT;
    } else if (dir == LEFT) {
        return RIGHT;
    } else if (dir == RIGHT) {
        return DOWN;
    } else if (dir == DOWN) {
        return UP;
    }
}

int block4(int dir) {
    if (dir == UP) {
        return DOWN;
    } else if (dir == LEFT) {
        return RIGHT;
    } else if (dir == RIGHT) {
        return UP;
    } else if (dir == DOWN) {
        return LEFT;
    }
}

int block5(int dir) {
    if (dir == UP) {
        return DOWN;
    } else if (dir == LEFT) {
        return RIGHT;
    } else if (dir == RIGHT) {
        return LEFT;
    } else if (dir == DOWN) {
        return UP;
    }
}

void solution(int r, int c, int d) {
    bool flag = false;
    int curr = r, curc = c, curd = d;
    int score = 0;
    while (true) {
        if ((curr == r && curc == c && flag) || (isInBlackHole(curr, curc))) {
            break;
        }

        flag = true;
        int nr = curr + mr[curd];
        int nc = curc + mc[curd];

        if (nr < 0 || nc < 0 || nr > n - 1 || nc > n - 1) {
            score++;
            curr = nr;
            curc = nc;
            curd = (curd + 2) % 4;
            continue;
        }

        if (arr[nr][nc] == 1) {
            curd = block1(curd);
            score++;
        } else if (arr[nr][nc] == 2) {
            curd = block2(curd);
            score++;
        } else if (arr[nr][nc] == 3) {
            curd = block3(curd);
            score++;
        } else if (arr[nr][nc] == 4) {
            curd = block4(curd);
            score++;
        } else if (arr[nr][nc] == 5) {
            curd = block5(curd);
            score++;
        } else if (arr[nr][nc] == 6) {
            if(nr == wh6[0].first && nc == wh6[0].second) {
                nr = wh6[1].first;
                nc = wh6[1].second;
            } else {
                nr = wh6[0].first;
                nc = wh6[0].second;
            }
        } else if(arr[nr][nc] == 7) {
            if(nr == wh7[0].first && nc == wh7[0].second) {
                nr = wh7[1].first;
                nc = wh7[1].second;
            } else {
                nr = wh7[0].first;
                nc = wh7[0].second;
            }
        } else if(arr[nr][nc] == 8) {
            if(nr == wh8[0].first && nc == wh8[0].second) {
                nr = wh8[1].first;
                nc = wh8[1].second;
            } else {
                nr = wh8[0].first;
                nc = wh8[0].second;
            }
        } else if(arr[nr][nc] == 9) {
            if(nr == wh9[0].first && nc == wh9[0].second) {
                nr = wh9[1].first;
                nc = wh9[1].second;
            } else {
                nr = wh9[0].first;
                nc = wh9[0].second;
            }
        } else if(arr[nr][nc] == 10) {
            if(nr == wh10[0].first && nc == wh10[0].second) {
                nr = wh10[1].first;
                nc = wh10[1].second;
            } else {
                nr = wh10[0].first;
                nc = wh10[0].second;
            }
        }
        curr = nr;
        curc = nc;
    }
    result = max(result, score);
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> t;
    for (int z = 1; z <= t; z++) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> arr[i][j];
                if (arr[i][j] == 6) {
                    wh6.push_back({i, j});
                } else if (arr[i][j] == 7) {
                    wh7.push_back({i, j});
                } else if (arr[i][j] == 8) {
                    wh8.push_back({i, j});
                } else if (arr[i][j] == 9) {
                    wh9.push_back({i, j});
                } else if (arr[i][j] == 10) {
                    wh10.push_back({i, j});
                } else if (arr[i][j] == -1) {
                    bh.push_back({i, j});
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (arr[i][j] == 0) {
                    for (int k = 0; k < 4; k++) {
                        solution(i, j, k);
                    }
                }
            }
        }

        cout << "#" << z << " " << result << "\n";
        result = 0;
        memset(arr, 0, sizeof(arr));
        bh.clear();
        wh6.clear();
        wh7.clear();
        wh8.clear();
        wh9.clear();
        wh10.clear();
    }
}