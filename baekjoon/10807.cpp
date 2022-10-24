#include <iostream>
using namespace std;

int n, num, v;
int arr[201];

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num;
        arr[num + 100]++;
    }
    cin >> v;

    cout << arr[v + 100] << "\n";
    return 0;
}