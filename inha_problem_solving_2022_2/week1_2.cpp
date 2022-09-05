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

        stack<char> stack1;
        int length1 = 0;
        int result1 = 0;
        for (int i = 0; i < str.length(); i++) {
            char c = str[i];
            if (c == 'C') {
                length1++;
                stack1.push(c);
            } else {
                if (stack1.empty()) {
                    result1 = length1 > result1 ? length1 : result1;
                    length1 = 0;
                } else {
                    length1++;
                    stack1.pop();
                    if (stack1.empty()) {
                        result1 = length1 > result1 ? length1 : result1;
                    }
                }
            }
        }

        stack<int> stack2;
        int length2 = 0;
        int result2 = 0;
        for (int i = str.length() - 1; i >= 0; i--) {
            char c = str[i];
            if (c == 'T') {
                length2++;
                stack2.push(c);
            } else {
                if (stack2.empty()) {
                    result2 = length2 > result2 ? length2 : result2;
                    length2 = 0;
                } else {
                    length2++;
                    stack2.pop();
                    if (stack2.empty()) {
                        result2 = length2 > result2 ? length2 : result2;
                    }
                }
            }
        }
        cout << (result1 >= result2 ? result1 : result2) << "\n";
    }
    return 0;
}