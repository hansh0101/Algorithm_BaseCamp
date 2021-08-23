#include <iostream>
#include <cmath>

using namespace std;

long long n, k;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    while (cin >> n >> k) {
        long long ret = n;
        long long stamp = n;
        for (int i = 1; i <= (int) (log(n) / log(k)); i++) {
            ret += n / (long long) (pow(k, i)) + stamp / k;
            stamp = stamp / k + stamp % k;
        }
        cout << ret << "\n";
    }
}