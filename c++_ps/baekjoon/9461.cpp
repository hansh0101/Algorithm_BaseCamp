#include <iostream>

using namespace std;

long long dp[101];

long long solution(int i) {
    if (i < 5) {
        return dp[i];
    } else {
        if (dp[i] != 0) {
            return dp[i];
        } else {
            return dp[i] = solution(i - 1) + solution(i - 5);
        }
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;

    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;
    dp[4] = 2;
    dp[5] = 2;

    while (t--) {
        int n;
        cin >> n;

        cout << solution(n) << "\n";
    }

    return 0;
}