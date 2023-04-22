#include <iostream>
#include <cstring>
using namespace std;

string z;
int b;
int result;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> z >> b;
    int digit = 1;
    for (int i = z.length() - 1; i >= 0; i--) {
        int num;
        if (z[i] >= 'A' && z[i] <= 'Z') {
            num = z[i] - 'A' + 10;
        } else {
            num = z[i] - '0';
        }

        result += num * digit;
        digit *= b;
    }

    cout << result << "\n";
    return 0;
}