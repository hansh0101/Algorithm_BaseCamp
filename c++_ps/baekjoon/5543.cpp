#include <iostream>
using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int burger, minBurger = 2000, beverage, minBeverage = 2000;
    for (int i = 0; i < 3; i++) {
        cin >> burger;
        minBurger = min(minBurger, burger);
    }
    for (int i = 0; i < 2; i++) {
        cin >> beverage;
        minBeverage = min(minBeverage, beverage);
    }

    cout << minBurger + minBeverage - 50;

    return 0;
}