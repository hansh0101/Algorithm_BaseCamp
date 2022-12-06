#include <iostream>
#include <cstring>
#include <stack>

using namespace std;

int t;
string str;
stack<int> st;

void init() {
    while (!st.empty()) {
        st.pop();
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> t;
    while (t--) {
        init();

        cin >> str;
        for (char c: str) {
            if (c - '0' >= 1 && c - '0' <= 9) {
                st.push(c - '0');
            } else {
                int num2 = st.top();
                st.pop();
                int num1 = st.top();
                st.pop();

                if (c == '+') {
                    st.push(num1 + num2);
                } else if (c == '-') {
                    st.push(num1 - num2);
                } else if (c == '*') {
                    st.push(num1 * num2);
                }
            }
        }

        cout << st.top() << "\n";
        st.pop();
    }
}