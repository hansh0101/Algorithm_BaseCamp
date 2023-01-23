#include <iostream>
#include <cstring>
#include <map>

using namespace std;

int t, n;
string name, type;
map<string, int> dict;
int result;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> t;
    while (t--) {
        dict.clear();
        result = 1;

        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> name >> type;
            dict[type]++;
        }

        for (auto it : dict) {
            result *= (it.second + 1);
        }
        result -= 1;

        cout << result << "\n";
    }
}