#include <iostream>
#include <cmath>
#define ll long long

using namespace std;

int t;
ll n;
ll count0, count1;

void init();
void input();
void solve();
void print();

int getExponent(ll num);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> t;
    while (t--) {
        init();
        input();
        solve();
        print();
    }
}

void init() {
    count0 = 0;
    count1 = 0;
}

void input() {
    cin >> n;
}

int getExponent(ll num) {
    int exponent = 0;
    while (num != 1) {
        num /= 2;
        exponent++;
    }
    return exponent;
}

void solve() {
    int exponent = getExponent(n);
    int notShownCount = 0;
    for (int i = 0; i < exponent; i++) {
        count1 += pow(2, exponent - 1);
        if (i != 0) {
            notShownCount += pow(2, i - 1);
        }
        count0 += pow(2, exponent - 1) - notShownCount;
    }
    count1++;
}

void print() {
    cout << count0 << " " << count1 << "\n";
}