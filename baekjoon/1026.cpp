#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> a;
vector<int> b;
int num;
int result;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num;
        a.push_back(num);
    }
    for (int i = 0; i < n; i++) {
        cin >> num;
        b.push_back(num);
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end(), greater<int>());

    for (int i = 0; i < n; i++) {
        result += a[i] * b[i];
    }

    cout << result << "\n";
    return 0;
}