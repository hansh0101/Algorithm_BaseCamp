#include <iostream>

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    unsigned long long answer = 0;

    for (int i = 1; i <= n; i++) {
        answer += (n / i) * i;
    }

    cout << answer << "\n";
    return 0;
}