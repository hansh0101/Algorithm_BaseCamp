#include <iostream>
#include <cstring>
using namespace std;

string s;
int i;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> s;
    cin >> i;
    
    cout << s[i - 1] << "\n";
    return 0;
}