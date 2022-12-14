#include <iostream>
using namespace std;

int x, n, a, b;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> x;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        x -= a * b;
    }

    if (x == 0) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }

    return 0;
}