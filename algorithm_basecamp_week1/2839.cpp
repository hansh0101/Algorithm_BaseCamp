#include <iostream>
#include <cstring>
using namespace std;

int n;
int dp[5001];

int calc(int n) {
    if (n<=5 || dp[n] != -1) {
        return dp[n];
    } else {
       if(calc(n-5) != -1) {
           return dp[n] = calc(n-5) +1;
       }  else if(calc(n-3) != -1) {
           return dp[n] = calc(n-3) + 1;
       } else {
           return dp[n] = -1;
       }
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    memset(dp, -1, sizeof(dp));
    dp[3] = 1;
    dp[5] = 1;
    cin>>n;

    cout<<calc(n);
    return 0;
}