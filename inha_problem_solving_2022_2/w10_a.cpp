#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int t, n, a, p, q, x;
vector<int> vec;
int result;

void init();
void input();
void solve();
void print();

void makePermutation(int depth, int n, int r);
bool isInRange();

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> t;
    while (t--) {
        init();
        input();
        solve();
        print();
    }

    return 0;
}

void init() {
    vec.clear();
    result = 0;
}

void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a;
        vec.push_back(a);
    }
    cin >> p >> q >> x;
}

void solve() {
    makePermutation(0, n, n);
}

void print() {
    cout << result << "\n";
}

void makePermutation(int depth, int n, int r) {
    if (depth == r) {
        if (isInRange()) {
            result++;
        }
        return;
    }

    for (int i = depth; i < n; i++) {
        swap(vec[depth], vec[i]);
        makePermutation(depth + 1, n, r);
        swap(vec[depth], vec[i]);
    }
}

bool isInRange() {
    long long calculatedResult = 0;
    for (int i = 0; i < n; i++) {
        long long currentCalculatedResult = ((long long)vec[i] * (long long)pow(x, i)) % (long long)1013;
        calculatedResult = (calculatedResult + currentCalculatedResult) % (long long)1013;
    }

    if (calculatedResult >= p && calculatedResult <= q) {
        return true;
    } else {
        return false;
    }
}