#include <iostream>

using namespace std;

int n, k;
int cnt;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            cnt++;

            if (cnt == k) {
                cout << i << "\n";
                return 0;
            }
        }
    }

    cout << 0 << "\n";
    return 0;
}