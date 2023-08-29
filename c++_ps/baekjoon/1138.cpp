#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> counts;
vector<int> result;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int count;
        cin >> count;
        counts.push_back(count);
    }

    for (int i = counts.size() - 1; i >= 0; i--) {
        int number = i + 1;
        result.insert(result.begin() + counts[i], number);
    }

    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << "\n";

    return 0;
}