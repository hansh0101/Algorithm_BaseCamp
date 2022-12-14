#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int arr[4][4001];
vector<int> vec[2];

void solution() {
    long long ans = 0;

    // arr[0]과 arr[1]의 가능한 모든 합을 vec[0]에 push_back, arr[2]와 arr[3]의 가능한 모든 합을 vec[1]에 push_back
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            vec[0].push_back(arr[0][i] + arr[1][j]);
            vec[1].push_back(arr[2][i] + arr[3][j]);
        }
    }

    // vec[0]은 오름차순으로, vec[1]은 내림차순으로 정렬
    sort(vec[0].begin(), vec[0].end());
    sort(vec[1].begin(), vec[1].end(), greater<>());

    // 투포인터 사용
    int p1 = 0, p2 = 0;
    while (p1 < n * n && p2 < n * n) {
        int sum = vec[0][p1] + vec[1][p2];

        if (sum == 0) {
            long long sameNumCnt1 = 0;
            long long sameNumCnt2 = 0;
            for (int i = p1; i < n * n; i++) {
                if (vec[0][p1] == vec[0][i]) {
                    sameNumCnt1++;
                } else {
                    break;
                }
            }
            for (int i = p2; i < n * n; i++) {
                if (vec[1][p2] == vec[1][i]) {
                    sameNumCnt2++;
                } else {
                    break;
                }
            }
            ans += sameNumCnt1 * sameNumCnt2;
            p1 += sameNumCnt1;
            p2 += sameNumCnt2;
        } else if (sum > 0) {
            p2++;
        } else {
            p1++;
        }
    }
    cout<<ans;
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[0][i] >> arr[1][i] >> arr[2][i] >> arr[3][i];
    }

    solution();
    return 0;
}