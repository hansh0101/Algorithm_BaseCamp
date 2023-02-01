#include <iostream>
using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    int points = 2;
    for (int i = 0; i < n; i++) {
        points = points * 2 - 1;
    }

    cout << points * points << "\n";
    return 0;
}