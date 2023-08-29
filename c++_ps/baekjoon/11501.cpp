#include <iostream>
#include <vector>

using namespace std;

int t;
int n;
int price;
vector<int> prices;
long long result;

void reset() {
    prices.clear();
    result = 0;
}

void getInput() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> price;
        prices.push_back(price);
    }
}

void solve() {
    int maxPrice = 0;

    for (int i = prices.size() - 1; i >= 0; i--) {
        int price = prices[i];

        if (price > maxPrice) {
            maxPrice = price;
        } else if (price == maxPrice) {
            // 아무것도 하지 않는다.
        } else if (price < maxPrice) {
            result += (maxPrice - price);
        }
    }
}

void printResult() {
    cout << result << "\n";
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> t;
    while (t--) {
        reset();
        getInput();
        solve();
        printResult();
    }
}