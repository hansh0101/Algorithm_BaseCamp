#include <iostream>
using namespace std;

int n;
int arr[301];
int dp[2][301];

int solution(int n) {
    if(n == 1) {
        return dp[0][1];
    }

    for(int i=2;i<=n;i++) {
        dp[0][i] = dp[1][i-1] + arr[i];
        dp[1][i] = max(dp[0][i-2], dp[1][i-2]) + arr[i];
    }

    return max(dp[0][n], dp[1][n]);
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>arr[i];
    }

    dp[0][1] = dp[1][1] = arr[1];

    cout<<solution(n);

    return 0;
}