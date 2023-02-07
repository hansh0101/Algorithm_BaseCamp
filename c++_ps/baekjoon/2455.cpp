#include <iostream>
using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int total = 0;
    int result = 0;
    for (int i = 0; i < 4; i++) {
        int out, in;
        cin >> out >> in;
        total = total - out + in;
        result = max(result, total);
    }

    cout << result << "\n";
    return 0;
}