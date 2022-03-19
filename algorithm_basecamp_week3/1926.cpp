#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define pii pair<int,int>
using namespace std;

int n, m;
int arr[501][501];
bool visit[501][501];
queue<pii> q;
int mx[4] = {1, 0, -1, 0};
int my[4] = {0, 1, 0, -1};
vector<int> picSize;
int cnt;

void bfs(int x, int y) {
    q.push({x, y});
    visit[y][x] = true;
    int sz = 0;

    while(!q.empty()) {
        int curx = q.front().first;
        int cury = q.front().second;
        q.pop();
        sz++;

        for(int i=0;i<4;i++) {
            int nx = curx+mx[i];
            int ny = cury+my[i];

            if(nx < 1 || ny < 1 || nx > m || ny > n) {
                continue;
            }

            if(arr[ny][nx] == 1 && !visit[ny][nx]) {
                q.push({nx, ny});
                visit[ny][nx] = true;
            }
        }
    }
    picSize.push_back(sz);
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin>>arr[i][j];
        }
    }

    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            if(arr[i][j] == 1 && !visit[i][j]) {
                bfs(j, i);
            }
        }
    }

    sort(picSize.begin(), picSize.end());
    if(picSize.empty()) {
        cout<<picSize.size()<<"\n"<<0;
    }
    else {
        cout<<picSize.size()<<"\n"<<picSize.back();
    }

    return 0;
}