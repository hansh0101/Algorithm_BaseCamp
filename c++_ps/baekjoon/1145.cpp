#include <iostream>
using namespace std;

int nums[5];
int result = 1e9;

int getGcd(int a, int b) {
    if (a < b) {
        swap(a, b);
    }
    if (a % b == 0) {
        return b;
    } else {
        return getGcd(b, a % b);
    }
}

void findLcm(int a, int b, int c) {
    int lcm1 = (a * b) / getGcd(a, b);
    int lcm2 = (lcm1 * c) / getGcd(lcm1, c);
    result = min(result, lcm2);
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    for (int i = 0; i < 5; i++) {
        cin >> nums[i];
    }

    for (int i = 0; i < 5; i++) {
        for (int j = i + 1; j < 5; j++) {
            for (int k = j + 1; k < 5; k++) {
                findLcm(nums[i], nums[j], nums[k]);
            }
        }
    }

    cout << result << "\n";
    return 0;
}