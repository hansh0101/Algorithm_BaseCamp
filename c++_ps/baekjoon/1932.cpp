#include <iostream>

using namespace std;

int n;
int arr[501][501];
int dp[501][501];

int solution(int n) {
    dp[1][1] = arr[1][1];
    if (n == 1) {
        return dp[1][1];
    }

    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + arr[i][j];
        }
    }

    int ret = 0;
    for (int i = 1; i <= n; i++) {
        ret = max(ret, dp[n][i]);
    }
    return ret;
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cin >> arr[i][j];
        }
    }

    cout << solution(n);
    return 0;
}