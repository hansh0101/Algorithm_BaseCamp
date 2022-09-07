#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

int n, st, fn, ans;
vector<pair<ll, ll>> vec;

bool compare(pair<ll, ll> p1, pair<ll, ll> p2){
    if(p1.second == p2.second){
        return p1.first>p2.first;
    }
    else{
        return p1.second<p2.second;
    }
}

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin>>n;
    for(int i=0;i<n;i++){
        cin>>st>>fn;
        vec.push_back(pair<ll, ll>(fn, st));
    }

    sort(vec.begin(), vec.end());

    ll time = 0;
    for(int i=0;i<n;i++){
        if(time<=vec[i].second){
            time = vec[i].first;
            ans++;
        }
    }
    cout<<ans;
    return 0;
}