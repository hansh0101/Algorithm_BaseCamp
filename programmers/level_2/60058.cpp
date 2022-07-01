#include <string>
#include <vector>
#include <stack>

using namespace std;

bool checkBalanced(string u) {
    stack<char> st;

    // check
    for (char c: u) {
        if (st.empty()) {
            if (c == '(') {
                st.push(c);
            } else {
                return false;
            }
        } else {
            if (c != st.top()) {
                st.pop();
            } else {
                st.push(c);
            }
        }
    }

    return st.empty();
}

string recursion(string w) {
    if (w.length() == 0) {
        return w;
    }

    string u = "";
    string v = "";
    int left = 0;
    int right = 0;

    // split
    for (int i = 0; i < w.length(); i++) {
        u += w[i];
        if (w[i] == '(') {
            left++;
        } else if (w[i] == ')') {
            right++;
        }

        if (left == right && left != 0) {
            for (int j = i + 1; j < w.length(); j++) {
                v += w[j];
            }
            break;
        }
    }

    // check u
    if (checkBalanced(u)) {
        return u + recursion(v);
    } else {
        string returnString = "(" + recursion(v) + ")";
        for (int i = 1; i < u.length() - 1; i++) {
            if (u[i] == '(') {
                returnString += ")";
            } else if (u[i] == ')') {
                returnString += "(";
            }
        }
        return returnString;
    }
}

string solution(string p) {
    string answer = recursion(p);
    return answer;
}