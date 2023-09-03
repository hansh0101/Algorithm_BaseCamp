#include <iostream>

using namespace std;

int t, n;
int dp[10001][4];
int result;

void initDpArray() {
    // dp[i][1] + dp[i][2] + dp[i][3] == i를 1, 2, 3의 합으로 표현하는 경우의 수
    // dp[i][1] : i를 1, 2, 3의 합으로 표현하되, 1을 포함해도 되는 경우의 수 (2, 3을 포함해도 됨)
    // dp[i][2] : i를 2, 3의 합으로 표현하고, 1을 포함하면 안 되는 경우의 수 (2, 3을 포함해도 되지만 1을 포함하면 안 됨)
    // dp[i][3] : i를 3의 합으로 표현하고, 1, 2를 포함하면 안 되는 경우의 수 (3을 포함해도 되지만 1, 2를 포함하면 안 됨)

    // N = 1 대한 정보 초기화
    dp[1][1] = 1;
    dp[1][2] = 0;
    dp[1][3] = 0;

    // N = 2에 대한 정보 초기화
    dp[2][1] = 1;
    dp[2][2] = 1;
    dp[2][3] = 0;

    // N = 3에 대한 정보 초기화
    dp[3][1] = 2;
    dp[3][2] = 0;
    dp[3][3] = 1;
}

void getInput() {
    cin >> n;
}

void solve() {
    initDpArray();

    for (int i = 4; i <= n; i++) {
        dp[i][1] = dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][3];
        dp[i][2] = dp[i - 2][2] + dp[i - 2][3];
        dp[i][3] = dp[i - 3][3];
    }

    for (int i = 1; i <= 3; i++) {
        result += dp[n][i];
    }
}

void printResult() {
    cout << result << "\n";
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> t;
    while (t--) {
        result = 0;
        getInput();
        solve();
        printResult();
    }

    return 0;
}