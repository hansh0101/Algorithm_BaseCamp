#include <iostream>

using namespace std;

long long findGcd(long long a, long long b) {
    if (a % b == 0) {
        return b;
    }
    return findGcd(b, a % b);
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    long long a, b;
    cin >> a >> b;

    if (a < b) {
        swap(a, b);
    }

    cout << (a * b) / findGcd(a, b) << "\n";
    return 0;
}