#include <iostream>

using namespace std;

int main() {
     cin.tie(NULL);
     ios::sync_with_stdio(false);

     int k, q, l, b, kn, p;
     cin >> k >> q >> l >> b >> kn >> p;
     cout << 1 - k <<" "<< 1 - q << " " << 2 - l << " " << 2 - b << " " << 2 - kn << " " << 8 - p << "\n";
     return 0;
}