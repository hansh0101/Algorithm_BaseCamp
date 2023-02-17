#include <iostream>
#include <cstring>

using namespace std;

char convert(char c) {
    if (c >= 'a' && c <= 'z') {
        return (char)('A' + (c - 'a'));
    }
    return (char)('a' + (c - 'A'));
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    string str;
    cin >> str;

    for (int i = 0; i < str.length(); i++) {
        str[i] = convert(str[i]);
    }

    cout << str << "\n";

    return 0;
}