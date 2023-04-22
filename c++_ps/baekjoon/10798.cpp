#include <iostream>
#include <cstring>

using namespace std;

string str[5];
string result = "";

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int maxLength = 0;
    for (int i = 0; i < 5; i++) {
        cin >> str[i];
        if (str[i].length() > maxLength) {
            maxLength = str[i].length();
        }
    }

    for (int i = 0; i < maxLength; i++) {
        for (int j = 0; j < 5; j++) {
            if (str[j].length() <= i) {
                continue;
            }
            result += str[j][i];
        }
    }

    cout << result << "\n";
    return 0;
}