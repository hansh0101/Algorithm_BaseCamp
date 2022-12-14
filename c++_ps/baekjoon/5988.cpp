#include <iostream>
#include <string>
using namespace std;

int n;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin>>n;
    for(int i=0;i<n;i++) {
        string str;
        cin>>str;
        if((str[str.size() - 1] - '0') % 2 == 0) {
            cout<<"even\n";
        } else {
            cout<<"odd\n";
        }
    }

    return 0;
}