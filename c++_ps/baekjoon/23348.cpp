#include <iostream>
using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int a, b, c;
    cin >> a >> b >> c;

    int result = 0;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int sum = 0;

        for (int j = 0; j < 3; j++) {
            int count1, count2, count3;
            cin >> count1 >> count2 >> count3;

            sum += a * count1 + b * count2 + c * count3;
        }

        result = max(result, sum);
    }

    cout << result << "\n";
    return 0;
}