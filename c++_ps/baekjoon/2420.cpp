#include <iostream>
using namespace std;

int main() {
    long long n, m;
    cin >> n >> m;
    cout << (n - m >= 0 ? n - m : m - n) << "\n";
    return 0;
}