#include <iostream>
#include <set>
using namespace std;

int n, m;
set<string> s;
int result;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        s.insert(str);
    }
    for (int i = 0; i < m; i++) {
        string str;
        cin >> str;
        if (s.find(str) != s.end()) {
            result++;
        }
    }

    cout << result << "\n";
    return 0;
}