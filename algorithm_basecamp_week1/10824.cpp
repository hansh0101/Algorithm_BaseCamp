#include <iostream>
#include <string>
using namespace std;

string a, b, c, d;
long long sum;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin>>a>>b>>c>>d;
    sum = stoll(a+b) + stoll(c+d);
    cout<<sum;
    return 0;
}