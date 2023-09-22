#include <string>
#include <stack>

using namespace std;

bool solution(string s) {
    bool answer = true;

    stack<char> st;
    for (char c : s) {
        if (c == '(') {
            st.push(c);
        } else if (c == ')') {
            if (st.empty()) {
                answer = false;
                break;
            }
            
            st.pop();
        }
    }
    
    if (answer && !st.empty()) {
        answer = false;
    }

    return answer;
}