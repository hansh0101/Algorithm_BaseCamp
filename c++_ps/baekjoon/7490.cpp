#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int t, n;

bool check(string str) {
    for (int i = str.length() - 1; i >= 0; i--) {
        if (str[i] == ' ') {
            str.erase(i, 1);
        }
    }

    vector<int> nums;
    vector<char> ops;

    int lastOpIndex = -1;
    for (int i = 0; i <= str.length(); i++) {
        if (i == str.length()) {
            nums.push_back(stoi(str.substr(lastOpIndex + 1, i - (lastOpIndex + 1))));
            break;
        }

        if (str[i] == '+' || str[i] == '-') {
            nums.push_back(stoi(str.substr(lastOpIndex + 1, i - (lastOpIndex + 1))));
            ops.push_back(str[i]);
            lastOpIndex = i;
        }
    }

    int sum = nums[0];
    for (int i = 0; i < ops.size(); i++) {
        if (ops[i] == '+') {
            sum += nums[i + 1];
        } else if (ops[i] == '-') {
            sum -= nums[i + 1];
        }
    }

    return sum == 0;
}

void backTracking(int count, string str) {
    str.push_back((char)('0' + count));

    if (count == n) {
        if (check(str)) {
            cout << str << "\n";
        }
        return;
    }

    str.push_back(' ');
    backTracking(count + 1, str);
    str.pop_back();

    str.push_back('+');
    backTracking(count + 1, str);
    str.pop_back();

    str.push_back('-');
    backTracking(count + 1, str);
    str.pop_back();
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    // cin >> t;
    t = 1;
    while (t--) {
        // cin >> n;
        n = 3;

        backTracking(1, "");

        cout << "\n";
    }
}