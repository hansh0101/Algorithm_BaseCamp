#include <iostream>
using namespace std;

int n;
long long dp[2][91];

void solution(int n) {
    if(n <= 2) {
        return;
    }
    for(int i=3;i<=n;i++) {
        dp[0][i] = dp[0][i-1] + dp[1][i-1];
        dp[1][i] = dp[0][i-1];
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    dp[0][1] = dp[1][2] = 0;
    dp[1][1] = dp[0][2] = 1;

    cin>>n;
    solution(n);
    cout<<dp[0][n]+dp[1][n]<<"\n";

    return 0;
}