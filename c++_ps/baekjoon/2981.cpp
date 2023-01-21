#include <iostream>
#include <vector>
#include <cmath>
#include <set>
#include <algorithm>
using namespace std;

int n, num, gcd;
vector<int> nums;
vector<int> diff;
set<int> result;

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

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num;
        nums.push_back(num);
    }
    sort(nums.begin(), nums.end());

    for (int i = 0; i < n - 1; i++) {
        diff.push_back(nums[i + 1] - nums[i]);
        if (i == 0) {
            gcd = diff[i];
        } else {
            gcd = getGcd(gcd, diff[i]);
        }
    }

    result.insert(gcd);
    for (int i = 2; i * i <= gcd; i++) {
        if (gcd % i == 0) {
            result.insert(i);
            result.insert(gcd / i);
        }
    }

    for (auto i : result) {
        cout << i << " ";
    }

    return 0;
}