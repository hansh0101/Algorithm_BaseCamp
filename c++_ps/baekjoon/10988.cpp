#include <iostream>
#include <cstring>

using namespace std;

string str;
string reverseStr = "";

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> str;
    for (int i = str.length() - 1; i >= 0; i--) {
        reverseStr += str[i];
    }
    
    cout << (str == reverseStr) << "\n";
    return 0;
}