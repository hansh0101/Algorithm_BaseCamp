#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 10001

using namespace std;

struct PathInfo {
    int endPoint;
    int distance;

    PathInfo(int endPoint, int distance) {
        this->endPoint = endPoint;
        this->distance = distance;
    }
};

int n, d;
int from, to, dist;
vector<PathInfo> paths[10001];
int dp[10001];
int result;

void getInput() {
    cin >> n >> d;
    for (int i = 0; i < n; i++) {
        cin >> from >> to >> dist;
        paths[from].push_back(PathInfo(to, dist));
    }
}

void solve() {
    for (int i = 0; i <= d; i++) {
        dp[i] = MAX;
    }
    dp[0] = 0;

    for (int i = 0; i < d; i++) {
        // 지름길이 있다면 가본다.
        for (int j = 0; j < paths[i].size(); j++) {
            PathInfo pi = paths[i][j];
            dp[pi.endPoint] = min(dp[pi.endPoint], dp[i] + pi.distance);
        }

        // 지름길이 없다면 그냥 간다.
        dp[i + 1] = min(dp[i + 1], dp[i] + 1);
    }

    result = dp[d];
}

void printResult() {
    cout << dp[d] << "\n";
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    getInput();
    solve();
    printResult();

    return 0;
}