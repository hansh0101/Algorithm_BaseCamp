#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int N, d, k, c, n;
vector<int> vec;
map<int, int> m;
int result;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> N >> d >> k >> c;
    for (int i = 0; i < N; i++) {
        cin >> n;
        vec.push_back(n);
    }
    for (int i = 0; i < k; i++) {
        int index = i;
        if (i >= N) {
            index = i % N;
        }
        vec.push_back(vec[index]);
    }

    int start = 0, end = k - 1;
    for (int i = 0 ; i < k; i++) {
        if (m.find(vec[i]) == m.end()) {
            m[vec[i]] = 1;
        } else {
            m[vec[i]]++;
        }
    }
    if (m.find(c) == m.end()) {
        result = m.size() + 1;
    } else {
        result = m.size();
    }

    for (int i = 1; i < N; i++) {
        int deleteValue = vec[i - 1];
        int addValue = vec[i + k - 1];
        if (m[deleteValue] == 1) {
            m.erase(deleteValue);
        } else {
            m[deleteValue]--;
        }
        if (m.find(addValue) == m.end()) {
            m[addValue] = 1;
        } else {
            m[addValue]++;
        }

        if (m.find(c) == m.end()) {
            result = max((int)m.size() + 1, result);
        } else {
            result = max((int)m.size(), result);
        }
    }

    cout << result << "\n";
    return 0;
}