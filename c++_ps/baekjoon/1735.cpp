#include <iostream>

using namespace std;

int getGcd(int num1, int num2) {
    if (num1 < num2) {
        swap(num1, num2);
    }

    if (num1 % num2 == 0) {
        return num2;
    }
    return getGcd(num2, num1 % num2);
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int a, b, c, d;
    cin >> a >> b >> c >> d;

    // 1. 공통분모 찾기
    int gcdBD = getGcd(b, d);
    int lcmBD = (b * d) / gcdBD; // 공통분모 = lcmBD

    // 2. 분자, 분모 계산
    int upper = a * (lcmBD / b) + c * (lcmBD / d);
    int lower = lcmBD;

    // 3. 기약분수 형태로 바꾸기
    int gcdUL = getGcd(upper, lower);
    upper /= gcdUL;
    lower /= gcdUL;

    cout << upper << " " << lower << "\n";
    return 0;
}