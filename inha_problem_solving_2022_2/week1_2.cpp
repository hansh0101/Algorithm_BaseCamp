#include <iostream>
#include <cstring>
#include <stack>

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;

        int gauge1 = 0;
        int length1 = 0;
        int result1 = 0;
        for (int i = 0; i < str.length(); i++) {
            char c = str[i];
            if (c == 'C') {
                length1++;
                gauge1++;
            } else {
                if (gauge1 == 0) {
                    result1 = length1 > result1 ? length1 : result1;
                    length1 = 0;
                } else {
                    length1++;
                    gauge1--;
                    if (gauge1 == 0) {
                        result1 = length1 > result1 ? length1 : result1;
                    }
                }
            }
        }

        int gauge2 = 0;
        int length2 = 0;
        int result2 = 0;
        for (int i = str.length() - 1; i >= 0; i--) {
            char c = str[i];
            if (c == 'T') {
                length2++;
                gauge2++;
            } else {
                if (gauge2 == 0) {
                    result2 = length2 > result2 ? length2 : result2;
                    length2 = 0;
                } else {
                    length2++;
                    gauge2--;
                    if (gauge2 == 0) {
                        result2 = length2 > result2 ? length2 : result2;
                    }
                }
            }
        }
        cout << (result1 >= result2 ? result1 : result2) << "\n";
    }
    return 0;
}