#include <iostream>

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = n - i; j > 0; j--) {
            cout << " ";
        }
        for (int j = 1; j <= 2 * (i - 1) + 1; j++) {
            cout << "*";
        }
        cout << "\n";
    }
    return 0;
}