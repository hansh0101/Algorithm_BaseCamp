#include <iostream>
using namespace std;

int n, k;
int w[101];
int v[101];
int dp[101][100001];
int ans;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin>>n>>k;
    for(int i=1; i<=n; i++) {
        cin>>w[i]>>v[i];
    }

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=k; j++) {
            if(i == 1) {
                if(j-w[1] >= 0)
                    dp[1][j] = v[1];
                continue;
            }

            if(j-w[i] >= 0) {
                dp[i][j] = max(dp[i-1][j-w[i]]+v[i], dp[i-1][j]);
            }
            else {
                dp[i][j] = dp[i-1][j];
            }
        }
        ans = max(ans, dp[i][k]);
    }
    cout<<ans;
    return 0;
}