#include <iostream>
#include <cstring>

using namespace std;

int translateToMin(string num) {
    for (int i = 0; i < num.length(); i++) {
        if (num[i] == '6') {
            num[i] = '5';
        }
    }

    return stoi(num);
}

int translateToMax(string num) {
    for (int i = 0; i < num.length(); i++) {
        if (num[i] == '5') {
            num[i] = '6';
        }
    }

    return stoi(num);
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    string num1, num2;
    cin >> num1 >> num2;

    cout << translateToMin(num1) + translateToMin(num2) << " "
         << translateToMax(num1) + translateToMax(num2) << "\n";

    return 0;
}