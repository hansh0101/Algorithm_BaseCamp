#include <iostream>
#include <queue>
using namespace std;

// long long 사용하는 이유: integer overflow 발생함 !!!!!!
priority_queue<long long, vector<long long>, greater<long long>> pq; // 오름차순으로 정렬(작은 것들부터 더해주기 위해서)
int n, m, num;
long long ans;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin>>n>>m;
    for(int i=0;i<n;i++) {
        cin>>num;
        // priority_queue에 num을 push하면 greater<>로 인해서 오름차순으로 정렬됨
        pq.push(num);
    }

    for(int i=0;i<m;i++) {
        // priority_queue에서 가장 작은 값을 min1에 할당하고 pop함
        long long min1 = pq.top();
        pq.pop();
        // priority_queue에서 두 번째로 작은 값을 min2에 할당하고 pop함
        long long min2 = pq.top();
        pq.pop();

        long long sum = min1 + min2;

        // min1 + min2 에 해당하는 값을 priority_queue에 2번 push(2번 pop했으니까)
        pq.push(sum);
        pq.push(sum);
    }

    // priority_queue에 들어있는 값을 모두 더함
    for(int i=0;i<n;i++) {
        ans += pq.top();
        pq.pop();
    }

    cout<<ans;
    return 0;
}