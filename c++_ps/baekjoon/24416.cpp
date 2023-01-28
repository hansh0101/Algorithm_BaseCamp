#include <iostream>
using namespace std;

int n;
int dp[41];
int count1, count2;

int fibonacciRecursion(int num) {
    if (num == 1 || num == 2) {
        count1++;
        return num;
    } else {
        return fibonacciRecursion(num - 1) + fibonacciRecursion(num - 2);
    }
}

int fibonacciDynamicProgramming(int num) {
    dp[1] = dp[2] = 1;
    for (int i = 3; i <= num; i++) {
        count2++;
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[num];
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    fibonacciRecursion(n);
    fibonacciDynamicProgramming(n);
    cout << count1 << " " << count2 << "\n";
}