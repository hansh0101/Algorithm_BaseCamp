#include <iostream>

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    long long n;
    cin >> n;

    cout << (n * (n - 1) * (n - 2)) / 6 << "\n3\n";
    return 0;
}