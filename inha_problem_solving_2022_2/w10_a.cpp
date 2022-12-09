#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int t, n, a, p, q, x;
vector<int> v;
int result;

void init() {
    v.clear();
    result = 0;
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> t;
    while (t--) {
        init();

        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a;
            v.push_back(a);
        }
        cin >> p >> q >> x;
        sort(v.begin(), v.end());

        do {
            long long multiplier = 1;
            long long sum = 0;

            for (int i = 0; i < v.size(); i++) {
                sum = (sum + v[i] * multiplier) % 1013;
                multiplier *= x;
            }
            if (sum >= p && sum <= q) {
                result++;
            }
        } while (next_permutation(v.begin(), v.end()));

        cout << result << "\n";
    }
}