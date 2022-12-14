#include <iostream>

using namespace std;

int a, b, c;
int countArray[7];
int result;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> a >> b >> c;
    countArray[a]++;
    countArray[b]++;
    countArray[c]++;

    // 3개 같은지
    bool flag1 = false;
    int index1 = 0;
    for (int i = 1; i <= 6; i++) {
        if (countArray[i] == 3) {
            flag1 = true;
            index1 = i;
            break;
        }
    }
    if (flag1) {
        cout << 10000 + index1 * 1000 << "\n";
        return 0;
    }

    // 2개 같은지
    bool flag2 = false;
    int index2 = 0;
    for (int i = 1; i <= 6; i++) {
        if (countArray[i] == 2) {
            flag2 = true;
            index2 = i;
            break;
        }
    }
    if (flag2) {
        cout << 1000 + index2 * 100 << "\n";
        return 0;
    }

    int index3 = 0;
    for (int i = 1; i <= 6; i++) {
        if (countArray[i] == 1) {
            index3 = i;
        }
    }
    cout << index3 * 100 << "\n";
    return 0;
}