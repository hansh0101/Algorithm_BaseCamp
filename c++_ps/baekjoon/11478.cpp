#include <iostream>
#include <cstring>
#include <set>
using namespace std;

string str;
set<string> s;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> str;
    for (int i = 0; i < str.length(); i++) {
        for (int j = 0; j < str.length() - i; j++) {
            string substr = str.substr(i, j + 1);
            s.insert(substr);
        }
    }
    cout << s.size() << "\n";
    return 0;
}