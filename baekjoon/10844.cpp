#include <iostream>
using namespace std;

long long int dp[10][101]; // N=j일 때 마지막 자리의 숫자가 i인 계단 수의 개수를 dp[i][j]에 저장
long long int next[10] = { 1,2,2,2,2,2,2,2,2,1 };
int n; // 1 이상 100 이하

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;

    for (int i = 1; i <= 9; i++) {
        dp[i][1] = 1;
    }

    long long int ret = 0;

    if (n == 1) {
        for (int i = 0; i <= 9; i++) {
            ret += dp[i][1];
        }
        cout << ret << "\n";
        return 0;
    }

    for (int i = 2; i <= n; i++) {
        for (int j = 0; j <= 9; j++) {
            if (j > 0 && j < 9) {
                dp[j][i] = (dp[j - 1][i - 1] + dp[j + 1][i - 1]) % 1000000000;
            }
            else if (j == 0) {
                dp[j][i] = (dp[j + 1][i - 1]) % 1000000000;
            }
            else if (j == 9) {
                dp[j][i] = (dp[j - 1][i - 1]) % 1000000000;
            }
        }
    }

    for (int i = 0; i <= 9; i++) {
        ret += dp[i][n];
    }
    cout << ret % 1000000000 << "\n";
    return 0;
}