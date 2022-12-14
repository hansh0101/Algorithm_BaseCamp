#include <iostream>
#include <cstring>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    set<string> s;
    vector<string> v;
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        s.insert(str);
    }
    for (int i = 0; i < m; i++) {
        string str;
        cin >> str;
        if (s.find(str) != s.end()) {
            v.push_back(str);
        }
    }

    sort(v.begin(), v.end());
    cout << v.size() << "\n";
    for (string str: v) {
        cout << str << "\n";
    }

    return 0;
}