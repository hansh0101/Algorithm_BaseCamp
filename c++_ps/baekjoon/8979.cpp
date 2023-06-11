#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int n, k;
vector<pair<int, pair<int, int>>> vec;
map<int, pair<int, pair<int, int>>> dict;
int result;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int num, gold, silver, bronze;

        cin >> num >> gold >> silver >> bronze;
        pair<int, pair<int, int>> score = {gold, {silver, bronze}};
        dict[num] = score;
        vec.push_back(score);
    }

    sort(vec.begin(), vec.end());
    
    int result = vec.size() + 1 - (upper_bound(vec.begin(), vec.end(), dict[k]) - vec.begin());
    cout << result << "\n";

    return 0;
}