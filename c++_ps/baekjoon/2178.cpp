#include <iostream>
#include <queue>

using namespace std;

int n, m;
int arr[101][101];
bool visit[101][101];
queue<pair<pair<int, int>, int>> q;
int mx[4] = {1, 0, -1, 0};
int my[4] = {0, 1, 0, -1};

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        string str;
        cin >> str;
        for (int j = 1; j <= m; j++) {
            arr[i][j] = str[j - 1] - '0';
        }
    }

    q.push({{1, 1}, 1});
    visit[1][1] = true;

    while (!q.empty()) {
        int curx = q.front().first.second;
        int cury = q.front().first.first;
        int curcnt = q.front().second;
        q.pop();

        if(curx == m && cury == n) {
            cout<<curcnt;
            break;
        }

        for(int i=0;i<4;i++) {
            int nx = curx+mx[i];
            int ny = cury+my[i];
            int ncnt = curcnt+1;

            if(nx < 1 || ny < 1 || nx > m || ny > n) {
                continue;
            }

            if(arr[ny][nx] == 1 && !visit[ny][nx]) {
                q.push({{ny,nx}, ncnt});
                visit[ny][nx] = true;
            }
        }
    }
    return 0;
}