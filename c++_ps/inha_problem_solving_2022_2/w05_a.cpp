#include <iostream>
#include <cstring>
#include <set>

using namespace std;

int t;
string str1, str2;
set<char> s1, s2;

void init() {
    str1 = "";
    str2 = "";
    s1.clear();
    s2.clear();
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> t;
    while (t--) {
        init();
        cin >> str1 >> str2;

        for (char c: str1) {
            s1.insert(c);
        }
        for (char c: str2) {
            s2.insert(c);
        }

        bool result = true;
        for (char c : s1) {
            if (s2.find(c) == s2.end()) {
                result = false;
            }
        }
        for (char c : s2) {
            if (s1.find(c) == s1.end()) {
                result = false;
            }
        }

        cout << (result ? "YES" : "NO") << "\n";
    }
    return 0;
}