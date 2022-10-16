#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

string S;
string T;
bool result;

void solution(string str) {
    if (str == S) {
        result = true;
        return;
    }
    if (str.length() == S.length()) {
        return;
    }

    if (str[str.length() - 1] == 'A') {
        solution(str.substr(0, str.length() - 1));
    }
    if (str[0] == 'B') {
        reverse(str.begin(), str.end());
        solution(str.substr(0, str.length() - 1));
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> S >> T;
    solution(T);
    cout << (result ? 1 : 0) << "\n";
    return 0;
}