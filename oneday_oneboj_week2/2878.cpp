#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define LL long long

LL M;
int N;
vector <LL> v;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> M >> N;
    LL tmp, sum = -M;
    for (long long i = 0; i < N; i++) {
        cin >> tmp; v.push_back(tmp);
        sum += tmp;
    }

    sort(v.begin(), v.end());

    LL ans = 0;
    for (int i = 0; i < N; i++) {
        LL rmd = min(v[i], sum / (N - i));
        ans += rmd * rmd;
        sum -= rmd;
    }

    cout << ans << "\n";
}