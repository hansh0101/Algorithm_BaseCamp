#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<pair<int,int>> v; // first: d, second: p
priority_queue<int, vector<int>, greater<int>> pq; // 오름차순으로 정렬된 pq (작은 값이 앞에)
int n, d, p, ans;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin>>n;
    for(int i=0;i<n;i++) {
        cin>>p>>d;
        // first에 d, second에 p를 넣는 이유는 sort() 때문임
        v.push_back({d, p});
    }

    // sort() 함수는 기본적으로 오름차순으로 정렬해줌
    // pair로 된 구조의 경우에는 first를 기준으로 오름차순으로 정렬해주고, first가 같을 경우에는 second를 비교하여 second에 대한 오름차순으로 정렬됨
    // ex) {1, 2}, {1, 1} 이 들어있을 경우 -> {1, 1}, {1, 2} 로 정렬됨
    sort(v.begin(), v.end());

    // 반복문을 이용하여 모든 강연에 대해 확인해봄
    for(int i=0;i<n;i++) {
        // v[i].first는 d임
        // priority_queue.size() 보다 d가 작다는 것은, d일 내로 해당 강연을 맡을 수 있음을 의미함
        // ex) priority_queue.size() == 2, d == 3인 경우
        // 3일 내로만 강연해주면 되고 현재 맡은 강연은 2개이기 때문에 강연을 맡을 수 있음
        if(pq.size() < v[i].first) {
            // priority_queue에 강연료 p push
            pq.push(v[i].second);
            // ans는 받을 수 있는 강연료의 합으로, 해당 강연을 맡았다면 ans에 강연료를 더함
            ans+=v[i].second;
        }
        // priority_queue.size() 보다 d가 크거나 같다는 것은, d일 내로 해당 강연을 맡을 수 없음을 의미함
        // ex) priority_queue.size() == 3, d == 3인 경우
        // 3일 내로 강연해줘야 하는데 이미 맡은 강연이 3개이므로 현재 상태에서는 해당 강연을 맡을 수 없음
        // 하지만 우리가 구해야 하는 것은 '최대로 벌 수 있는 돈' 이므로,
        // 지금까지 수락한 강연 중 가장 강연료가 적은 것(a라고 하고)이 현재 확인해보는 강연(b라고 하면)의 강연료보다 작다면
        // a를 강연하는 것보다 b를 강연하는 것이 이득임
        // priority_queue는 greater<int> 를 기준으로 정렬함 -> priority_queue는 오름차순으로 정렬되어있음
        // 즉, priority_queue의 맨 앞에는 강연료가 가장 작은 것(a에 해당)이 들어있음
        else {
            // priority_queue.top() 은 지금까지 수락한 강연 중 강연료가 가장 작은 것(a에 해당)
            // v[i].second 는 현재 확인해보는 강연(b에 해당)의 강연료에 해당
            // a < b인 경우 (현재 확인해보는 강연을 맡는 것이 더 이득인 경우)
            if(pq.top() < v[i].second) {
                // ans에 이미 더해준 a의 강연료를 빼고
                ans -= pq.top();
                // priority_queue에서 a를 뺌
                pq.pop();
                // priority_queue에 b를 추가하고
                pq.push(v[i].second);
                // ans에 b의 강연료를 더함
                ans+=v[i].second;
            }
        }
    }

    cout<<ans;
    return 0;
}