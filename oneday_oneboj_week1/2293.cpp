#include <iostream>
using namespace std;

int n, k;
int arr[101];
int dp[10001];

void solution() {
    dp[0] = 1;
    for(int i=1;i<=n;i++) {
        for(int j=arr[i]; j<=k; j++) {
            dp[j] += dp[j-arr[i]];
        }
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin>>n>>k;
    for(int i=1;i<=n;i++) {
        cin>>arr[i];
    }

    solution();

    cout<<dp[k];
    return 0;
}