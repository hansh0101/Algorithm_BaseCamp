#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

string str;
stack<char> st;
int ans;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin>>str;
    for(int i=0; i<str.size(); i++) {
        if(str[i] == '(') {
            st.push(str[i]);
        }
        else if(str[i] == ')') {
            if(str[i-1] == '(') {
                st.pop();
                ans+=st.size();
            }
            else {
                ans+=1;
                st.pop();
            }
        }
    }
    cout<<ans;
    return 0;
}