#include <iostream>
#include <cstring>

using namespace std;

int t;
string x, y;
int result[1001][1001];

void init() {
    memset(result, 0, sizeof(result));
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> t;
    while (t--) {
        init();

        cin >> x >> y;
        for (int r = 1; r <= x.length(); r++) {
            result[r][0] = r;
        }
        for (int c = 1; c <= y.length(); c++) {
            result[0][c] = c;
        }
        for (int r = 1; r <= x.length(); r++) {
            for (int c = 1; c <= y.length(); c++) {
                if (x[r - 1] == y[c - 1]) {
                    result[r][c] = result[r - 1][c - 1];
                } else {
                    result[r][c] = min(result[r - 1][c - 1], min(result[r][c - 1], result[r - 1][c])) + 1;
                }
            }
        }

        cout << result[x.length()][y.length()] << "\n";
    }
}