#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

int t, n;
long long result[2];

void init() {
    memset(result, 0, sizeof(result));
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> t;
    while (t--) {
        init();

        cin >> n;

        int i = 2;
        while (pow(2, i - 1) < n) {
            result[0] += (i - 1) * pow(2, i - 2);
            result[1] += (i - 1) * pow(2, i - 2) + pow(2, i - 1);
            i++;
        }
        result[0] += (i - 1);
        result[1] += 2;

        cout << result[0] << " " << result[1] << "\n";
    }
}