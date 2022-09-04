#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findGcd(vector<int> v) {
    sort(v.begin(), v.end());
    int gcd = v.front();
    for (int num: v) {
        int a = num;
        int b = gcd;
        while (a % b != 0) {
            int temp = a;
            a = b;
            b = temp % b;
        }
        gcd = b;
    }
    return gcd;
}

void printResult(vector<int> v, int i) {
    for (int num: v) {
        if (num % i == 0) {
            cout << "-1";
            return;
        }
    }
    cout << i;
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<int> inha;
        vector<int> biryong;
        for (int i = 0; i < n; i++) {
            int num;
            cin >> num;
            inha.push_back(num);
        }
        for (int i = 0; i < m; i++) {
            int num;
            cin >> num;
            biryong.push_back(num);
        }

        int inhaGcd = findGcd(inha);
        int biryongGcd = findGcd(biryong);

        printResult(inha, biryongGcd);
        cout << " ";
        printResult(biryong, inhaGcd);
        cout << "\n";
    }

    return 0;
}