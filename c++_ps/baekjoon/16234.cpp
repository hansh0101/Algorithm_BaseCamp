#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int n, l, r;
int arr[50][50];
queue<pair<int, int>> q;
vector<pair<int, int>> v;
bool visited[50][50];
int mr[4] = {1, 0, -1, 0};
int mc[4] = {0, 1, 0, -1};
int result;

void getInput();
void solve();
void printResult();

void bfs();
void movePeople();

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    getInput();
    solve();
    printResult();

    return 0;
}

void getInput() {
    cin >> n >> l >> r;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
}

void solve() {
    bool repeatFlag = true;

    while (repeatFlag) {
        repeatFlag = false;
        while (!q.empty()) {
            q.pop();
        }
        memset(visited, false, sizeof(visited));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                v.clear();

                if (!visited[i][j]) {
                    q.push({i, j});
                    visited[i][j] = true;
                    bfs();
                }

                if (v.size() >= 2) {
                    movePeople();
                    repeatFlag = true;
                }
            }
        }

        if (repeatFlag) {
            result++;
        }
    }
}

void printResult() {
    cout << result << "\n";
}

void bfs() {
    while (!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();
        v.push_back(p);

        for (int i = 0; i < 4; i++) {
            int nr = p.first + mr[i];
            int nc = p.second + mc[i];

            if (nr < 0 || nr >= n || nc < 0 || nc >= n) {
                continue;
            }

            int diff = abs(arr[p.first][p.second] - arr[nr][nc]);
            if (diff >= l && diff <= r && !visited[nr][nc]) {
                q.push({nr, nc});
                visited[nr][nc] = true;
            }
        }
    }
}

void movePeople() {
    int sum = 0;
    for (pair<int, int> p : v) {
        sum += arr[p.first][p.second];
    }
    for (pair<int, int> p : v) {
        arr[p.first][p.second] = sum / v.size();
    }
}