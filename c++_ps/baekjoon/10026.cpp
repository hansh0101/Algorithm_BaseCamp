#include <iostream>
#include <queue>
using namespace std;

int n;
char arr[100][100];
bool normal_visit[100][100];
bool abnormal_visit[100][100];
queue<pair<int, int>> q;
int mx[4] = {1, 0, -1, 0};
int my[4] = {0, 1, 0, -1};
int normal_ans, abnormal_ans;

pair<int, int> normal_finish() {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(!normal_visit[i][j]) {
                return {j, i};
            }
        }
    }
    return {-1, -1};
}

pair<int, int> abnormal_finish() {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(!abnormal_visit[i][j]) {
                return {j, i};
            }
        }
    }
    return {-1, -1};
}

void normal_bfs() {
    while(true) {
        pair<int, int> p = normal_finish();
        if(p.first == -1 && p.second == -1) break;

        q.push({p.first, p.second});
        normal_visit[p.second][p.first] = true;

        while(!q.empty()) {
            int curx = q.front().first;
            int cury = q.front().second;
            char curcol = arr[cury][curx];
            q.pop();

            for(int i=0;i<4;i++) {
                int nx = curx+mx[i];
                int ny = cury+my[i];

                if(nx < 0 || ny < 0 || nx > n-1 || ny > n-1) continue;
                char ncol = arr[ny][nx];

                if(!normal_visit[ny][nx]) {
                    if(curcol == ncol) {
                        q.push({nx, ny});
                        normal_visit[ny][nx] = true;
                    }
                }
            }
        }
        normal_ans++;
    }
}

void abnormal_bfs() {
    while(true) {
        pair<int, int> p = abnormal_finish();
        if(p.first == -1 && p.second == -1) break;

        q.push({p.first, p.second});
        abnormal_visit[p.second][p.first] = true;

        while(!q.empty()) {
            int curx = q.front().first;
            int cury = q.front().second;
            char curcol = arr[cury][curx];
            q.pop();

            for(int i=0;i<4;i++) {
                int nx = curx+mx[i];
                int ny = cury+my[i];

                if(nx < 0 || ny < 0 || nx > n-1 || ny > n-1) continue;
                char ncol = arr[ny][nx];

                if(!abnormal_visit[ny][nx]) {
                    if(curcol == ncol || (curcol == 'R' && ncol == 'G') || (curcol == 'G' && ncol == 'R')) {
                        q.push({nx, ny});
                        abnormal_visit[ny][nx] = true;
                    }
                }
            }
        }
        abnormal_ans++;
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin>>n;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin>>arr[i][j];
        }
    }

    normal_bfs();
    abnormal_bfs();

    cout<<normal_ans<<" "<<abnormal_ans;
}