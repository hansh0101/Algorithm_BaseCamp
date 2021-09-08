#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int r, c;
char arr[1001][1001];
bool visit[1001][1001];
queue<pair<pair<int, int>, int>> q;
queue<pair<int, int>> f;
int mx[4] = {1, 0, -1, 0};
int my[4] = {0, 1, 0, -1};

void fire() {
    queue<pair<int, int>> nf;
    while (!f.empty()) {
        int curx = f.front().first;
        int cury = f.front().second;
        f.pop();

        for (int i = 0; i < 4; i++) {
            int nx = curx + mx[i];
            int ny = cury + my[i];

            if (nx < 1 || ny < 1 || nx > c || ny > r) {
                continue;
            }

            if (arr[ny][nx] == '.' || arr[ny][nx] == 'J') {
                nf.push({nx, ny});
                arr[ny][nx] = 'F';
            }
        }
    }
    f = nf;
}

void bfs() {
    int cnt = 0;
    while (!q.empty()) {
        int curx = q.front().first.first;
        int cury = q.front().first.second;
        int curcnt = q.front().second;
        q.pop();

        if (cnt != curcnt) {
            fire();
            cnt++;
        }

        if(arr[cury][curx] == 'F') {
            continue;
        }

        if (curx == 1 || cury == 1 || curx == c || cury == r) {
            cout<<curcnt + 1;
            return;
        }

        for(int i=0;i<4;i++) {
            int nx = curx+mx[i];
            int ny = cury+my[i];
            int ncnt = curcnt + 1;

            if(nx < 1 || ny < 1 || nx > c || ny > r) {
                continue;
            }

            if(arr[ny][nx] == '.' && !visit[ny][nx]) {
                q.push({{nx, ny}, ncnt});
                visit[ny][nx] = true;
            }
        }
    }
    cout<<"IMPOSSIBLE";
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> r >> c;
    for (int i = 1; i <= r; i++) {
        string str;
        cin >> str;
        for (int j = 1; j <= c; j++) {
            arr[i][j] = str[j - 1];
            if (str[j - 1] == 'J') {
                q.push({{j, i}, 0});
                visit[i][j] = true;
            } else if (str[j - 1] == 'F') {
                f.push({j, i});
            }
        }
    }

    bfs();
    return 0;
}