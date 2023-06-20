#include <iostream>
#define ull unsigned long long

using namespace std;

int n;
int dist[99999];
int price[100000];
ull result;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        cin >> dist[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> price[i];
    }

    for (int i = 0; i < n - 1; i++) {
        int curPrice = price[i];
        int distance = dist[i];
        for (int j = i + 1; j < n - 1; j++) {
            int nextPrice = price[j];
            if (curPrice <= nextPrice) {
                distance += dist[j];
                i++;
            } else {
                break;
            }
        }

        result += (ull) curPrice * (ull) distance;
    }

    cout << result << "\n";
    return 0;
}