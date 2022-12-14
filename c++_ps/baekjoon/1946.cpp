#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int t, n;
vector<pair<int, int>> v;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin>>t;
    while(t--) {
        v.clear();

        cin>>n;
        int score1, score2;
        for(int i=0;i<n;i++) {
            cin>>score1>>score2;
            v.push_back({score1, score2});
        }
        sort(v.begin(), v.end());

        int ans = 0;
        int cut = n+1;
        for(int i=0;i<n;i++) {
            if(cut > v[i].second) {
                cut = v[i].second;
                ans++;
            }
        }
        cout<<ans<<"\n";
    }

    return 0;
}