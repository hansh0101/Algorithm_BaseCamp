#include <iostream>
#include <cstring>

#define pii pair<int, int>
using namespace std;

int t;
string str;

pii recursion(const char *s, int l, int r) {
    if (l >= r) return {1, 1};
    else if (s[l] != s[r]) return {0, 1};

    pii result = recursion(s, l + 1, r - 1);
    result.second++;
    return result;
}

pii isPalindrome(const char *s) {
    return recursion(s, 0, strlen(s) - 1);
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> str;
        pii result = isPalindrome(&str[0]);
        cout << result.first << " " << result.second << "\n";
    }
    return 0;
}
