#include <iostream>

using namespace std;

int n;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    if (n % 2 == 0) {
        cout << "CY\n";
    } else {
        cout << "SK\n";
    }

    return 0;
}