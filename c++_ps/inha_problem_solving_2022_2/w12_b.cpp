#include <iostream>
#include <set>
using namespace std;

int t, n, ability;
set<pair<int, int>> s;

void init() {
    s.clear();
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> t;
    while (t--) {
        init();

        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> ability;
            auto iter = s.insert({ability, i});
            if (iter.first == s.begin()) {
                cout << "-1 ";
            } else {
                cout << (--iter.first)->second << " ";
            }
        }
        cout << "\n";
    }
}