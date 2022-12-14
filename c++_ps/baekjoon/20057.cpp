#include <iostream>

using namespace std;

int n;
int arr[500][500];
int result;

int mr[4] = {0, 1, 0, -1};
int mc[4] = {-1, 0, 1, 0};
// 1%, 1%, 2%, 2%, 5%, 7%, 7%, 10%, 10%
pair<int, int> move1[10] = {{-1, 1},
                            {1,  1},
                            {-2, 0},
                            {2,  0},
                            {0,  -2},
                            {-1, 0},
                            {1,  0},
                            {-1, -1},
                            {1,  -1},
                            {0,  -1}};
pair<int, int> move2[10] = {{-1, -1},
                            {-1, 1},
                            {0,  -2},
                            {0,  2},
                            {2,  0},
                            {0,  -1},
                            {0,  1},
                            {1,  -1},
                            {1,  1},
                            {1,  0}};
pair<int, int> move3[10] = {{-1, -1},
                            {1,  -1},
                            {-2, 0},
                            {2,  0},
                            {0,  2},
                            {-1, 0},
                            {1,  0},
                            {-1, 1},
                            {1,  1},
                            {0,  1}};
pair<int, int> move4[10] = {{1,  -1},
                            {1,  1},
                            {0,  2},
                            {0,  -2},
                            {-2, 0},
                            {0,  1},
                            {0,  -1},
                            {-1, -1},
                            {-1, 1},
                            {-1, 0}};

void moveSand(int r, int c, int d) {
    int sand = arr[r][c];
    if (d == 0) {
        int movedSand = 0;
        for (int i = 0; i < 9; i++) {
            int nr = r + move1[i].first;
            int nc = c + move1[i].second;
            int nsand;
            if (i < 2) {
                nsand = sand * 0.01;
                movedSand += nsand;
            } else if (i < 4) {
                nsand = sand * 0.02;
                movedSand += nsand;
            } else if (i < 5) {
                nsand = sand * 0.05;
                movedSand += nsand;
            } else if (i < 7) {
                nsand = sand * 0.07;
                movedSand += nsand;
            } else if (i < 9) {
                nsand = sand * 0.1;
                movedSand += nsand;
            }

            if (nr < 1 || nc < 1 || nr > n || nc > n) {
                result += nsand;
            } else {
                arr[nr][nc] += nsand;
            }
        }

        sand -= movedSand;
        int nr = r + move1[9].first;
        int nc = c + move1[9].second;
        if (nr < 1 || nc < 1 || nr > n || nc > n) {
            result += sand;
        } else {
            arr[nr][nc] += sand;
            arr[r][c] = 0;
        }
    } else if (d == 1) {
        int movedSand = 0;
        for (int i = 0; i < 9; i++) {
            int nr = r + move2[i].first;
            int nc = c + move2[i].second;
            int nsand;
            if (i < 2) {
                nsand = sand * 0.01;
                movedSand += nsand;
            } else if (i < 4) {
                nsand = sand * 0.02;
                movedSand += nsand;
            } else if (i < 5) {
                nsand = sand * 0.05;
                movedSand += nsand;
            } else if (i < 7) {
                nsand = sand * 0.07;
                movedSand += nsand;
            } else if (i < 9) {
                nsand = sand * 0.1;
                movedSand += nsand;
            }

            if (nr < 1 || nc < 1 || nr > n || nc > n) {
                result += nsand;
            } else {
                arr[nr][nc] += nsand;
            }
        }

        sand -= movedSand;
        int nr = r + move2[9].first;
        int nc = c + move2[9].second;
        if (nr < 1 || nc < 1 || nr > n || nc > n) {
            result += sand;
        } else {
            arr[nr][nc] += sand;
            arr[r][c] = 0;
        }
    } else if (d == 2) {
        int movedSand = 0;
        for (int i = 0; i < 9; i++) {
            int nr = r + move3[i].first;
            int nc = c + move3[i].second;
            int nsand;
            if (i < 2) {
                nsand = sand * 0.01;
                movedSand += nsand;
            } else if (i < 4) {
                nsand = sand * 0.02;
                movedSand += nsand;
            } else if (i < 5) {
                nsand = sand * 0.05;
                movedSand += nsand;
            } else if (i < 7) {
                nsand = sand * 0.07;
                movedSand += nsand;
            } else if (i < 9) {
                nsand = sand * 0.1;
                movedSand += nsand;
            }

            if (nr < 1 || nc < 1 || nr > n || nc > n) {
                result += nsand;
            } else {
                arr[nr][nc] += nsand;
            }
        }

        sand -= movedSand;
        int nr = r + move3[9].first;
        int nc = c + move3[9].second;
        if (nr < 1 || nc < 1 || nr > n || nc > n) {
            result += sand;
        } else {
            arr[nr][nc] += sand;
            arr[r][c] = 0;
        }
    } else if (d == 3) {
        int movedSand = 0;
        for (int i = 0; i < 9; i++) {
            int nr = r + move4[i].first;
            int nc = c + move4[i].second;
            int nsand;
            if (i < 2) {
                nsand = sand * 0.01;
                movedSand += nsand;
            } else if (i < 4) {
                nsand = sand * 0.02;
                movedSand += nsand;
            } else if (i < 5) {
                nsand = sand * 0.05;
                movedSand += nsand;
            } else if (i < 7) {
                nsand = sand * 0.07;
                movedSand += nsand;
            } else if (i < 9) {
                nsand = sand * 0.1;
                movedSand += nsand;
            }

            if (nr < 1 || nc < 1 || nr > n || nc > n) {
                result += nsand;
            } else {
                arr[nr][nc] += nsand;
            }
        }

        sand -= movedSand;
        int nr = r + move4[9].first;
        int nc = c + move4[9].second;
        if (nr < 1 || nc < 1 || nr > n || nc > n) {
            result += sand;
        } else {
            arr[nr][nc] += sand;
            arr[r][c] = 0;
        }
    }
}

void solution() {
    int curr = n / 2 + 1;
    int curc = n / 2 + 1;

    int cnt = 1;
    int d = 0;
    while (curr != 1 || curc != 1) {
        for (int i = 0; i < cnt; i++) {
            int nr = curr + mr[d];
            int nc = curc + mc[d];
            if (nr < 1 || nc < 1 || nr > n || nc > n) {
                continue;
            }
            moveSand(nr, nc, d);
            curr = nr;
            curc = nc;
        }

        d = (d + 1) % 4;
        if (d % 2 == 0) {
            if (cnt != n) {
                cnt++;
            }
        }
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> arr[i][j];
        }
    }

    solution();

    cout << result;
    return 0;
}