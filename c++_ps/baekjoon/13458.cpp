#include <iostream>
#include <vector>

#define ll long long
using namespace std;

int n;
vector<int> vec;
int b, c;
ll res;

void solve() {
    for (int idx = 0; idx < n; idx++) {
        if (vec[idx] - b > 0) {
            if ((vec[idx] - b) % c == 0) {
                res += 1 + (vec[idx] - b) / c;
            } else {
                res += 1 + (vec[idx] - b) / c + 1;
            }
        } else {
            res += 1;
        }
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        vec.push_back(a);
    }
    cin >> b >> c;

    solve();
    cout << res;
    return 0;
}