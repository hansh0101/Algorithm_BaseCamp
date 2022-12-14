#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

string str;
vector<int> nums;
vector<char> opers;
deque<int> num;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> str;
    int idx = 0;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '+' || str[i] == '-') {
            nums.push_back(stoi(str.substr(idx, (i + 1) - idx)));
            opers.push_back(str[i]);
            idx = i + 1;
        }
    }
    nums.push_back(stoi(str.substr(idx, str.length() - idx)));

    num.push_back(nums[0]);
    for (int i = 0; i < opers.size(); i++) {
        char oper = opers[i];
        int m = nums[i + 1];
        if (oper == '+') {
            int n = num.back();
            num.pop_back();
            num.push_back(n + m);
        } else if (oper == '-') {
            num.push_back(m);
        }
    }

    int result = num.front();
    num.pop_front();
    while (!num.empty()) {
        int n = num.front();
        num.pop_front();
        result -= n;
    }
    cout << result << "\n";
    return 0;
}