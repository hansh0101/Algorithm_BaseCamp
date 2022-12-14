#include <iostream>
#include <queue>
#define pii pair<int, int>
using namespace std;

int m, n;
int arr[1001][1001];
bool visit[1001][1001];
queue<pair<pair<int,int>, int>> q;
int mx[4] = {1, 0, -1, 0};
int my[4] = {0, 1, 0, -1};
int ans;

void bfs() {
    while(!q.empty()) {
        int curx = q.front().first.first;
        int cury = q.front().first.second;
        int curd = q.front().second;
        q.pop();
        ans = max(ans, curd);

        for(int i=0;i<4;i++) {
            int nx = curx+mx[i];
            int ny = cury+my[i];
            int nd = curd+1;

            if(nx<1 || ny < 1 || nx > m || ny > n) {
                continue;
            }

            if(arr[ny][nx] == 0 && !visit[ny][nx]) {
                arr[ny][nx] = 1;
                q.push({{nx, ny}, nd});
                visit[ny][nx] = true;
            }
        }
    }
}

void check() {
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            if(arr[i][j] == 0) {
                ans = -1;
            }
        }
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin>>m>>n;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            cin>>arr[i][j];
            if(arr[i][j] == 1) {
                q.push({{j, i}, 0});
                visit[i][j] = true;
            }
        }
    }

    bfs();
    check();

    cout<<ans;
    return 0;
}