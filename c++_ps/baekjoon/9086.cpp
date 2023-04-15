#include <iostream>
#include <cstring>

using namespace std;

int t;
string str;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> t;
    while (t--) {
        cin >> str;
        cout << str[0] << str[str.length() - 1] << "\n";
    }
    return 0;
}