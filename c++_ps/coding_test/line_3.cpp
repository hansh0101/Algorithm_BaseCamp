#include <string>
#include <vector>
#include <cstring>
#include <queue>
#include <iostream>

using namespace std;

int mr[4] = {0, 1, 0, -1};
int mc[4] = {1, 0, -1, 0};

vector<vector<long long>> solution(int n, int m, vector<vector<int>> fires, vector<vector<int>> ices) {
    vector<vector<long long>> answer;

    long long board[30][30];
    memset(board, 0, sizeof(board));

    for (int i = 1; i <= m; i++) {
        pair<int, int> arr[30][30];
        for (int j = 0; j < 30; j++) {
            for (int k = 0; k < 30; k++) {
                arr[j][k] = {0, 0};
            }
        }

        for (vector<int> fire: fires) {
            int r = fire[0] - 1;
            int c = fire[1] - 1;

            for (int j = r - i; j <= r + i; j++) {
                for (int k = c - i; k <= c + i; k++) {
                    if (j < 0 || j >= n || k < 0 || k >= n) continue;
                    arr[j][k].first++;
                }
            }
        }

        for (vector<int> ice: ices) {
            int r = ice[0] - 1;
            int c = ice[1] - 1;

            bool visit[30][30];
            memset(visit, false, sizeof(visit));
            queue<pair<pair<int, int>, int>> q;
            q.push({{r, c}, 0});
            visit[r][c] = true;
            arr[r][c].second++;

            while (!q.empty()) {
                int curr = q.front().first.first;
                int curc = q.front().first.second;
                int curcnt = q.front().second;
                q.pop();
                if (curcnt == i) continue;

                for (int i = 0; i < 4; i++) {
                    int nr = curr + mr[i];
                    int nc = curc + mc[i];

                    if (nr < 0 || nr >= n || nc < 0 || nc >= n) continue;
                    if (!visit[nr][nc]) {
                        q.push({{nr, nc}, curcnt + 1});
                        arr[nr][nc].second++;
                        visit[nr][nc] = true;
                    }
                }
            }
        }

        cout << i <<"일 후\n";

        cout << "불\n";
        for(int j = 0 ; j < n; j++) {
            for(int k = 0; k < n; k++) {
                cout << arr[j][k].first << " ";
            }
            cout<<"\n";
        }

        cout<<"얼음\n";
        for(int j = 0 ; j < n; j++) {
            for(int k = 0; k < n; k++) {
                cout << arr[j][k].second << " ";
            }
            cout<<"\n";
        }

        cout << "결과:\n";
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                board[j][k] += arr[j][k].first - arr[j][k].second;
                cout << board[j][k] << " ";
            }
            cout << "\n";
        }
    }

    answer.resize(n, vector<long long>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            answer[i][j] = board[i][j];
        }
    }

    return answer;
}