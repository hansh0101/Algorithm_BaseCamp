#include <iostream>
#include <algorithm>
using namespace std;

int t, n;
int arr[2][100001];
int dp[2][100001];

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> t;

    while (t--) {
        cin >> n;
        for (int i = 0; i < 2; i++) {
            for (int j = 1; j <= n; j++) {
                arr[i][j] = 0;
                dp[i][j] = 0;
                cin >> arr[i][j];
            }
        }

        dp[0][1] = arr[0][1];
        dp[1][1] = arr[1][1];

        for (int i = 1; i <= n; i++) {
            dp[0][i] = max(dp[1][i - 1] + arr[0][i], dp[1][i - 2] + arr[0][i]);
            dp[1][i] = max(dp[0][i - 1] + arr[1][i], dp[0][i - 2] + arr[1][i]);
        }

        cout << max(dp[0][n], dp[1][n]) << "\n";
    }

    return 0;
}