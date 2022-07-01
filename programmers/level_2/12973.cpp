#include <string>
#include <stack>
using namespace std;

int solution(string s) {
    stack<char> st;
    for (int i = 0; i < s.length(); i++) {
        char c = s[i];

        if (st.empty()) {
            st.push(c);
        } else {
            char top = st.top();
            if (top == c) {
                st.pop();
            } else {
                st.push(c);
            }
        }
    }

    if (st.empty()) {
        return 1;
    } else {
        return 0;
    }
}