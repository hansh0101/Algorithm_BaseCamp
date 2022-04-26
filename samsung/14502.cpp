#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int n, m;
int arr[8][8];
int result = 0;

vector<pair<int, int>> zero;
vector<pair<int, int>> wall;
vector<pair<int, int>> virus;
bool visit[8][8];
int mx[4] = {1, -1, 0, 0};
int my[4] = {0, 0, 1, -1};

void bfs() {
    memset(visit, false, sizeof(visit));
    queue<pair<int, int>> q;
    for (int i = 0; i < virus.size(); i++) {
        q.push(virus[i]);
    }

    int virusSize = 0;
    while(!q.empty()) {
        virusSize++;
        int curx = q.front().first;
        int cury = q.front().second;
        q.pop();

        for (int j = 0; j < 4; j++) {
            int nx = curx + mx[j];
            int ny = cury + my[j];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
                continue;
            }

            if (arr[nx][ny] > 0) {
                continue;
            }

            if(!visit[nx][ny]) {
                q.push({nx, ny});
                visit[nx][ny] = true;
            }
        }
    }

    result = max(result, n*m - (int)wall.size() - virusSize - 3);
}

void makeTheWall() {
    for (int i = 0; i < zero.size(); i++) {
        arr[zero[i].first][zero[i].second] = 1;
        for (int j = i + 1; j < zero.size(); j++) {
            arr[zero[j].first][zero[j].second] = 1;
            for (int k = j + 1; k < zero.size(); k++) {
                arr[zero[k].first][zero[k].second] = 1;
                bfs();
                arr[zero[k].first][zero[k].second] = 0;
            }
            arr[zero[j].first][zero[j].second] = 0;
        }
        arr[zero[i].first][zero[i].second] = 0;
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 0) {
                zero.push_back({i, j});
            } else if(arr[i][j] == 1) {
                wall.push_back({i, j});
            } else if (arr[i][j] == 2) {
                virus.push_back({i, j});
            }
        }
    }

    makeTheWall();

    cout<<result;
    return 0;
}