#include <iostream>
#include <stack>

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n;
    stack<int> st;

    cin >> n;
    while (n--) {
        int input;
        cin >> input;

        if (input == 0) {
            st.pop();
        } else {
            st.push(input);
        }
    }

    int result = 0;
    while (!st.empty()) {
        result += st.top();
        st.pop();
    }

    cout << result;
    return 0;
}