#include <iostream>

using namespace std;

int t, n;
int dp[10001][4];
int result;

void initDpArray() {
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

        cout << "------\n";
        cout << "dp[" << i << "][1] : " << dp[i][1] << "\n";
        cout << "dp[" << i << "][2] : " << dp[i][2] << "\n";
        cout << "dp[" << i << "][3] : " << dp[i][3] << "\n";
        cout << "------\n";
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

/*
Test input
3
4
7
10

Test output
4
8
14
*/