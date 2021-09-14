#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int arr[100001];

void solution(int num) {
    int l = 0;
    int r = n-1;

    while(r>=l) {
        int mid = (l+r)/2;
        if(arr[mid] == num) {
            cout<<"1\n";
            return;
        }
        else if(arr[mid] > num) {
            r = mid - 1;
        }
        else if(arr[mid] < num) {
            l = mid + 1;
        }
    }
    cout<<"0\n";
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin>>n;
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }

    sort(arr, arr+n);

    cin>>m;
    for(int i=0;i<m;i++) {
        int tmp = 0;
        cin>>tmp;
        solution(tmp);
    }

    return 0;
}