#include <iostream>
#include <cstring>

using namespace std;

string input;
int result;

void getInput() {
    cin >> input;
}

void solve() {
    result = input.length();

    int aCount = 0;
    for (int i = 0; i < input.length(); i++) {
        if (input[i] == 'a') {
            aCount++;
        }
    }

    int bCount = 0;
    for (int i = 0; i < aCount; i++) {
        if (input[i] == 'b') {
            bCount++;
        }
    }
    result = min(result, bCount);

    for (int i = 0; i < input.length(); i++) {
        if (input[i] == 'b') {
            bCount--;
        }

        if (input[(i + aCount) % input.length()] == 'b') {
            bCount++;
        }

        result = min(result, bCount);
    }
}

void printResult() {
    cout << result << "\n";
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    getInput();
    solve();
    printResult();

    return 0;
}