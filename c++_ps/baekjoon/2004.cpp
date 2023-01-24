#include <iostream>
using namespace std;

int n, m;
int result;

int getCount2(int num) {
    int count = 0;
    while (num >= 2) {
        count += num / 2;
        num /= 2;
    }
    return count;
}

int getCount5(int num) {
    int count = 0;
    while (num >= 5) {
        count += num / 5;
        num /= 5;
    }
    return count;
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    int count2 = getCount2(n) - getCount2(m) - getCount2(n - m);
    int count5 = getCount5(n) - getCount5(m) - getCount5(n - m);
    cout << min(count2, count5) << "\n";

    return 0;
}