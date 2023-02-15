#include <iostream>
using namespace std;

int input;
int minValue = 101;
int sumValue;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    for (int i = 0; i < 7; i++) {
        cin >> input;
        if (input % 2 == 1) {
            minValue = min(minValue, input);
            sumValue += input;
        }
    }

    if (minValue == 101) {
        cout << "-1\n";
    } else {
        cout << sumValue << "\n" << minValue << "\n";
    }

    return 0;
}