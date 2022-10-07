#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    while (true) {
        int n;
        cin >> n;
        if (n == 0) break;
        string str = to_string(n);
        string rStr = str;
        reverse(rStr.begin(), rStr.end());
        cout << (str.compare(rStr) == 0 ? "yes" : "no") << "\n";
    }
    return 0;
}