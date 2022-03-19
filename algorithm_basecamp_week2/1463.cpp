#include <iostream>

#define MAX 1e9
using namespace std;

int dp[1000001];
int n;

int solution(int n) {
    if (n <= 3) {
        return dp[n];
    } else {
        if (dp[n] != 0) {
            return dp[n];
        } else {
            int a = MAX, b = MAX, c = MAX;
            if (n % 3 == 0) {
                a = solution(n / 3) + 1;
            }
            if (n % 2 == 0) {
                b = solution(n / 2) + 1;
            }
            c = solution(n - 1) + 1;
            return dp[n] = min(a, min(b, c));
        }
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);


    dp[1] = 0;
    dp[2] = dp[3] = 1;

    cin >> n;
    cout << solution(n);
    return 0;
}