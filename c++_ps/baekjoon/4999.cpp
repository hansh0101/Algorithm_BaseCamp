#include <iostream>
#include <cstring>

using namespace std;

int main() {
    string input;
    string output;

    cin >> input >> output;

    if (input.length() < output.length()) {
        cout << "no\n";
    } else {
        cout << "go\n";
    }

    return 0;
}