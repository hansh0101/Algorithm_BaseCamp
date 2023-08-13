#include <iostream>
#include <cstring>

using namespace std;

int n;
int memo[1000001];

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;

    memo[0] = 0;
    memo[1] = 1;
    memo[2] = 2;

    for (int i = 3; i <= n; i++) {
        memo[i] = (memo[i - 2] + memo[i - 1]) % 15746;
    }

    cout << memo[n] << "\n";
    return 0;
}