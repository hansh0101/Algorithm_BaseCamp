#include <iostream>
#include <queue>
using namespace std;

int N, P;
priority_queue<int> pq[500001];
int ans;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin>>N>>P;
    for(int i=0;i<N;i++) {
        int n, p;
        cin>>n>>p;

        while(true) {
            if(pq[n].empty() || pq[n].top() < p) {
                pq[n].push(p);
                ans++;
                break;
            }
            else if(pq[n].top() > p) {
                pq[n].pop();
                ans++;
            }
            else if(pq[n].top() == p) {
                break;
            }
        }
    }
    cout<<ans;
    return 0;
}