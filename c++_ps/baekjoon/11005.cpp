#include <iostream>
#include <cstring>

using namespace std;

int n, b;
string result = "";

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> b;
    while (n != 0) {
        int remainder = n % b;

        if (remainder >= 10) {
            result += (char) (remainder - 10) + 'A';
        } else {
            result += remainder + '0';
        }

        n /= b;
    }

    for (int i = result.length() - 1; i >= 0; i--) {
        cout << result[i];
    }
    cout << "\n";
    return 0;
}