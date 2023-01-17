#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int w, n, m, p;
vector<pair<int, int>> vec;
int result;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> w >> n;
    for (int i = 0; i < n; i++) {
        cin >> m >> p;
        vec.push_back({p, m});
    }
    sort(vec.begin(), vec.end(), greater<pair<int, int>>());

    for (int i = 0; i < vec.size(); i++) {
        if (w == 0) {
            break;
        }

        if (w >= vec[i].second) {
            result += vec[i].first * vec[i].second;
            w -= vec[i].second;
        } else {
            result += vec[i].first * w;
            w = 0;
        }
    }

    cout << result << "\n";
    return 0;
}