#include <iostream>
#include <cstring>

using namespace std;

string input;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> input;

    int index = 0;
    int number = 0;
    while (index != input.length()) {
        string numberStr = to_string(++number);
        
        for (int i = 0; i < numberStr.length(); i++) {
            if (index == input.length()) {
                break;
            }

            if (numberStr[i] == input[index]) {
                index++;
            }
        }
    }

    cout << number << "\n";
    return 0;
}