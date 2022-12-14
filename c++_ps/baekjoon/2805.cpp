#include <iostream>
#include <algorithm>
using namespace std;

long long int n, m;
long long int tree[1000000];

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> tree[i];
    }

    sort(tree, tree + n);

    long long int left = 0, right = tree[n - 1], mid = (left + right) / 2;

    while (left <= right) {
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            if (tree[i] > mid) {
                sum += tree[i] - mid;
            }
        }

        if (sum < m) {
            right = mid - 1;
            mid = (left + right) / 2;
        }
        else if (sum > m) {
            left = mid + 1;
            mid = (left + right) / 2;
        }
        else {
            break;
        }
    }

    cout << mid << "\n";

    return 0;
}