#include <iostream>

#define INF 1e9
using namespace std;

int n;
int arr[11];
int oper[4];
int maxValue = -INF;
int minValue = INF;

void recursion(int index, int result);

void solution();

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < 4; i++) {
        cin >> oper[i];
    }

    solution();
    cout<<maxValue<<"\n"<<minValue;
    return 0;
}

void solution() {
    recursion(0, arr[0]);
}

void recursion(int index, int result) {
    if (index == n - 1) {
        maxValue = max(maxValue, result);
        minValue = min(minValue, result);
        return;
    }

    if (oper[0] > 0) {
        oper[0]--;
        recursion(index + 1, result + arr[index + 1]);
        oper[0]++;
    }
    if (oper[1] > 0) {
        oper[1]--;
        recursion(index + 1, result - arr[index + 1]);
        oper[1]++;
    }
    if (oper[2] > 0) {
        oper[2]--;
        recursion(index + 1, result * arr[index + 1]);
        oper[2]++;
    }
    if (oper[3] > 0) {
        oper[3]--;
        recursion(index + 1, result / arr[index + 1]);
        oper[3]++;
    }
}