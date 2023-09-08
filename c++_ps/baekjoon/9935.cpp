#include <iostream>
#include <cstring>
#include <stack>
#include <algorithm>

using namespace std;

string input;
string target;
string result;

stack<char> st;

void getInput();
void solve();
void printResult();

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    getInput();
    solve();
    printResult();

    return 0;
}

void getInput() {
    cin >> input;
    cin >> target;
}

void solve() {
    for (int i = 0; i < input.length(); i++) {
        st.push(input[i]);

        if (input[i] == target[target.length() - 1] && st.size() >= target.length()) {
            string str = "";
            for (int j = 0; j < target.length(); j++) {
                str += st.top();
                st.pop();
            }
            reverse(str.begin(), str.end());

            if (str != target) {
                for (int k = 0; k < str.length(); k++) {
                    st.push(str[k]);
                }
            }
        }
    }

    while (!st.empty()) {
        result += st.top();
        st.pop();
    }

    reverse(result.begin(), result.end());
}

void printResult() {
    cout << (result.length() == 0 ? "FRULA" : result) << "\n";
}