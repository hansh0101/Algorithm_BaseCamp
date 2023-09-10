#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, k, p, x;
bool isOn[10][7];
vector<int> changables[10];
vector<int> xVec;
vector<int> iVec;
int result;

void getInput();
void solve();
void printResult();

void initIsOn();
void xToVec();
void iToVec(int);
int getDiff();

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    getInput();
    solve();
    printResult();

    return 0;
}

void getInput() {
    cin >> n >> k >> p >> x;
}

void initIsOn() {
    isOn[0][0] = true;
    isOn[2][0] = true;
    isOn[3][0] = true;
    isOn[5][0] = true;
    isOn[6][0] = true;
    isOn[7][0] = true;
    isOn[8][0] = true;
    isOn[9][0] = true;
    
    isOn[0][1] = true;
    isOn[1][1] = true;
    isOn[2][1] = true;
    isOn[3][1] = true;
    isOn[4][1] = true;
    isOn[7][1] = true;
    isOn[8][1] = true;
    isOn[9][1] = true;

    isOn[0][2] = true;
    isOn[1][2] = true;
    isOn[3][2] = true;
    isOn[4][2] = true;
    isOn[5][2] = true;
    isOn[6][2] = true;
    isOn[7][2] = true;
    isOn[8][2] = true;
    isOn[9][2] = true;

    isOn[0][3] = true;
    isOn[2][3] = true;
    isOn[3][3] = true;
    isOn[5][3] = true;
    isOn[6][3] = true;
    isOn[8][3] = true;
    isOn[9][3] = true;

    isOn[0][4] = true;
    isOn[2][4] = true;
    isOn[6][4] = true;
    isOn[8][4] = true;
    
    isOn[0][5] = true;
    isOn[4][5] = true;
    isOn[5][5] = true;
    isOn[6][5] = true;
    isOn[8][5] = true;
    isOn[9][5] = true;

    isOn[2][6] = true;
    isOn[3][6] = true;
    isOn[4][6] = true;
    isOn[5][6] = true;
    isOn[6][6] = true;
    isOn[8][6] = true;
    isOn[9][6] = true;
}

void xToVec() {
    int copiedX = x;
    for (int i = 0; i < k; i++) {
        xVec.push_back(copiedX % 10);
        copiedX /= 10;
    }
    reverse(xVec.begin(), xVec.end());
}

void iToVec(int num) {
    for (int i = 0; i < k; i++) {
        xVec.push_back(num % 10);
        num /= 10;
    }
    reverse(xVec.begin(), xVec.end());
}

int getDiff(int num1, int num2) {
    int diff = 0;
    for (int i = 0; i < 7; i++) {
        if (isOn[num1][i] != isOn[num2][i]) {
            diff++;
        }
    }

    return diff;
}

void solve() {
    initIsOn();
    xToVec();

    for (int i = 1; i <= n; i++) {
        if (i == x) {
            continue;
        }

        iToVec(i);
        int diff = 0;
        for (int j = 0; j < xVec.size(); j++) {
            diff += getDiff(xVec[j], iVec[j]);
        }

        if (diff <= p) {
            result++;
        }
    }
}

void printResult() {
    cout << result << "\n";
}