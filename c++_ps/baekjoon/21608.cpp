#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int n;
int arr[21][21];
vector<int> vec[401];
int mx[4] = {1, 0, -1, 0};
int my[4] = {0, 1, 0, -1};
int result;

void calculate() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int student = arr[i][j];
            int friendCount = 0;
            for (int k = 0; k < 4; k++) {
                int nx = i + mx[k];
                int ny = j + my[k];

                if (nx < 1 || ny < 1 || nx > n || ny > n) {
                    continue;
                }

                for (int l = 0; l < 4; l++) {
                    if (arr[nx][ny] == vec[student][l]) {
                        friendCount++;
                    }
                }
            }

            if (friendCount == 0) {
                result += 0;
            } else if (friendCount == 1) {
                result += 1;
            } else if (friendCount == 2) {
                result += 10;
            } else if (friendCount == 3) {
                result += 100;
            } else if (friendCount == 4) {
                result += 1000;
            }
        }
    }
}

void findMySeat(int student) {
    // 1. 비어있는 칸 중에서 좋아하는 학생이 인접한 칸에 가장 많은 칸으로 자리를 정한다.
    int friendCount = -1;
    vector<pair<int, int>> candidate1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (arr[i][j] != 0) {
                continue;
            }

            int count = 0;
            for (int k = 0; k < 4; k++) {
                int nx = i + mx[k];
                int ny = j + my[k];

                if (nx < 1 || ny < 1 || nx > n || ny > n) {
                    continue;
                }

                for (int l = 0; l < 4; l++) {
                    if (vec[student][l] == arr[nx][ny]) {
                        count++;
                    }
                }
            }

            if (count > friendCount) {
                friendCount = count;
                candidate1.clear();
                candidate1.push_back({i, j});
            } else if (count == friendCount) {
                candidate1.push_back({i, j});
            }
        }
    }

    if (candidate1.size() == 1) {
        int x = candidate1[0].first;
        int y = candidate1[0].second;
        arr[x][y] = student;
        return;
    }

    // 2. 1을 만족하는 칸이 여러 개이면, 인접한 칸 중에서 비어있는 칸이 가장 많은 칸으로 자리를 정한다.
    int vacantCount = -1;
    vector<pair<int, int>> candidate2;
    for (int i = 0; i < candidate1.size(); i++) {
        int cx = candidate1[i].first;
        int cy = candidate1[i].second;

        int count = 0;
        for (int j = 0; j < 4; j++) {
            int nx = cx + mx[j];
            int ny = cy + my[j];

            if (nx < 1 || ny < 1 || nx > n || ny > n) {
                continue;
            }

            if (arr[nx][ny] == 0) {
                count++;
            }
        }

        if (count > vacantCount) {
            vacantCount = count;
            candidate2.clear();
            candidate2.push_back({cx, cy});
        } else if (count == vacantCount) {
            candidate2.push_back({cx, cy});
        }
    }

    if (candidate2.size() == 1) {
        int x = candidate2[0].first;
        int y = candidate2[0].second;
        arr[x][y] = student;
        return;
    }

    // 3. 2를 만족하는 칸도 여러 개인 경우에는 행의 번호가 가장 작은 칸으로, 그러한 칸도 여러 개이면 열의 번호가 가장 작은 칸으로 자리를 정한다.
    int x = n * n + 1, y = n * n + 1;
    for (int i = 0; i < candidate2.size(); i++) {
        int cx = candidate2[i].first;
        int cy = candidate2[i].second;

        if (cx < x) {
            x = cx;
            y = cy;
            continue;
        }

        if (cx == x && cy < y) {
            x = cx;
            y = cy;
            continue;
        }
    }

    arr[x][y] = student;
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n * n; i++) {
        int student;
        int friend1, friend2, friend3, friend4;

        cin >> student >> friend1 >> friend2 >> friend3 >> friend4;
        vec[student].push_back(friend1);
        vec[student].push_back(friend2);
        vec[student].push_back(friend3);
        vec[student].push_back(friend4);

        findMySeat(student);
    }

    calculate();

    cout<<result;
    return 0;
}