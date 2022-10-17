#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

int T;
string str;
stack<int> st;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;
	while (T--) {
		cin >> str;
		for (char c : str) {
			if (c == '+') {
				int num1 = st.top();
				st.pop();
				int num2 = st.top();
				st.pop();
				st.push(num1 + num2);
			}
			else if (c == '-') {
				int num1 = st.top();
				st.pop();
				int num2 = st.top();
				st.pop();
				st.push(num2 - num1);
			}
			else if (c == '*') {
				int num1 = st.top();
				st.pop();
				int num2 = st.top();
				st.pop();
				st.push(num1 * num2);
			}
			else {
				st.push(c - '0');
			}
		}
		cout << st.top() << "\n";
		st.pop();
	}
}

/*
9
35+
34*
23+
23*5+
452-+
36+67*-
378+-2*
357+2*+
3548--+
*/