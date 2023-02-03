#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    for (int i = n; i >= 4; i--) {
        int num = i;
        bool flag = true;
        while (num != 0) {
            if (num % 10 == 4 || num % 10 == 7) {
                num /= 10;
                continue;
            } else {
                flag = false;
                break;
            }
        }

        if (flag) {
            cout << i << "\n";
            break;
        }
    }

    return 0;
}