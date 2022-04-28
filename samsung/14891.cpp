#include <iostream>
#include <string>
#include <cmath>

#define RIGHT 2
#define LEFT 6
using namespace std;

string input;
int arr[4][8];
int k, n, d;

int result;

int idx[4];
int dir[4];

int translate(int a, int b) {
    if (a + b >= 8) {
        return (a + b) % 8;
    } else {
        return a + b;
    }
}

void calculate() {
    for (int i = 0; i < 4; i++) {
        if (arr[i][idx[i]] == 1) {
            result += pow(2, i);
        }
    }
}

void solution() {
    // 톱니가 돌 방향을 미리 파악
    dir[n - 1] = d;
    for (int i = n - 2; i >= 0; i--) {
        if (arr[i + 1][translate(idx[i + 1], LEFT)] == arr[i][translate(idx[i], RIGHT)]) {
            dir[i] = 0;
        } else {
            dir[i] = dir[i + 1] * (-1);
        }
    }
    for (int i = n; i < 4; i++) {
        if (arr[i - 1][translate(idx[i - 1], RIGHT)] == arr[i][translate(idx[i], LEFT)]) {
            dir[i] = 0;
        } else {
            dir[i] = dir[i - 1] * (-1);
        }
    }

    // 톱니 돌리기
    for (int i = 0; i < 4; i++) {
        if (dir[i] == 1) {
            if (idx[i] == 0) {
                idx[i] = 7;
            } else {
                idx[i] -= 1;
            }
        } else if (dir[i] == -1) {
            idx[i] = (idx[i] + 1) % 8;
        }
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    for (int i = 0; i < 4; i++) {
        cin >> input;
        for (int j = 0; j < 8; j++) {
            arr[i][j] = input[j] - '0';
        }
    }


    cin >> k;
    for (int i = 0; i < k; i++) {
        cin >> n >> d;
        solution();
    }

    calculate();
    cout << result;
    return 0;
}