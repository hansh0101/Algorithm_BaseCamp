#include <iostream>
using namespace std;

int n,s;
int arr[100001];

void solution() {
//    int start = 0, end = 0;
//    int res = 100001;
//    int sum = arr[start];
//
//    while(end != n) {
//        if(sum >= s) {
//            res = min(res, end-start+1);
//            if(start == end) {
//                break;
//            }
//            sum -= arr[start];
//            start++;
//        }
//        else {
//            end++;
//            if(end != n) {
//                sum += arr[end];
//            }
//        }
//    }
//
//    if(res == 100001) {
//        cout<<"0";
//    }
//    else {
//        cout<<res;
//    }
    int start = 0, end = 0;
    int res = 100001;

    while(end != n) {
        int sum = 0;
        for(int i=start;i<=end;i++) {
            sum += arr[i];
        }

        if(sum >= s) {
            res = min(res, end - start + 1);
            if(end == start) {
                break;
            }
            start++;
        }
        else {
            end++;
        }
    }

    if(res == 100001) {
        cout<<"0";
    }
    else {
        cout<<res;
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin>>n>>s;
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }

    solution();
}