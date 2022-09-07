#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int board[500][500];
int result = 0;

pair<int, int> case1[8][4] = {{{0, 0}, {-1, 0},  {-1, -1}, {-1, -2}},
                              {{0, 0}, {-1, 0},  {-1, 1},  {-1, 2}},
                              {{0, 0}, {0,  -1}, {-1, -1}, {-2, -1}},
                              {{0, 0}, {0,  -1}, {1,  -1}, {2,  -1}},
                              {{0, 0}, {1, 0}, {1,  -1}, {1,  -2}},
                              {{0, 0}, {1, 0}, {1,  1}, {1, 2}},
                              {{0, 0}, {0, 1}, {-1, 1}, {-2,  1}},
                              {{0, 0}, {0, 1}, {1,  1}, {2,  1}}};
pair<int, int> case2[4][4] = {{{0, 0}, {-1, 0},  {-1, -1}, {-2, -1}},
                              {{0, 0}, {-1, 0},  {-1, 1},  {-2, 1}},
                              {{0, 0}, {0,  -1}, {1,  -1}, {1,  -2}},
                              {{0, 0}, {0,  -1}, {-1, -1}, {-1, -2}}};
pair<int, int> case3[4][4] = {{{0, 0}, {-1, 0},  {-2, 0},  {-1, -1}},
                              {{0, 0}, {-1, 0},  {-2, 0},  {-1, 1}},
                              {{0, 0}, {0,  -1}, {0,  -2}, {1,  -1}},
                              {{0, 0}, {0,  -1}, {0,  -2}, {-1, -1}}};
pair<int, int> case4[2][4] = {{{0, 0}, {-1, 0},  {-2, 0},  {-3, 0}},
                              {{0, 0}, {0,  -1}, {0,  -2}, {0,  -3}}};
pair<int, int> case5[1][4] = {{{0, 0}, {-1, 0}, {0, -1}, {-1, -1}}};

bool isOut(int r, int c) {
    if (r < 0 || c < 0 || r >= n || c >= m) {
        return true;
    } else {
        return false;
    }
}

void check(int r, int c) {
    // case 1
    for (int i = 0; i < 8; i++) {
        int tmpResult = 0;
        bool isOutFlag = false;
        for (int j = 0; j < 4; j++) {
            int nr = r + case1[i][j].first;
            int nc = c + case1[i][j].second;

            if (isOut(nr, nc)) {
                isOutFlag = true;
                break;
            }

            tmpResult += board[nr][nc];
        }
        if (isOutFlag) {
            continue;
        } else {
            result = max(result, tmpResult);
        }
    }

    // case 2
    for (int i = 0; i < 4; i++) {
        int tmpResult = 0;
        bool isOutFlag = false;
        for (int j = 0; j < 4; j++) {
            int nr = r + case2[i][j].first;
            int nc = c + case2[i][j].second;

            if (isOut(nr, nc)) {
                isOutFlag = true;
                break;
            }

            tmpResult += board[nr][nc];
        }
        if (isOutFlag) {
            continue;
        } else {
            result = max(result, tmpResult);
        }
    }

    // case 3
    for (int i = 0; i < 4; i++) {
        int tmpResult = 0;
        bool isOutFlag = false;
        for (int j = 0; j < 4; j++) {
            int nr = r + case3[i][j].first;
            int nc = c + case3[i][j].second;

            if (isOut(nr, nc)) {
                isOutFlag = true;
                break;
            }

            tmpResult += board[nr][nc];
        }
        if (isOutFlag) {
            continue;
        } else {
            result = max(result, tmpResult);
        }
    }

    // case 4
    for (int i = 0; i < 2; i++) {
        int tmpResult = 0;
        bool isOutFlag = false;
        for (int j = 0; j < 4; j++) {
            int nr = r + case4[i][j].first;
            int nc = c + case4[i][j].second;

            if (isOut(nr, nc)) {
                isOutFlag = true;
                break;
            }

            tmpResult += board[nr][nc];
        }
        if (isOutFlag) {
            continue;
        } else {
            result = max(result, tmpResult);
        }
    }

    // case 5
    for (int i = 0; i < 1; i++) {
        int tmpResult = 0;
        bool isOutFlag = false;
        for (int j = 0; j < 4; j++) {
            int nr = r + case5[i][j].first;
            int nc = c + case5[i][j].second;

            if (isOut(nr, nc)) {
                isOutFlag = true;
                break;
            }

            tmpResult += board[nr][nc];
        }
        if (isOutFlag) {
            continue;
        } else {
            result = max(result, tmpResult);
        }
    }
}

void solution() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            check(i, j);
        }
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    solution();
    cout << result;
    return 0;
}