#include <iostream>

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int hh, mm, m;
    cin >> hh >> mm >> m;
    int time = 60 * hh + mm + m;
    time = time % (60 * 24);
    hh = time / 60;
    mm = time % 60;
    cout << hh << " " << mm;
    return 0;
}