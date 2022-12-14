#include <iostream>
#include <vector>

using namespace std;

int t, a, b;
vector<int> v;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> t;
    while (t--) {
        v.clear();

        cin >> a >> b;

        int n = a % 10;
        v.push_back(n);
        n = (n * a) % 10;

        while (true) {
            if (n == a % 10) {
                break;
            }

            v.push_back(n);
            n = (n * a) % 10;
        }

        int index = b % v.size() - 1;
        if (index < 0) {
            index = v.size() - 1;
        }

        cout << (v[index] == 0 ? 10 : v[index]) << "\n";
    }
    return 0;
}