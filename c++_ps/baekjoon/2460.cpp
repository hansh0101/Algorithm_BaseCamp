#include <iostream>

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int result = 0;
    int total = 0;
    for (int i = 0; i < 10; i++) {
        int on, off;
        cin >> off >> on;
        total = total - off + on;
        result = max(result, total);
    }
    cout << result << "\n";
    return 0;
}