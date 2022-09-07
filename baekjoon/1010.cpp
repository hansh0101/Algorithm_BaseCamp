#include <iostream>

using namespace std;

long long dp[30][30];

long long recursion(int n, int m) {
    if (dp[n][m] != 0) {
        return dp[n][m];
    }
    if (n == 1) {
        return dp[n][m] = m;
    }
    for (int i = m - 1; i >= n - 1; i--) {
        dp[n][m] += recursion(n - 1, i);
    }
    return dp[n][m];
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        cout << recursion(n, m) << "\n";
    }

    return 0;
}