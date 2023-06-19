#include <iostream>
#include <vector>

using namespace std;

int n, m, x;
vector<int> vec;
int result;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> x;
        vec.push_back(x);
    }

    int maxLength = 0;
    for (int i = 0; i <= vec.size(); i++) {
        int length = 0;
        if (i == 0) {
            length = (vec[i] - 0) * 2;
        } else if (i == vec.size()) {
            length = (n - vec[vec.size() - 1]) * 2;
        } else {
            length = vec[i] - vec[i - 1];
        }

        if (maxLength < length) {
            maxLength = length;
        }
    }

    if (maxLength % 2 == 0) {
        result = maxLength / 2;
    } else {
        result = maxLength / 2 + 1;
    }

    cout << result << "\n";
    return 0;
}