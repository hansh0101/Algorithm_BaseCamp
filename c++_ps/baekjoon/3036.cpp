#include <iostream>
using namespace std;

int main() {
    int arr[100] = { 0 };
    int gcd[99] = { 0 };
    int lcm[99] = { 0 };
    int n = 0;

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    for (int i = 0; i < n-1; i++) {
        int a = arr[0], b = arr[i + 1], temp = 0;
        while (a != b) {
            if (a > b)
                a = a - b;
            else
                b = b - a;
        }
        gcd[i] = a;
        lcm[i] = (arr[0] * arr[i + 1]) / gcd[i];

        cout << lcm[i] / arr[i + 1] << "/" << lcm[i] / arr[0] << "\n";
    }
    return 0;
}