#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> wv;
vector<int> hv;
vector<int> pv;

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin>>n;
    for(int i=0;i<n;i++) {
        int wt = 0, ht = 0;
        cin>>wt>>ht;
        wv.push_back(wt);
        hv.push_back(ht);
    }

    for(int i=0;i<n;i++) {
        int cnt = 1;
        for(int j=0;j<n;j++) {
            if(i != j && wv[i] < wv[j] && hv[i] < hv[j]) {
                cnt++;
            }
        }
        pv.push_back(cnt);
    }

    for(int i=0;i<n;i++){
        cout<<pv[i]<<" ";
    }

    return 0;
}