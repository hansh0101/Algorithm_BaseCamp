#include <iostream>
using namespace std;

int t;
int a, b;

int findGcd(int a, int b) {
    int x = max(a,b);
    int y = min(a,b);
    while(x>y) {
        x = x - y;
        if(x<y) {
            swap(x,y);
        }
    }
    return x;
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin>>t;
    for(int i=0;i<t;i++) {
        cin>>a>>b;
        int gcd = findGcd(a,b);
        cout<<a*(b/gcd)<<"\n";
    }
    return 0;
}