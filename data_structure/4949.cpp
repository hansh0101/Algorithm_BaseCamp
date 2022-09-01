#include <iostream>
#include <stack>
#include <cstring>

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    while (true) {
        string str;
        getline(cin, str);

        if (str == ".") {
            break;
        } else {
            stack<bool> st;
            bool result = false;
            bool condition = true;

            for (char c: str) {
                if (c == '(') {
                    st.push(true);
                } else if (c == '[') {
                    st.push(false);
                } else if (c == ')') {
                    if (st.empty()) {
                        condition = false;
                        break;
                    } else {
                        if(!st.top()) {
                            condition = false;
                            break;
                        } else {
                            st.pop();
                        }
                    }
                } else if (c == ']') {
                    if (st.empty()) {
                        condition = false;
                        break;
                    } else {
                        if(st.top()) {
                            condition = false;
                            break;
                        } else {
                            st.pop();
                        }
                    }
                }
            }

            if (condition && st.empty()) {
                result = true;
            }
            cout << (result ? "yes" : "no") << "\n";
        }
    }

    return 0;
}