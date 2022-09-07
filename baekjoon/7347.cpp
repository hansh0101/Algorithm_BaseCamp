#include <iostream>
using namespace std;

int t, k;
int arr[30];

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin>>t;
    while(t--) {
        cin>>k;
        for(int i=0;i<k;i++) {
            cin>>arr[i];
        }

        if(k % 2 == 1) {
            cout<<"YES\n";
        }
        else {
            int odd = 0, even = 0;
            for(int i=0;i<k;i++) {
                if(arr[i] == 1) {
                    if(i % 2 == 0)
                        even++;
                    else
                        odd++;
                }
            }

            if(even == odd || abs(even-odd) == 1) {
                cout << "YES\n";
            }
            else {
                cout<<"NO\n";
            }
        }
    }
}