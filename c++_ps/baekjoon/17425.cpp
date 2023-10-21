#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;

    unsigned long long answer[1000001] = {0, };
    for (int i = 1; i <= 1000000; i++) {
        for (int j = 1; i * j <= 1000000; j++) {
            answer[i * j] += i;
        }
        answer[i] += answer[i - 1];
    }

    while (t--) {
        int n;
        cin >> n;

        cout << answer[n] << "\n";
    }

    return 0;
}