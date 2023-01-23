#include <iostream>
using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    int result = 0;

    for (int i = 1; i <= n; i++) {
        int cur = i;
        while (cur % 5 == 0 && cur != 0) {
            result++;
            cur /= 5;
        }
    }

    cout << result << "\n";
    return 0;
}