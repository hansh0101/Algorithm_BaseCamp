#include <iostream>

using namespace std;

int t, a, b;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> t;
    for (int i = 1; i <= t; i++) {
        cin >> a >> b;
        cout << "Case #" << i << ": " << a + b << "\n";
    }

    return 0;
}