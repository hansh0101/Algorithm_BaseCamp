#include <iostream>
#include <algorithm>
#include <math.h>
#include <cmath>
using namespace std;

int n;
int dp[100001];

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    dp[1] = 1;

    for (int i = 1; i <= n; i++) {
        dp[i] = i;
        for (int j = 1; j <= sqrt(i); j++) {
            dp[i] = min(dp[i], dp[i-j*j] + 1);
        }
    }

    cout << dp[n] << "\n";

    return 0;
}