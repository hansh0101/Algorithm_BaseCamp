#include <iostream>
using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n, m;
    while (cin >> n >> m) {
        if (n == 0 && m == 0) {
            break;
        }
        if (m % n == 0) {
            cout << "factor\n";
            continue;
        }
        if (n % m == 0) {
            cout << "multiple\n";
            continue;
        }
        cout << "neither\n";
    }

    return 0;
}