// 5585
#include <iostream>
using namespace std;

int n, N, ans;
int arr[6] = {500, 100, 50, 10, 5, 1};

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin>>n;
    int idx = 0;
    N = 1000-n;
    while(N!=0) {
        if(N >= arr[idx]) {
            N-=arr[idx];
            ans++;
        }
        else {
            idx++;
        }
    }
    cout<<ans;
    return 0;
}
