#include <iostream>
#include <cstring>

using namespace std;

int t;
string x, y;
int result;
int dp[1001][1001];

void init();

void input();

void solve();

void print();

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> t;
    while (t--) {
        init();
        input();
        solve();
        print();
    }
}

void init() {
    memset(dp, 0, sizeof(dp));
}

void input() {
    cin >> x >> y;
}

void solve() {
    for (int i = 0; i <= x.length(); i++) {
        dp[i][0] = i;
    }
    for (int j = 0; j <= y.length(); j++) {
        dp[0][j] = j;
    }

    for (int i = 1; i <= x.length(); i++) {
        for (int j = 1; j <= y.length(); j++) {
            if (x[i - 1] == y[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
            }
        }
    }

    result = dp[x.length()][y.length()];
}

void print() {
    cout << result << "\n";
}