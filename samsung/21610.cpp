#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int n, m;
int arr[51][51];
vector<pair<int, int>> mv; // move vector
int result;

vector<pair<int, int>> nc; // new cloud
bool oc[51][51]; // old cloud
pair<int, int> moving[9] = {{0,  0},
                            {0,  -1},
                            {-1, -1},
                            {-1, 0},
                            {-1, 1},
                            {0,  1},
                            {1,  1},
                            {1,  0},
                            {1,  -1}};
pair<int, int> mov[4] = {{-1, -1},
                         {-1, 1},
                         {1,  1},
                         {1,  -1}};

void solution() {
    // 1. 비바라기 시전
    nc.push_back({n, 1});
    nc.push_back({n, 2});
    nc.push_back({n - 1, 1});
    nc.push_back({n - 1, 2});

    // m회 이동 수행
    for (int i = 0; i < m; i++) {
        // 2. 구름 이동
        int d = mv[i].first;
        int s = mv[i].second;

        for (int j = 0; j < nc.size(); j++) {
            for (int k = 0; k < s; k++) {
                nc[j].first += moving[d].first;
                if(nc[j].first == 0) {
                    nc[j].first = n;
                } else if(nc[j].first == n+1) {
                    nc[j].first = 1;
                }

                nc[j].second += moving[d].second;
                if(nc[j].second == 0) {
                    nc[j].second = n;
                } else if(nc[j].second == n+1) {
                    nc[j].second = 1;
                }
            }
        }

        // 3. 비를 내림
        for (int j = 0; j < nc.size(); j++) {
            arr[nc[j].first][nc[j].second]++;
        }

        // 4. 물복사버그 시전
        for (int j = 0; j < nc.size(); j++) {
            int curr = nc[j].first;
            int curc = nc[j].second;

            int count = 0;
            for (int k = 0; k < 4; k++) {
                int nr = curr + mov[k].first;
                int nc = curc + mov[k].second;

                if (nr < 1 || nc < 1 || nr > n || nc > n) {
                    continue;
                }

                if (arr[nr][nc] > 0) {
                    count++;
                }
            }

            arr[curr][curc] += count;
        }

        // 5. 구름 있던 위치 표시
        for (int j = 0; j < nc.size(); j++) {
            oc[nc[j].first][nc[j].second] = true;
        }

        // 6. 구름 생성
        nc.clear();
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                if (arr[j][k] >= 2 && !oc[j][k]) {
                    nc.push_back({j, k});
                    arr[j][k] -= 2;
                }
            }
        }

        // 7. 다음 반복문 위해 초기화
        memset(oc, false, sizeof(oc));
    }

    // 8. 계산
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            result += arr[i][j];
        }
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < m; i++) {
        int d, s;
        cin >> d >> s;
        mv.push_back({d, s});
    }

    solution();
    cout << result;
    return 0;
}