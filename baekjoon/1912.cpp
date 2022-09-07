#include <iostream>
#define MINF -1e9
using namespace std;

int n;
int arr[100001];
int dp[100001];
int ans = MINF;

void solution(int n) {
    for(int i=1;i<=n;i++) {
        dp[i] = max(dp[i - 1] + arr[i], arr[i]);
        ans = max(ans, dp[i]);
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>arr[i];
    }

    solution(n);
    cout<<ans;
    return 0;
}