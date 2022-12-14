#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int arr[1000000];
vector<int> vec;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        vec.push_back(arr[i]);
    }

    sort(vec.begin(), vec.end());
    vec.erase(unique(vec.begin(), vec.end()), vec.end());

    for (int i = 0; i < n; i++) {
        int index = lower_bound(vec.begin(), vec.end(), arr[i]) - vec.begin();
        cout << index << " ";
    }
    cout << "\n";

    return 0;
}
