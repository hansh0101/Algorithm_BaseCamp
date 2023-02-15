#include <iostream>
#include <vector>
using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<int> vec;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;

        vec.insert(vec.end() - num, i + 1);
    }

    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }

    return 0;
}