#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> v;
int result;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        v.push_back(num);
    }

    sort(v.begin(), v.end());
    do {
        int tempResult = 0;
        for (int i = 0; i < v.size() - 1; i++) {
            tempResult += (v[i + 1] - v[i] >= 0) ? v[i + 1] - v[i] : v[i] - v[i + 1];
        }
        result = max(result, tempResult);
    } while (next_permutation(v.begin(), v.end()));

    cout << result << "\n";
    return 0;
}