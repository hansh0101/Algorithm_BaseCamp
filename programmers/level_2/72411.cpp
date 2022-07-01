#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;

    for (auto &order: orders) {
        sort(order.begin(), order.end());
    }

    for (auto c: course) {
        map<string, int> m;
        for (auto order: orders) {
            if (order.length() > c) {
                vector<bool> comb(order.length() - c, false);
                for (int i = 0; i < c; i++) { comb.push_back(true); }

                do {
                    string tmp = "";
                    for (int i = 0; i < order.length(); i++) {
                        if (comb[i]) tmp += order[i];
                    }
                    m[tmp]++;
                } while (next_permutation(comb.begin(), comb.end()));
            } else if (order.length() == c) {
                m[order]++;
            }
        }

        int maxValue = max_element(m.begin(), m.end(), [](const pair<string, int> &x, const pair<string, int> &y) {
            return x.second < y.second;
        })->second;
        if (maxValue < 2) continue;

        for (auto iter: m) {
            if (iter.second == maxValue) {
                answer.push_back(iter.first);
            }
        }
    }

    sort(answer.begin(), answer.end());

    return answer;
}