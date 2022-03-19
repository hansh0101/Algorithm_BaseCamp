#include <iostream>
#include <cstring>

using namespace std;

string str;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    while (getline(cin, str)) {
        int ret[4] = {0, 0, 0, 0};
        for (char i : str) {
            if ('a' <= i && i <= 'z') {
                ret[0]++;
            } else if ('A' <= i && i <= 'Z') {
                ret[1]++;
            } else if ('0'<=i && i<='9') {
                ret[2]++;
            } else if(i == ' ') {
                ret[3]++;
            }
        }
        for(int i: ret) {
            cout<<i<<" ";
        }
        cout<<"\n";
    }
    return 0;
}