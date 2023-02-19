#include <iostream>
using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;

    while (t--) {
        int a, b;
        cin >> a >> b;

        int result = 0;

        if (a != 0) {
            int sumA = 0;
            for (int i = 1; i <= 6; i++) {
                if (sumA < a && a <= sumA + i) {
                    switch (i) {
                        case 1:
                            result += 5000000;
                            break;
                        case 2:
                            result += 3000000;
                            break;
                        case 3:
                            result += 2000000;
                            break;
                        case 4:
                            result += 500000;
                            break;
                        case 5:
                            result += 300000;
                            break;
                        case 6:
                            result += 100000;
                            break;
                    }
                    break;
                }
                sumA += i;
            }
        }

        if (b != 0) {
            int sumB = 0;
            int digit = 1;
            for (int i = 1; i<= 5; i++) {
                if (sumB < b && b <= sumB + digit) {
                    result += 5120000 / digit;
                    break;
                }
                sumB += digit;
                digit *= 2;
            }
        }

        cout << result << "\n";
    }
}