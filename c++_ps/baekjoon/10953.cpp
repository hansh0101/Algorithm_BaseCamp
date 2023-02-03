#include <iostream>
#include <cstring>

using namespace std;

pair<int, int> splitString(string str, char c) {
    pair<int, int> p;
    int index = 0;
    for (int i = 0; i <= str.length(); i++) {
        if (i == str.length()) {
            p.second = stoi(str.substr(index, i - index));
            break;
        }

        if (str[i] == c) {
            p.first = stoi(str.substr(index, i - index));
            index = i + 1;
        }
    }
    return p;
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;

    while (t--) {
        string str;
        cin >> str;
        pair<int, int> p = splitString(str, ',');
        cout << p.first + p.second << "\n";
    }

    return 0;
}