#include <iostream>
using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;

    int sum = 0;
    for (int i = 0; i < k; i++) {
        int holes;
        cin >> holes;
        sum += (holes + 1) / 2;
    }

    cout << (sum >= n ? "YES" : "NO") << "\n";
    return 0;
}