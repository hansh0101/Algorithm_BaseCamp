#include <string>
#include <vector>
#include <cstring>
#define DIV 1000000007

using namespace std;

int solution(int n) {
    int answer = 0;

    if (n % 2 != 0) {
        return 0;
    }

    long long dp[5001];
    memset(dp, 0, sizeof(dp));
    dp[0] = 0;
    dp[2] = 3;
    dp[4] = 11;
    if (n <= 4) {
        return dp[n];
    }
    for (int i = 6; i <= n; i += 2) {
        dp[i] = 2 + dp[i-2] * 3;
        dp[i] %= DIV;
        for (int j = i - 4; j >= 2; j -= 2) {
            dp[i] += dp[j] * 2;
            dp[i] %= DIV;
        }
    }
    answer = dp[n];

    return answer;
}