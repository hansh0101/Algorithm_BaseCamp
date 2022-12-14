#include <iostream>
#include <cstring>

using namespace std;

int t, n, d;
int cnt, median;
int calories[100001];
int cntArr[201];

int calcMedian() {
    int medCount = 0;
    int c = -1;
    int med = 0;

    if (d % 2 == 1) {
        for (int i = 0; i <= 200; i++) {
            medCount = medCount + cntArr[i];
            if (medCount > d / 2) {
                med = i * 2;
                break;
            }
        }
    } else {
        for (int i = 0; i <= 200; i++) {
            medCount = medCount + cntArr[i];
            if (medCount >= d / 2 && c == -1) {
                c = i;
            }
            if (medCount >= d / 2 + 1) {
                med = c + i;
                break;
            }
        }
    }

    return med;
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> t;
    while(t--) {
        memset(calories, 0, sizeof(calories));
        memset(cntArr, 0, sizeof(cntArr));
        cnt = 0, median = 0;

        cin >> n >> d;
        for (int i = 1; i<= n; i++) {
            cin >> calories[i];
        }
        for (int i = 1; i<= d; i++) {
            cntArr[calories[i]]++;
        }
        for (int i = d + 1; i <= n; i++) {
            median = calcMedian();
            if (median <= calories[i]) {
                cnt++;
            }
            cntArr[calories[i-d]]--;
            cntArr[calories[i]]++;
        }
        cout << cnt << "\n";
    }
}