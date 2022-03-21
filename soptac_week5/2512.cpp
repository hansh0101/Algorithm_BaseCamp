#include <iostream>
#include <algorithm>
using namespace std;

int n, budget, sum;
int arr[10000];

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin>>n;
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    cin>>budget;

    sort(arr, arr+n);

    int left = 0, right = arr[n-1], mid = (left+right) / 2;

    while(left<=right) {
        if(mid >= arr[n-1])
            break;

        sum = 0;
        for(int i=0;i<n;i++) {
            if(arr[i] > mid)
                sum+=mid;
            else
                sum+=arr[i];
        }

        if(sum > budget) {
            right = mid - 1;
            mid = (left+right)/2;
        }
        else if(sum < budget) {
            left = right + 1;
            mid = (left+right)/2;
        }
        else
            break;
    }

    if(mid>=arr[n-1])
        cout<<arr[n-1]<<"\n";
    else
        cout<<mid<<"\n";

    return 0;
}