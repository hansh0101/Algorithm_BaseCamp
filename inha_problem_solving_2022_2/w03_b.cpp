#include <iostream>
#include <vector>

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
            bool isRoundDown;
            if (num <= 4) {
                result += num;
                isRoundDown = true;
            } else if (num == 5) {
                int nextNum = v[i - 1];
                if (nextNum <= 4) {
                    isRoundDown = true;
                } else if (nextNum >= 5) {
                    isRoundDown = false;
                }
                result += num;
            } else if (num >= 6) {
                result += 10 - num;
                isRoundDown = false;
            }
            v[i] = 0;

            if (!isRoundDown) {
                v[i - 1]++;
            }
        }

        result += v[0];

        cout << result << "\n";
    }
    return 0;
}