#include <iostream>
using namespace std;

int n;
int a,b;

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        cout<<a+b<<"\n";
    }
    return 0;
}