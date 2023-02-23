#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    string str = "";
    while (n != 0) {
        str += (char) ((n % 2) + '0');
        n /= 2;
    }

    for (int i = str.length() - 1; i >= 0; i--) {
        n += (str[i] - '0') * pow(2, str.length() - 1 - i);
    }
    cout << n << "\n";

    return 0;
}