#include <iostream>

using namespace std;

int dp[21][21][21];

int solve(int a, int b, int c) {
    if (a <= 0 || b <= 0 || c <= 0) {
        return 1;
    }
    if (a > 20 || b > 20 || c > 20) {
        if (dp[20][20][20] == 0) {
            dp[20][20][20] = solve(20, 20, 20);
        }

        return dp[20][20][20];
    }
    if (a < b && b < c) {
        if (dp[a][b][c] == 0) {
            if (dp[a][b][c - 1] == 0) {
                dp[a][b][c - 1] = solve(a, b, c - 1);
            }

            if (dp[a][b - 1][c - 1] == 0) {
                dp[a][b - 1][c - 1] = solve(a, b - 1, c - 1);
            }

            if (dp[a][b - 1][c] == 0) {
                dp[a][b - 1][c] = solve(a, b - 1, c);
            }

            dp[a][b][c] = dp[a][b][c - 1] + dp[a][b - 1][c - 1] - dp[a][b - 1][c];
        }

        return dp[a][b][c];
    }

    if (dp[a][b][c] == 0) {
        if (dp[a - 1][b][c] == 0) {
            dp[a - 1][b][c] = solve(a - 1, b, c);
        }

        if (dp[a - 1][b - 1][c] == 0) {
            dp[a - 1][b - 1][c] = solve(a - 1, b - 1, c);
        }

        if (dp[a - 1][b][c - 1] == 0) {
            dp[a - 1][b][c - 1] = solve(a - 1, b, c - 1);
        }

        if (dp[a - 1][b - 1][c - 1] == 0) {
            dp[a - 1][b - 1][c - 1] = solve(a - 1, b - 1, c - 1);
        }

        dp[a][b][c] = dp[a - 1][b][c] + dp[a - 1][b - 1][c] + dp[a - 1][b][c - 1] - dp[a - 1][b - 1][c - 1];
    }

    return dp[a][b][c];
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    while (true) {
        int a, b, c;
        cin >> a >> b >> c;

        if (a == -1 && b == -1 && c == -1) {
            break;
        }

        cout << "w(" << a << ", " << b << ", " << c << ") = " << solve(a, b, c) << "\n";
    }

    return 0;
}