#include <iostream>
using namespace std;

int n;
long long dp[1001];

long long solution(int n) {
    if(dp[n] != 0) {
        return dp[n];
    }
    return dp[n] = (int)(solution(n-1)+solution(n-2))%10007;
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin>>n;
    dp[1] = 1;
    dp[2] = 2;

    cout<<solution(n);
}