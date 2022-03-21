#include <iostream>
#include <queue>
using namespace std;

int k, w, h;
int arr[201][201];
queue<pair<pair<int, int>, pair<int, int>>> q;
bool visit[201][201][30];
int mx[4] = {1, 0, -1, 0};
int my[4] = {0, 1, 0, -1};
int mhx[8] = {2, 2, 1, -1, -2, -2, -1, 1};
int mhy[8] = {-1, 1, 2, 2, 1, -1, -2, -2};

void bfs() {
    q.push({{1,1}, {0, 0}});
    visit[1][1][0] = true;

    while(!q.empty()) {
        int curx = q.front().first.first;
        int cury = q.front().first.second;
        int curjumpcnt = q.front().second.first;
        int curcnt = q.front().second.second;
        q.pop();

        if(curx == w && cury == h) {
            cout<<curcnt;
            return;
        }

        if(curjumpcnt < k) {
            for(int i=0; i<8; i++) {
                int nx = curx + mhx[i];
                int ny = cury + mhy[i];
                int njumpcnt = curjumpcnt + 1;
                int ncnt = curcnt + 1;

                if(nx < 1 || nx > w || ny < 1 || ny > h) continue;
                if(arr[ny][nx] == 1) continue;

                if(!visit[ny][nx][njumpcnt]) {
                    q.push({{nx,ny}, {njumpcnt, ncnt}});
                    visit[ny][nx][njumpcnt] = true;
                }
            }
        }
        for(int i=0; i<4; i++) {
            int nx = curx + mx[i];
            int ny = cury + my[i];
            int njumpcnt = curjumpcnt;
            int ncnt = curcnt+1;

            if(nx < 1 || nx > w || ny < 1 || ny > h) continue;
            if(arr[ny][nx] == 1) continue;

            if(!visit[ny][nx][njumpcnt]) {
                q.push({{nx,ny}, {njumpcnt, ncnt}});
                visit[ny][nx][njumpcnt] = true;
            }
        }
    }
    cout<<"-1";
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin>>k>>w>>h;
    for(int i=1;i<=h;i++) {
        for(int j=1;j<=w;j++) {
            cin>>arr[i][j];
        }
    }

    bfs();
    return 0;
}