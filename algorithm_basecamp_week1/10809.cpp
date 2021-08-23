#include <iostream>
#include <string.h>
using namespace std;

string str;
int arr[26];

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    memset(arr,-1,sizeof(arr));

    cin>>str;
    for(int i=0;i<str.length();i++) {
        if(arr[str[i]-'a'] == -1) {
            arr[str[i]-'a'] = i;
        }
    }

    for(int i=0;i<26;i++) {
        cout<<arr[i]<<" ";
    }

    return 0;
}