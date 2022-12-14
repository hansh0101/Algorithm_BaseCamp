#include <iostream>
#include <vector>

using namespace std;

int n, m;
int arr[8][8];

int result = 65;

class Cctv {
public:
    int type;
    int r;
    int c;
    int direction;

    Cctv(int t, int r, int c, int d) {
        type = t;
        this->r = r;
        this->c = c;
        direction = d;
    }
};

vector<Cctv> v;
vector<Cctv> vec;
int board[8][8];
int mr[4] = {0, -1, 0, 1};
int mc[4] = {1, 0, -1, 0};
// 순서 : Right, Up, Left, Down

void check(vector<int> dir, int r, int c) {
    for (int i = 0; i < dir.size(); i++) {
        int nr = r;
        int nc = c;
        while (true) {
            nr += mr[dir[i]];
            nc += mc[dir[i]];

            if (nr < 0 || nc < 0 || nr >= n || nc >= m) {
                break;
            }

            if (board[nr][nc] == 6) {
                break;
            }

            if (board[nr][nc] == 0) {
                board[nr][nc] = -1;
            }
        }
    }
}

void calculate() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            board[i][j] = arr[i][j];
        }
    }

    for (int i = 0; i < vec.size(); i++) {
        Cctv cctv = vec[i];
        if (cctv.type == 1) {
            vector<int> direction;
            direction.push_back(cctv.direction);
            check(direction, cctv.r, cctv.c);
        } else if (cctv.type == 2) {
            vector<int> direction;
            if (cctv.direction == 0) {
                direction.push_back(0);
                direction.push_back(2);
            } else if (cctv.direction == 1) {
                direction.push_back(1);
                direction.push_back(3);
            }
            check(direction, cctv.r, cctv.c);
        } else if (cctv.type == 3) {
            vector<int> direction;
            if (cctv.direction == 0) {
                direction.push_back(0);
                direction.push_back(1);
            } else if (cctv.direction == 1) {
                direction.push_back(1);
                direction.push_back(2);
            } else if (cctv.direction == 2) {
                direction.push_back(2);
                direction.push_back(3);
            } else if (cctv.direction == 3) {
                direction.push_back(3);
                direction.push_back(0);
            }
            check(direction, cctv.r, cctv.c);
        } else if (cctv.type == 4) {
            vector<int> direction;
            if (cctv.direction == 0) {
                direction.push_back(0);
                direction.push_back(1);
                direction.push_back(2);
            } else if (cctv.direction == 1) {
                direction.push_back(1);
                direction.push_back(2);
                direction.push_back(3);
            } else if (cctv.direction == 2) {
                direction.push_back(2);
                direction.push_back(3);
                direction.push_back(0);
            } else if (cctv.direction == 3) {
                direction.push_back(3);
                direction.push_back(0);
                direction.push_back(1);
            }
            check(direction, cctv.r, cctv.c);
        } else if (cctv.type == 5) {
            vector<int> direction;
            direction.push_back(0);
            direction.push_back(1);
            direction.push_back(2);
            direction.push_back(3);
            check(direction, cctv.r, cctv.c);
        }
    }
    int tmpResult = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 0) {
                tmpResult++;
            }
        }
    }
    result = min(result, tmpResult);
}

void solution(int idx) {
    if (idx == v.size()) {
        calculate();
        return;
    }

    if (v[idx].type == 1 || v[idx].type == 3 || v[idx].type == 4) {
        for (int i = 0; i < 4; i++) {
            vec.push_back(Cctv(v[idx].type, v[idx].r, v[idx].c, i));
            solution(idx + 1);
            vec.pop_back();
        }
    } else if (v[idx].type == 2) {
        for (int i = 0; i < 2; i++) {
            vec.push_back(Cctv(v[idx].type, v[idx].r, v[idx].c, i));
            solution(idx + 1);
            vec.pop_back();
        }
    } else if (v[idx].type == 5) {
        vec.push_back(Cctv(v[idx].type, v[idx].r, v[idx].c, 0));
        solution(idx + 1);
        vec.pop_back();
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];

            if (arr[i][j] > 0 && arr[i][j] < 6) {
                v.push_back(Cctv(arr[i][j], i, j, 0));
            }
        }
    }

    solution(0);
    cout << result;
    return 0;
}