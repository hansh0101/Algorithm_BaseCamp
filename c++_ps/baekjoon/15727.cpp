#include <iostream>

using namespace std;

int main() {
    int l;
    cin >> l;

    int result = l / 5;
    if (l % 5 != 0) {
        result++;
    }
    cout << result << "\n";
    return 0;
}