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

        if (n > m) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }

    return 0;
}