#include <iostream>

using namespace std;

int n;
int t[15], p[15];

int recursion(int today, int until, int pay) {
    if (today == n) {
        return pay;
    }

    int totalPay1 = 0;
    if (today >= until && today + t[today] <= n) {
        // 상담 가능한 상태이고 상담해봄
        totalPay1 = recursion(today + 1, today + t[today], pay + p[today]);
    }
    // 상담 안 해봄
    int totalPay2 = recursion(today + 1, until, pay);

    return max(totalPay1, totalPay2);
}

void solve() {
    int res = recursion(0, 0, 0);
    cout<<res;
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> t[i] >> p[i];
    }

    solve();
    return 0;
}