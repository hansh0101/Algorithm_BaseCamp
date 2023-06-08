#include <iostream>
using namespace std;

int n;
int points = 2;
int result;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        points = 2 * points - 1;
    }

    cout << points * points << "\n";
    return 0;
}