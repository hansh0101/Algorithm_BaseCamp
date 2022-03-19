#include <iostream>

using namespace std;

int n;
int arr[10001];
int dp[2][10001];

void solution(int num) {
    if (num == 1) {
        return;
    }

    for (int i = 2; i <= n; i++) {
        dp[0][i] = max(dp[0][i - 2], dp[1][i - 2]) + arr[i];
        dp[1][i] = dp[0][i - 1] + arr[i];

        if(dp[0][i] < max(dp[0][i-1], dp[1][i-1])) {
            dp[0][i] = max(dp[0][i-1], dp[1][i-1]);
        }
        if(dp[1][i] < max(dp[0][i-1], dp[1][i-1])) {
            dp[1][i] = max(dp[0][i-1], dp[1][i-1]);
        }
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    dp[0][1] = dp[1][1] = arr[1];
    solution(n);
    cout<<max(dp[0][n], dp[1][n]);
    return 0;
}