#include <iostream>
#include <cstring>

using namespace std;

string input;
string result;

void getInput();
void solve();
void printResult();

bool isWin(char);
bool isFinished();

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    while (true) {
        getInput();
        if (input == "end") {
            break;
        }
        solve();
        printResult();
    }

    return 0;
}

void getInput() {
    cin >> input;
}

bool isWin(char c) {
    if ((input[0] == c && input[1] == c && input[2] == c)
        || (input[3] == c && input[4] == c && input[5] == c)
        || (input[6] == c && input[7] == c && input[8] == c)
        || (input[0] == c && input[3] == c && input[6] == c)
        || (input[1] == c && input[4] == c && input[7] == c)
        || (input[2] == c && input[5] == c && input[8] == c)
        || (input[0] == c && input[4] == c && input[8] == c)
        || (input[2] == c && input[4] == c && input[6] == c)
    ) {
        return true;
    }

    return false;
}

bool isFinished() {
    // O가 이겨서 끝난 경우
    if (isWin('O')) {
        return true;
    }

    // X가 이겨서 끝난 경우
    if (isWin('X')) {
        return true;
    }

    // 아무도 승리 확정이 아니며 게임이 진행 중인 경우
    for (int i = 0; i < input.length(); i++) {
        if (input[i] == '.') {
            return false;
        }
    }

    // 이긴 사람은 없지만 끝난 경우
    return true;
}

void solve() {
    // 1. X와 O의 개수 체크해서 invalid 걸러내기
    int xCount = 0;
    int oCount = 0;
    for (char c : input) {
        if (c == 'X') {
            xCount++;
        } else if (c == 'O') {
            oCount++;
        }
    }

    // O가 X보다 많이 나올 수 없다.
    if (oCount > xCount) {
        result = "invalid";
        return;
    }

    // X가 O보다 2개 이상 더 나올 수 없다.
    if (xCount > oCount + 1) {
        result = "invalid";
        return;
    }

    // 2. X가 더 많이 뒀는데 O가 이긴 경우를 체크해서 invalid 걸러내기
    if (xCount == oCount + 1) {
        if (isWin('O')) {
            result = "invalid";
            return;
        }
    }

    // 3. X와 O가 같은 횟수를 뒀는데 X가 이미 승리조건을 달성한 경우를 체크해서 invalid 걸러내기
    if (xCount == oCount) {
        if (isWin('X')) {
            result = "invalid";
            return;
        }
    }

    // 4. 게임이 최종 상태인지 확인하기
    if (isFinished()) {
        result = "valid";
    } else {
        result = "invalid";
    }
}

void printResult() {
    cout << result << "\n";
}