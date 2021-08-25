#include <iostream>
using namespace std;

int t, n;
int dp[11];

int solution(int n) {
    if(n<=3) {
        return dp[n];
    }
    else {
        if(dp[n-1] == 0) {
            dp[n-1] = solution(n-1);
        }
        return dp[n] = dp[n-1]+dp[n-2]+dp[n-3];
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;

    cin>>t;
    while(t--) {
        cin>>n;
        cout<<solution(n)<<"\n";
    }

    return 0;
}

/*
 * n-1을 n으로 할 수 있는 방법 -> + 1 -> dp[n-1] 가지 방법
 * n-2를 n으로 할 수 있는 방법 -> + 2 -> dp[n-2] 가지 방법
 * n-3을 n으로 할 수 있는 방법 -> + 3 -> dp[n-3] 가지 방법
 */