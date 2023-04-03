#include <iostream>
#include <cstring>
using namespace std;

int n;
string result = "";

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n / 4; i++) {
        result += "long ";
    }
    result += "int";

    cout << result << "\n";
    return 0;
}