#include <iostream>

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    long long n;
    cin >> n;

    long long result;
    if (n % 2 == 0) {
        result = n * ((n - 1) / 2) + n / 2;
    } else {
        result = n * ((n - 1) / 2);
    }

    cout << result << "\n2\n";
    return 0;
}