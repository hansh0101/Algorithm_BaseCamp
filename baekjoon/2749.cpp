#include <iostream>

#define ull unsigned long long
using namespace std;

ull n;
ull dp[1500000];
int big = 1000000;

void fib(ull num) {
    if(num == 1 || num == 0) {
        return;
    }

    for (int i = 2; i < 1500000; i++) {
        dp[i] = (dp[i-1] + dp[i-2])%big;
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    dp[0] = 0;
    dp[1] = 1;
    fib(n);
    cout << dp[n % 1500000];
    return 0;
}