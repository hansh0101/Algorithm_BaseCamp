#include <iostream>
using namespace std;

int n;
int arr[1001];
int dp[1001];

void solution(int num) {
    for(int i=1;i<=num;i++) {
        for(int j=1;j<=i;j++) {
            dp[i] = max(dp[i], arr[j]+dp[i-j]);
        }
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
    cout<<dp[n];
    return 0;
}