#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, start, finish, ans;
vector<pair<int, int>> vec;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin>>n;
    for(int i=0;i<n;i++) {
        cin>>start>>finish;
        vec.push_back({finish, start});
    }

    sort(vec.begin(), vec.end());

    int lastFinishTime = 0;
    for(int i=0;i<n;i++) {
        if(lastFinishTime<=vec[i].second) {
            ans++;
            lastFinishTime = vec[i].first;
        }
    }

    cout<<ans;
    return 0;
}