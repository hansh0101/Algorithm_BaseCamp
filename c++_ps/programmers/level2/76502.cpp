#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(string s) {
    int answer = 0;

    for (int i = 0; i < s.length(); i++) {
        stack<char> st;
        bool result = true;
        
        for (int j = 0; j < s.length(); j++) {
            int idx = (i + j) % s.length();
            if (s[idx] == '(' || s[idx] == '{' || s[idx] == '[') {
                st.push(s[idx]);
            } else {
                if (st.empty()) {
                    result = false;
                    break;
                }

                char top = st.top();
                if (top == '(' && s[idx] == ')') {
                    st.pop();
                } else if (top == '{' && s[idx] == '}') {
                    st.pop();
                } else if (top == '[' && s[idx] == ']') {
                    st.pop();
                } else {
                    result = false;
                    break;
                }
            }
        }

        if (result && st.empty()) {
            answer++;
        }
    }

    return answer;
}