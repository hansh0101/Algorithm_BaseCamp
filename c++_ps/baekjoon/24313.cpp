#include <iostream>

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int a1, a0, c, n0;
    cin >> a1 >> a0 >> c >> n0;

    if (a1 * n0 + a0 <= c * n0 && a1 <= c) {
        cout << "1\n";
    } else {
        cout << "0\n";
    }

    return 0;
}