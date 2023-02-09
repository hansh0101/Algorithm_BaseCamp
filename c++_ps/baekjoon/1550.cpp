#include <iostream>

using namespace std;

int charToInt(char c) {
    if (c - '0' >= 0 && c - '0' <= 9) {
        return (int) (c - '0');
    }
    return (int) (c - 'A' + 10);
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    string input;
    cin >> input;
    int digit = 1;
    int result = 0;
    for (int i = input.length() - 1; i >= 0; i--) {
        result += charToInt(input[i]) * digit;
        digit *= 16;
    }

    cout << result << "\n";
    return 0;
}