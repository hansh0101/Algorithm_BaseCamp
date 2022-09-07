#include <iostream>
#include <vector>
using namespace std;

int n, k;
vector<int> v[100];
vector<int> order;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin>>n>>k;
    int input;
    for(int i=0;i<n;i++) {
        cin>>input;
        order.push_back(input);
    }

    for(int i=0;i<order.size();i++) {
        bool flag = false;

        for(int j=0;j<k;j++) {
            if(v[j].empty()) {
                v[j].push_back(order[i]);
                flag = true;
                break;
            }
        }

        if(flag) continue;

        for(int j=0;j<k;j++) {
            if(v[j][v[j].size() - 1] < order[i]) {
                v[j].push_back(order[i]);
                flag = true;
                break;
            }
        }

        if(!flag) {
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES";
    return 0;
}