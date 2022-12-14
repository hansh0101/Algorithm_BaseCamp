#include <iostream>
#include <cstring>
#include <map>

using namespace std;

int t;
string str;
int sum[10001];
map<int, int> dict;
int result;

void init() {
    memset(sum, 0, sizeof(sum));
    dict.clear();
    result = 0;
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> t;
    while (t--) {
        init();

        cin >> str;
        for (int i = 0; i < str.length(); i++) {
            if (str[i] == '1') {
                sum[i + 1] = sum[i] + 1;
            } else {
                sum[i + 1] = sum[i] - 1;
            }
        }

        for (int i = 0; i <= str.length(); i++) {
            if (dict.find(sum[i]) == dict.end()) {
                dict[sum[i]] = i;
            } else {
                result = max(result, i - dict[sum[i]]);
            }
        }

        cout << result << "\n";
    }
}