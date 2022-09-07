#include <iostream>
#include <string>
#include <queue>
#include <algorithm>

#define pii pair<int,int>
using namespace std;

int n;
string str;
int arr[26][26];
bool visit[26][26];
queue<pair<int, int>> q;
int mx[4] = {1, 0, -1, 0};
int my[4] = {0, 1, 0, -1};
vector<int> vec;
int num = 0;

void bfs(int x, int y) {
    q.push({x, y});
    visit[y][x] = true;
    int cnt = 0;
    num++;

    while (!q.empty()) {
        int curx = q.front().first;
        int cury = q.front().second;
        q.pop();
        cnt++;

        for (int i = 0; i < 4; i++) {
            int nx = curx + mx[i];
            int ny = cury + my[i];

            if (nx < 1 || ny < 1 || nx > n || ny > n) {
                continue;
            }

            if (arr[ny][nx] == 1 && !visit[ny][nx]) {
                q.push({nx, ny});
                visit[ny][nx] = true;
            }
        }
    }
    vec.push_back(cnt);
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> str;
        for (int j = 1; j <= n; j++) {
            arr[i][j] = str[j-1] - '0';
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (arr[i][j] == 1 && !visit[i][j]) {
                bfs(j, i);
            }
        }
    }

    cout<<num<<"\n";

    sort(vec.begin(), vec.end());
    for(int i : vec) {
        cout<<i<<"\n";
    }

    return 0;
}