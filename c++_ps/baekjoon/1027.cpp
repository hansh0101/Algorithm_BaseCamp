#include <iostream>

using namespace std;

int n;
int buildings[51];
int counts[51];
int result;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> buildings[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            int building1 = buildings[i];
            int building2 = buildings[j];
            double rate = (double)(building2 - building1) / (double)(j - i);

            bool isBlind = false;
            for (int k = i + 1; k < j; k++) {
                double height = (double)building1 + rate * (double)(k - i);
                
                if (height <= buildings[k]) {
                    isBlind = true;
                    break;
                }
            }

            if (!isBlind) {
                counts[i]++;
                counts[j]++;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        result = max(result, counts[i]);
    }

    cout << result << "\n";
    return 0;
}