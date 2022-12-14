#include <iostream>
#include <algorithm>
#define MAX 1e9
using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n, k;
    int arr[101] = {0};
    int dp[100001];
    cin >> n >> k;

    for (int i = 1; i <= k; i++) {
        dp[i] = MAX;
    }
    dp[0] = 0;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i <= k; i++) {
        for (int j = 0; j < n; j++) {
            if (i + arr[j] <= k) {
                dp[i + arr[j]] = min(dp[i + arr[j]], dp[i] + 1);
            }
        }
    }
    if (dp[k] == MAX) {
        cout << "-1\n";
    } else {
        cout << dp[k] << "\n";
    }

    return 0;
}