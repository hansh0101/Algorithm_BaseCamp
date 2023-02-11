#include <iostream>

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int a, b;
    cin >> a >> b;
    int cnt = 1, result = 0;

    for (int i = 1; i <= 1000; i++) {
        for (int j = 1; j <= i; j++) {
            if (cnt > b) {
                goto label;
            }
            if (a <= cnt && cnt <= b) {
                result += i;
            }
            cnt++;
        }
    }

    label:
    cout << result << "\n";

    return 0;
}