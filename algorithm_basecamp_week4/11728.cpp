#include <iostream>
using namespace std;

int n, m;
int arr1[1000001];
int arr2[1000001];
int pa, pb;
int ans[2000001];

void solution() {
    int cnt = 0;
    while(pa != n || pb != m) {
        if(pa == n) {
            ans[pa+pb] = arr2[pb];
            pb++;
            continue;
        }
        if(pb == m) {
            ans[pa+pb] = arr1[pa];
            pa++;
            continue;
        }

        if(arr1[pa] >= arr2[pb]) {
            ans[pa+pb] = arr2[pb];
            pb++;
        }
        else {
            ans[pa+pb] = arr1[pa];
            pa++;
        }
    }

    for(int i=0;i<n+m;i++) {
        cout<<ans[i]<<" ";
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin>>n>>m;
    for(int i=0;i<n;i++) {
        cin>>arr1[i];
    }
    for(int i=0;i<m;i++) {
        cin>>arr2[i];
    }

    solution();
    return 0;
}