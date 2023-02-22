#include <iostream>

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n, t;
    cin >> n >> t;

    int result = 0;
    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;

        if (t >= input) {
            t -= input;
            result++;
        } else {
            break;
        }
    }

    cout << result << "\n";
    return 0;
}