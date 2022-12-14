#include <iostream>
#include <set>
using namespace std;

int n, m, num;
set<int> s1;
set<int> s2;
set<int> s;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> num;
        s1.insert(num);
    }
    for (int i = 0; i < m; i++) {
        cin >> num;
        s2.insert(num);
    }

    for (int i: s1) {
        if (s2.find(i) == s2.end()) {
            s.insert(i);
        }
    }
    for (int i: s2) {
        if (s1.find(i) == s1.end()) {
            s.insert(i);
        }
    }

    cout << s.size() << "\n";
    return 0;
}