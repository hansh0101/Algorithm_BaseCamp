#include <iostream>
#include <algorithm>
#define ull unsigned long long
using namespace std;

ull m;
int n;
ull arr[100000];
ull anger[100000];

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin>>m>>n;
    ull sum = 0;
    for(int i=0;i<n;i++) {
        cin>>arr[i];
        sum+=arr[i];
    }

    sort(arr, arr+n);
    ull diff = sum - m;
    ull ret = 0;
    for(int i=0;i<n;i++) {
        anger[i] = min(arr[i], diff / (n-i));
        diff -= anger[i];
        ret += anger[i]*anger[i];
    }
    cout<<ret;
    return 0;
}