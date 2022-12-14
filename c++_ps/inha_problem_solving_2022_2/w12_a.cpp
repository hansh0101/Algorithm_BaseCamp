#include <iostream>
using namespace std;

int t, x, a, b;

int getDistance(int n) {
    if (n <= a) {
        return 2 * n;
    }
    int r = n / a;
    return getDistance(n - r * a + r * b) + 2 * r * a;
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> t;
    while (t--) {
        cin >> x >> a >> b;
        cout << getDistance(x) << "\n";
    }
}