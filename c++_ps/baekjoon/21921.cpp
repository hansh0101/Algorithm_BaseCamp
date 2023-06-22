#include <iostream>
#include <vector>

using namespace std;

int n, x;
int visitor;
vector<int> visitors;
int result = 0;
int cnt = 0;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> x;
    for (int i = 0; i < n; i++) {
        cin >> visitor;
        visitors.push_back(visitor);
    }

    int sum = 0;
    for (int i = 0; i < x; i++) {
        sum += visitors[i];
        result = sum;
        cnt = 1;
    }

    for (int i = x; i < n; i++) {
        sum -= visitors[i - x];
        sum += visitors[i];
        
        if (result < sum) {
            result = sum;
            cnt = 1;
        } else if (result == sum) {
            cnt++;
        }
    }

    if (result == 0) {
        cout << "SAD\n";
    } else {
        cout << result << "\n" << cnt << "\n";
    }

    return 0;
}