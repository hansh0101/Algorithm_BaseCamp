#include <iostream>
using namespace std;

int distA, distB;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> distA >> distB;
    if (distA == distB) {
        cout << "same\n";
    } else if (distA > distB) {
        cout << "A\n";
    } else if (distA < distB) {
        cout << "B\n";
    }

    return 0;
}