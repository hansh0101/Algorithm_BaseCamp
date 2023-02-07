#include <iostream>
#include <vector>

using namespace std;

void makeCombination(const vector<int> &vec, vector<int> v, int idx) {
    if (v.size() == 6) {
        for (int i: v) {
            cout << i << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = idx; i < vec.size(); i++) {
        v.push_back(vec[i]);
        makeCombination(vec, v, i + 1);
        v.pop_back();
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    while (true) {
        int s;
        cin >> s;

        if (s == 0) {
            break;
        }

        vector<int> vec;
        for (int i = 0; i < s; i++) {
            int num;
            cin >> num;
            vec.push_back(num);
        }

        makeCombination(vec, vector<int>(), 0);
        cout << "\n";
    }

    return 0;
}