#include <iostream>

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int r1, s;
    cin >> r1 >> s;

    int r2 = 2 * s - r1;
    cout << r2 << "\n";

    return 0;
}