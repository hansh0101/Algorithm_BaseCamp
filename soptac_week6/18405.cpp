#include <iostream>
#include <queue>
#include <string.h>

using namespace std;

int n, k;
int arr[201][201];
int s, x, y;
int mx[4] = {1, 0, -1, 0};
int my[4] = {0, 1, 0, -1};
queue<pair<int, int>> q[1001];
vector<pair<int, int>> v[1001];

void test() {
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            cout<<arr[i][j]<<" ";
        }
        cout<<"\n";
    }
}

void bfs() {
    for (int i = 0; i < s; i++) {
        for (int j = 1; j <= k; j++) {
            v[j].clear();

            while (!q[j].empty()) {
                int curx = q[j].front().first;
                int cury = q[j].front().second;
                q[j].pop();

                for (int k = 0; k < 4; k++) {
                    int nx = curx + mx[k];
                    int ny = cury + my[k];

                    if(nx < 1 || ny < 1 || nx > n || ny > n) continue;

                    if (arr[ny][nx] == 0) {
                        arr[ny][nx] = j;
                        v[j].push_back({nx, ny});
                    }
                }
            }

            for (int k = 0; k < v[j].size(); k++) {
                q[j].push({v[j][k].first, v[j][k].second});
            }
//            test();
        }
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> arr[i][j];
            if (arr[i][j] != 0) {
                q[arr[i][j]].push({j, i});
            }
        }
    }
    cin >> s >> x >> y;

    bfs();

    cout << arr[x][y];
}