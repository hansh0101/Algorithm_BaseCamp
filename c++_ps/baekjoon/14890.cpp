#include <iostream>

using namespace std;

int n, l;
int arr[100][100];

int result;

void solution() {
    for (int i = 0; i < n; i++) {
        int curH = arr[i][0];
        int count = 1;
        for (int j = 1; j <= n; j++) {
            if (j == n) {
                result++;
                break;
            }

            if (curH == arr[i][j]) {
                count++;
            } else if (curH + 1 == arr[i][j]) {
                if (count >= l) {
                    curH = arr[i][j];
                    count = 1;
                } else {
                    break;
                }
            } else if (curH - 1 == arr[i][j]) {
                if (j + l - 1 < n) {
                    bool isPossible = true;
                    for (int k = j; k < j + l; k++) {
                        if (curH - 1 != arr[i][k]) {
                            isPossible = false;
                            break;
                        }
                    }
                    if (isPossible) {
                        curH = arr[i][j];
                        j = j + l - 1;
                        count = 0;
                    } else {
                        break;
                    }
                } else {
                    break;
                }
            } else {
                break;
            }
        }
    }

    // col 검사
    for (int i = 0; i < n; i++) {
        int curH = arr[0][i];
        int count = 1;
        for (int j = 1; j <= n; j++) {
            if (j == n) {
                result++;
                break;
            }

            if (curH == arr[j][i]) {
                count++;
            } else if (curH + 1 == arr[j][i]) {
                if (count >= l) {
                    curH = arr[j][i];
                    count = 1;
                } else {
                    break;
                }
            } else if (curH - 1 == arr[j][i]) {
                if (j + l - 1 < n) {
                    bool isPossible = true;
                    for (int k = j; k < j + l; k++) {
                        if (curH - 1 != arr[k][i]) {
                            isPossible = false;
                            break;
                        }
                    }
                    if (isPossible) {
                        curH = arr[j][i];
                        j = j + l - 1;
                        count = 0;
                    } else {
                        break;
                    }
                } else {
                    break;
                }
            } else {
                break;
            }
        }
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> l;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    solution();
    cout << result;
    return 0;
}