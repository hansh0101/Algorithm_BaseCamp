#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, k;
int arr[51][51];
int arr_copy[51][51];
int r[6], c[6], s[6];
vector<int> vec;
int ans = 1e9;

int solution() {
    for(int i=0;i<vec.size();i++) {
        // cur_rcs = 회전 순서에 따른 현재 수행해야 할 rcs 배열 인덱스
        int cur_rcs = vec[i];
        for(int j=1;j<=s[cur_rcs]; j++) {
            // j = (r, c)로부터 떨어진 거리
            int right_top = arr_copy[r[cur_rcs] - j][c[cur_rcs] + j];
            // 상
            for(int l= c[cur_rcs] + j; l > c[cur_rcs] - j; l--) {
                arr_copy[r[cur_rcs] - j][l] = arr_copy[r[cur_rcs] - j][l - 1];
            }
            // 좌
            for(int l= r[cur_rcs] - j; l < r[cur_rcs] + j; l++) {
                arr_copy[l][c[cur_rcs] - j] = arr_copy[l + 1][c[cur_rcs] - j];
            }
            // 하
            for(int l= c[cur_rcs] - j; l < c[cur_rcs] + j; l++) {
                arr_copy[r[cur_rcs] + j][l] = arr_copy[r[cur_rcs] + j][l + 1];
            }
            // 우
            for(int l= r[cur_rcs] + j; l > r[cur_rcs] - j; l--) {
                arr_copy[l][c[cur_rcs] + j] = arr_copy[l - 1][c[cur_rcs] + j];
            }
            // 사라져버린 오른쪽 위 값을 알맞게 대입시켜주기
            arr_copy[r[cur_rcs] - j + 1][c[cur_rcs] + j] = right_top;
        }
    }

    int ret = 1e9;
    for(int i=1;i<=n;i++) {
        int sum = 0;
        for(int j=1;j<=m;j++) {
            sum+=arr_copy[i][j];
        }
        ret = min(ret, sum);
    }

    return ret;
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin>>n>>m>>k;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            cin>>arr[i][j];
        }
    }
    for(int i=0;i<k;i++) {
        cin>>r[i]>>c[i]>>s[i];
        vec.push_back(i);
    }

    do {
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=m;j++) {
                arr_copy[i][j] = arr[i][j];
            }
        }
        ans = min(ans, solution());
    } while (next_permutation(vec.begin(), vec.end()));

    cout<<ans;
    return 0;
}