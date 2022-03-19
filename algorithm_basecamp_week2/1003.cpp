#include <iostream>
#include <string.h>
using namespace std;

int t, n;
int dp[2][41];

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    memset(dp, -1, sizeof(dp));
    dp[0][0] = 1;
    dp[1][0] = 0;
    dp[0][1] = 0;
    dp[1][1] = 1;

    cin>>t;
    while(t--) {
        cin>>n;

        if(dp[0][n] != -1 && dp[1][n] != -1) {
            cout<<dp[0][n]<<" "<<dp[1][n]<<"\n";
            continue;
        }

        for(int i=2;i<=n;i++) {
            dp[0][i] = dp[0][i-2] + dp[0][i-1];
            dp[1][i] = dp[1][i-2] + dp[1][i-1];
        }
        cout<<dp[0][n]<<" "<<dp[1][n]<<"\n";
    }
}