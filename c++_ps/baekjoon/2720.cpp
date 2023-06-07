#include <iostream>
using namespace std;

int t, c;
int quarter, dime, nickel, penny;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> t;
    while (t--) {
        cin >> c;

        quarter = c / 25;
        c %= 25;

        dime = c / 10;
        c %= 10;

        nickel = c / 5;
        c %= 5;

        penny = c / 1;
        c %= 1;

        cout << quarter << " " << dime << " " << nickel << " " << penny << "\n";
    }

    return 0;
}