#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>

#define ll long long

using namespace std;

int t;
ll m;
vector<int> v;
int result;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> t;
    while (t--) {
        v.clear();
        result = 0;

        cin >> m;
        while (m != 0) {
            v.insert(v.begin(), m % 10);
            m /= 10;
        }
        v.insert(v.begin(), 0);

        for (int i = v.size() - 1; i > 0; i--) {
            if (v[i] >= 10) {
                v[i - 1]++;
                v[i] = 0;
            }

            int num = v[i];
            bool isMinus;
            if (num <= 4) {
                result += num;
                isMinus = true;
            } else if (num == 5) {
                int nextNum = v[i - 1];
                if (nextNum <= 4) {
                    isMinus = true;
                } else if (nextNum >= 5) {
                    isMinus = false;
                }
                result += num;
            } else if (num >= 6) {
                result += 10 - num;
                isMinus = false;
            }
            v[i] = 0;

            if (!isMinus) {
                v[i - 1]++;
            }
        }

        m = 0;
        for (int i = 0; i < v.size(); i++) {
            int num = v[v.size() - 1 - i];
            m += pow(10, i) * num;
        }

        int length = to_string(m).length() - 1;
        ll divider = pow(10, length);
        result += m / divider;

        cout << result << "\n";
    }
    return 0;
}