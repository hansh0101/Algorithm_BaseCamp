#include <iostream>

using namespace std;

int main() {
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;

    bool find = false;
    for (int i = -999; i <= 999; i++) {
        for (int j = -999; j <= 999; j++) {
            if (a * i + b * j == c && d * i + e * j == f) {
                cout << i << " " << j << "\n";
                goto FIND;
            }
        }
    }

    FIND: 
    return 0;
}