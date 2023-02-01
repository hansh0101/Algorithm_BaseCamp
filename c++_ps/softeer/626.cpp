#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cstring>

using namespace std;

int n, m;
string r;
int s, t;

map<string, vector<pair<int, int>>> dict;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> r;
        dict[r] = vector<pair<int, int>>();
    }
    for (int i = 0; i < m; i++) {
        cin >> r >> s >> t;
        dict[r].push_back({s, t});
    }

    for (auto iter = dict.begin(); iter != dict.end(); iter++) {
        cout << "Room " << iter->first << ":\n";

        vector<string> vec;
        int lastFinishedTime = 9;
        sort(iter->second.begin(), iter->second.end());
        for (auto it: iter->second) {
            if (it.first != lastFinishedTime) {
                if (lastFinishedTime < 10) {
                    vec.push_back('0' + to_string(lastFinishedTime) + '-' + to_string(it.first));
                } else {
                    vec.push_back(to_string(lastFinishedTime) + '-' + to_string(it.first));
                }
            }
            lastFinishedTime = it.second;
        }
        if (lastFinishedTime != 18) {
            if (lastFinishedTime < 10) {
                vec.push_back('0' + to_string(lastFinishedTime) + '-' + to_string(18));
            } else {
                vec.push_back(to_string(lastFinishedTime) + '-' + to_string(18));
            }
        }

        if (vec.empty()) {
            cout  << "Not available\n";
        }  else {
            cout << vec.size() << " available:\n";;
        }

        for (string str: vec) {
            cout << str << "\n";
        }

        if (iter != --dict.end()) {
            cout << "-----\n";
        }
    }
}