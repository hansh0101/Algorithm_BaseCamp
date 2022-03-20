#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

int n;
string str;
vector<int> num;
vector<char> op;
vector<int> myNum;
vector<char> myOp;
int res = INT_MIN;

void calculate() {
    int myRes = myNum[0];
    for (int i = 0; i < myOp.size(); i++) {
        switch (myOp[i]) {
            case '+':
                myRes += myNum[i + 1];
                break;
            case '-':
                myRes -= myNum[i + 1];
                break;
            case '*':
                myRes *= myNum[i + 1];
                break;
            default:;
        }
    }

    res = max(res, myRes);
}

void recursion(int index) {
    // TODO: 재귀 종료 조건 필요
    // INFO: index == num.size()가 되면 재귀를 종료
    if (index == num.size()) {
        calculate();
        return;
    }

    // TODO: num[index]와 num[index + 1] 을 괄호로 묶는 경우
    // INFO: index + 1이 out of range 인지 판단할 조건이 필요
    // index + 1이 out of range 인 경우 괄호로 묶을 수 없음
    if (index + 1 < num.size()) {
        int tmpNum1 = num[index];
        int tmpNum2 = num[index + 1];
        char tmpOp = op[index];
        int tmpNum;

        switch (tmpOp) {
            case '+':
                tmpNum = tmpNum1 + tmpNum2;
                break;
            case '-':
                tmpNum = tmpNum1 - tmpNum2;
                break;
            case '*':
                tmpNum = tmpNum1 * tmpNum2;
                break;
            default:;
        }

        myNum.push_back(tmpNum);
        if (index + 1 < op.size()) {
            myOp.push_back(op[index + 1]);
        }

        recursion(index + 2);

        myNum.pop_back();
        if (index + 1 < op.size()) {
            myOp.pop_back();
        }
    }

    // TODO: num[index]와 num[index + 1] 을 괄호로 묶지 않는 경우
    myNum.push_back(num[index]);
    if (index < op.size()) {
        myOp.push_back(op[index]);
    }

    recursion(index + 1);

    myNum.pop_back();
    if (index < op.size()) {
        myOp.pop_back();
    }
}

void solution() {
    recursion(0);
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        if (i % 2 == 0) {
            num.push_back(c - '0');
        } else {
            op.push_back(c);
        }
    }

    solution();
    cout << res;
    return 0;
}