#include <iostream>

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    unsigned long long k, n;
    cin >> k >> n;

    if (n == 1) {
        cout << -1 << "\n";
    } else {
        cout << ((k * n) % (n - 1) == 0 ? (k * n) / (n - 1) : ((k * n) / (n - 1)) + 1) << "\n";
    }
    return 0;
}

// (x - k) * n >= x
// n * x - k * n >= x
// (n - 1) * x >= k * n
// x >= (k * n) / (n - 1)