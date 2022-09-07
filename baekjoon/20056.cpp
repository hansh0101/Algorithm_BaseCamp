#include <iostream>
#include <vector>

using namespace std;

int n, m, K;
int result;

struct fireball {
    int r;
    int c;
    int m;
    int s;
    int d;

    fireball(int r, int c, int m, int s, int d) {
        this->r = r;
        this->c = c;
        this->m = m;
        this->s = s;
        this->d = d;
    }
};

vector<fireball> vec;
vector<fireball> tmpvec;
vector<fireball> board[51][51];

pair<int, int> directions[8] = {{-1, 0},
                                {-1, 1},
                                {0,  1},
                                {1,  1},
                                {1,  0},
                                {1,  -1},
                                {0,  -1},
                                {-1, -1}};

void solution() {
    // 명령을 K번 반복한다.
    while (K--) {
        // 1. 파이어볼을 이동시킨다.
        for (int i = 0; i < vec.size(); i++) {
            fireball fb = vec[i];
            fb.r = fb.r + directions[fb.d].first * fb.s;
            fb.c = fb.c + directions[fb.d].second * fb.s;

            while (fb.r < 1) {
                fb.r += n;
            }
            while (fb.r > n) {
                fb.r -= n;
            }
            while (fb.c < 1) {
                fb.c += n;
            }
            while (fb.c > n) {
                fb.c -= n;
            }

            vec[i] = fb;

            board[fb.r][fb.c].push_back(fb);
        }

        // 2. 이동이 끝난 후 같은 칸에 파이어볼이 있다면 합친다.
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (board[i][j].size() >= 2) {
                    vector<fireball> fbs = board[i][j];

                    int sumM = 0;
                    int sumS = 0;
                    bool isAllOdd = true;
                    bool isAllEven = true;
                    for (int k = 0; k < fbs.size(); k++) {
                        fireball fb = fbs[k];

                        sumM += fb.m;
                        sumS += fb.s;
                        if (isAllOdd) {
                            isAllOdd = fb.d % 2 == 1;
                        }
                        if (isAllEven) {
                            isAllEven = fb.d % 2 == 0;
                        }
                    }

                    if (sumM / 5 != 0) {
                        if (isAllOdd || isAllEven) {
                            tmpvec.push_back(fireball(i, j, sumM / 5, sumS / fbs.size(), 0));
                            tmpvec.push_back(fireball(i, j, sumM / 5, sumS / fbs.size(), 2));
                            tmpvec.push_back(fireball(i, j, sumM / 5, sumS / fbs.size(), 4));
                            tmpvec.push_back(fireball(i, j, sumM / 5, sumS / fbs.size(), 6));
                        } else {
                            tmpvec.push_back(fireball(i, j, sumM / 5, sumS / fbs.size(), 1));
                            tmpvec.push_back(fireball(i, j, sumM / 5, sumS / fbs.size(), 3));
                            tmpvec.push_back(fireball(i, j, sumM / 5, sumS / fbs.size(), 5));
                            tmpvec.push_back(fireball(i, j, sumM / 5, sumS / fbs.size(), 7));
                        }
                    }
                } else if (board[i][j].size() == 1) {
                    tmpvec.push_back(board[i][j][0]);
                }
            }
        }

        // 3. 합치는 작업이 끝났다면, 변수들을 초기화해주자.
        vec.clear();
        for (int i = 0; i < tmpvec.size(); i++) {
            vec.push_back(tmpvec[i]);
        }
        tmpvec.clear();
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                board[i][j].clear();
            }
        }
    }

    for (int i = 0; i < vec.size(); i++) {
        result += vec[i].m;
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m >> K;
    for (int i = 0; i < m; i++) {
        int r, c, m, s, d;
        cin >> r >> c >> m >> s >> d;
        vec.push_back(fireball(r, c, m, s, d));
    }

    solution();
    cout << result;
    return 0;
}