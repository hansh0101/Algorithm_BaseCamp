#include <iostream>
#include <cstring>

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    string str;
    cin >> str;

    int count0 = 0;
    int count1 = 0;

    for (char c : str) {
        if (c == '0') {
            count0++;
        } else if (c == '1') {
            count1++;
        }
    }

    count0 /= 2;
    count1 /= 2;

    for (int i = 0; i < str.length(); i++) {
        if (count1 == 0) {
            break;
        }

        if (str[i] == '1') {
            count1--;
            str[i] = '-';
        }  
    }

    for (int i = str.length() - 1; i >= 0; i--) {
        if (count0 == 0) {
            break;
        }

        if (str[i] == '0') {
            count0--;
            str[i] = '-';
        }
    }

    string result = "";
    for (char c : str) {
        if (c == '-') {
            continue;
        }

        result += c;
    }

    cout << result << "\n";
    return 0;
}