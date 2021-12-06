#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, c1, c2, p, q;
int pIdx, qIdx, minDst = 1e9, cnt;
vector<int> v1, v2;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m >> c1 >> c2;
    for (int i = 0; i < n; i++) {
        cin >> p;
        v1.push_back(p);
    }
    for (int i = 0; i < m; i++) {
        cin >> q;
        v2.push_back(q);
    }

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    while(pIdx != n && qIdx != m) {
        int p1, p2;

        if(pIdx == n) p1 = pIdx - 1;
        else p1 = pIdx;
        if(qIdx == m) p2 = qIdx - 1;
        else p2 = qIdx;

        int diff = v1[p1] - v2[p2];

        if(abs(diff) < minDst) {
            minDst = abs(diff);
            cnt = 1;
        }
        else if(abs(diff) == minDst) {
            cnt++;
        }

        if(diff >= 0) {
            if(qIdx != m) qIdx++;
            else break;
        }
        else {
            if(pIdx != n) pIdx++;
            else break;
        }
    }

    cout<<minDst + abs(c1 - c2)<<" "<<cnt;
}