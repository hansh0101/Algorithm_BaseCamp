#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int n;
int board[25][25];
vector<int> blocks;
queue<pair<int, int>> q;
bool visit[25][25];

int mr[4] = {1, 0, -1, 0};
int mc[4] = {0, 1, 0, -1};

void bfs() {
    blocks.push_back(0);
    while (!q.empty()) {
        int curr = q.front().first;
        int curc = q.front().second;
        q.pop();
        blocks[blocks.size() - 1]++;

        for (int i = 0; i < 4; i++) {
            int nr = curr + mr[i];
            int nc = curc + mc[i];

            if (nr < 0 || nr >= n || nc < 0 || nc >= n) {
                continue;
            }
            if (board[nr][nc] == 1 && !visit[nr][nc]) {
                q.push({nr, nc});
                visit[nr][nc] = true;
            }
        }
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int r = 0; r < n; r++) {
        string str;
        cin >> str;
        for (int c = 0; c < str.length(); c++) {
            board[r][c] = str[c] - '0';
        }
    }

    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            if (board[r][c] == 1 && !visit[r][c]) {
                q.push({r, c});
                visit[r][c] = true;
                bfs();
            }
        }
    }

    sort(blocks.begin(), blocks.end());
    cout << blocks.size() << "\n";
    for (int i : blocks) {
        cout << i << "\n";
    }

    return 0;
}