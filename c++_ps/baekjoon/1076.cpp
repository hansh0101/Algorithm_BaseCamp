#include <iostream>
#include <cstring>
#include <cmath>
#include <map>

#define ll long long
using namespace std;

string arr[10] = {"black", "brown", "red", "orange", "yellow", "green", "blue", "violet", "grey", "white"};
map<string, ll> colorValueMap, colorMap;
string first, second, third;
ll result;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    for (int i = 0; i < 10; i++) {
        colorValueMap[arr[i]] = (ll) i;
        colorMap[arr[i]] = (ll) pow(10, i);
    }
    cin >> first >> second >> third;

    result = (colorValueMap[first] * 10 + colorValueMap[second]) * colorMap[third];
    cout << result << "\n";
    return 0;
}