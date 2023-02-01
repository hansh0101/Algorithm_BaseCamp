#include <iostream>
#include <cstring>
using namespace std;

int k, m, n;
int tmp;
string secrets = "";
string input = "";

char intToChar(int num) {
    return (char)num + '0';
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> m >> n >> k;

    for (int i = 0; i < m; i++) {
        cin >> tmp;
        secrets += intToChar(tmp);
    }

    for (int i = 0; i < n; i++) {
        cin >> tmp;
        input += intToChar(tmp);
    }

    if (input.find(secrets) != string::npos) {
        cout << "secret\n";
    } else {
        cout << "normal\n";
    }

    return 0;
}