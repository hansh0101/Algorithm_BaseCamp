#include <iostream>

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;

    int numerator = 1;
    int denominator = 1;

    for (int i = 1; i <= k; i++) {
        denominator *= i;
        numerator *= (n + 1) - i;
    }

    cout << numerator / denominator << "\n";
    return 0;
}