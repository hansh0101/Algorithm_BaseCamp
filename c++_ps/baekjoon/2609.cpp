#include <iostream>

using namespace std;

int findGcd(int a, int b) {
    if (a < b) {
        swap(a, b);
    }
    if (a % b == 0) {
        return b;
    }
    return findGcd(b, a % b);
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    int gcd = findGcd(n, m);
    int lcm = n * (m / gcd);
    cout << gcd << "\n" << lcm << "\n";
    return 0;
}