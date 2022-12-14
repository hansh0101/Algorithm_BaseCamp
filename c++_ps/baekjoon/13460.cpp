#include <iostream>
#include <queue>
#include <cstring>
#include <cmath>

using namespace std;

int N, M;
string inputString;
char board[10][10];
struct Info {
    int rr;
    int rc;
    int br;
    int bc;
    int cnt = 0;
};
queue<Info> q;
bool visit[10][10][10][10];
int mr[4] = {-1, 0, 1, 0};
int mc[4] = {0, -1, 0, 1};
int result = 11;

bool isOutOfRange(int r, int c) {
    return (r < 0 || r >= N || c < 0 || c >= M);
}

void bfs() {
    while (!q.empty()) {
        Info cur = q.front();
        q.pop();
        int currr = cur.rr;
        int currc = cur.rc;
        int curbr = cur.br;
        int curbc = cur.bc;
        int curCnt = cur.cnt;

        if (curCnt == 11) {
            continue;
        }
        if (board[curbr][curbc] == 'O') {
            continue;
        }
        if (board[currr][currc] == 'O') {
            result = min(result, curCnt);
            continue;
        }

        for (int i = 0; i < 4; i++) {
            int nrr = currr + mr[i];
            int nrc = currc + mc[i];
            int nbr = curbr + mr[i];
            int nbc = curbc + mc[i];

            while (true) {
                if (isOutOfRange(nrr, nrc) || board[nrr][nrc] == '#') {
                    nrr -= mr[i];
                    nrc -= mc[i];
                    break;
                } else if (board[nrr][nrc] == 'O') {
                    break;
                }
                nrr += mr[i];
                nrc += mc[i];
            }
            while (true) {
                if (isOutOfRange(nbr, nbc) || board[nbr][nbc] == '#') {
                    nbr -= mr[i];
                    nbc -= mc[i];
                    break;
                } else if (board[nbr][nbc] == 'O') {
                    break;
                }
                nbr += mr[i];
                nbc += mc[i];
            }

            if (nrr == nbr && nrc == nbc && board[nrr][nrc] != 'O') {
                int rDist = abs(nrr - currr) + abs(nrc - currc);
                int bDist = abs(nbr - curbr) + abs(nbc - curbc);
                if (rDist > bDist) {
                    nrr -= mr[i];
                    nrc -= mc[i];
                } else if (rDist < bDist) {
                    nbr -= mr[i];
                    nbc -= mc[i];
                }
            }

            if (!visit[nrr][nrc][nbr][nbc]) {
                Info info;
                info.rr = nrr;
                info.rc = nrc;
                info.br = nbr;
                info.bc = nbc;
                info.cnt = curCnt + 1;
                q.push(info);
                visit[nrr][nrc][nbr][nbc] = true;
            }
        }
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> N >> M;

    Info info;
    for (int i = 0; i < N; i++) {
        cin >> inputString;
        for (int j = 0; j < M; j++) {
            char c = inputString[j];
            board[i][j] = c;
            if (c == 'R') {
                info.rr = i;
                info.rc = j;
            } else if (c == 'B') {
                info.br = i;
                info.bc = j;
            }
        }
    }

    q.push(info);
    visit[info.rr][info.rc][info.br][info.bc] = true;
    bfs();

    cout << (result == 11 ? -1 : result) << "\n";
    return 0;
}