#include <iostream>
#include <cstring>

using namespace std;

int n;
string input;
int result = 500001;

void getInput() {
    cin >> n;
    cin >> input;
}

void solve() {
    // 1. 색상 별 공의 개수 확인
    int redCount = 0;
    int blueCount = 0;
    for (char c : input) {
        if (c == 'R') {
            redCount++;
        } else if (c == 'B') {
            blueCount++;
        }
    }

    // 2. 왼쪽으로 공을 모으는 경우
    char leftColor = input[0];
    int count = 0;
    for (int i = 0; i < input.length(); i++) {
        if (input[i] == leftColor) {
            count++;
        } else {
            break;
        }
    }

    if (leftColor == 'R') {
        result = min(result, min(blueCount, redCount - count));
    } else if (leftColor == 'B') {
        result = min(result, min(redCount, blueCount - count));
    }

    // 3. 오른쪽으로 공을 모으는 경우
    char rightColor = input[input.length() - 1];
    count = 0;
    for (int i = input.length() - 1; i >= 0; i--) {
        if (input[i] == rightColor) {
            count++;
        } else {
            break;
        }
    }

    if (rightColor == 'R') {
        result = min(result, min(blueCount, redCount - count));
    } else if (rightColor == 'B') {
        result = min(result, min(redCount, blueCount - count));
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