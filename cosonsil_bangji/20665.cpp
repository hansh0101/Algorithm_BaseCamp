#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>

#define pii pair<int, int>
using namespace std;

int n, t, p;
int s, e;
vector<pii > reserve; // 예약 정보를 담을 vector<pair<int, int>>;  first: 시작 시간, second: 종료 시간
vector<pii > log; // 좋아하는 좌석에 대한 이용 로그를 담을 vector<pair<int, int>>;  first: 시작 시간, second: 종료 시간
priority_queue<pii, vector<pii >, greater<>> leave; // 독서실 이용을 시작한 사람의 종료 시간과 좌석 번호를 담을 priority_queue(오름차순);  first: 종료시간, second: 좌석번호
map<int, int> seat; // 좌석에 대한 정보를 담을 map;  key: 좌석 번호, value: 해당 좌석의 좌우 거리 중 최솟값

bool compare(pair<int, int> p1, pair<int, int> p2) {
    // 좌석 간 거리가 큰 것을 우선순위로 두고, 좌석 간 거리가 같을 경우 좌석번호가 작은 것을 우선순위로 둠
    if (p1.second == p2.second) {
        return p1.first > p2.first;
    }
    return p1.second < p2.second;
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> t >> p;

    for (int i = 0; i < t; i++) {
        // 예약정보 push
        cin >> s >> e;
        reserve.push_back({s, e});
    }

    for (int i = 1; i <= n; i++) {
        // i번 자리와 다른 인접 좌석 간의 거리를 n으로 초기화
        seat[i] = n;
    }

    // 예약 정보를 오름차순으로 초기화(먼저 시작하는 사람이 앞으로 오고, 같은 시간에 시작할 경우 먼저 끝나는 사람이 앞으로 옴)
    sort(reserve.begin(), reserve.end());

    // 예약 정보를 하나씩 돌면서 탐색
    for (int i = 0; i < reserve.size(); i++) {
        // curtime: 시작시각이면서 동시에 현재시각(현재시간으로 변수명을 정한 이유는 사람들의 퇴장을 관리하기 위해서)
        int curtime = reserve[i].first;
        // leavetime: 현재 사람이 떠날 시각
        int leavetime = reserve[i].second;

        // 퇴장 관리
        while (true) {
            // leave가 empty라는 것은 퇴장할 사람이 없음을 의미
            if (leave.empty()) {
                break;
            }
            // leave는 퇴장 시각을 기준으로 오름차순으로 정렬되어있음
            // leave.top().first는 퇴장시간으로, 퇴장시간이 현재 시간보다 작다면 나갔음을 의미
            // 유일하게 break가 없는 조건문
            if (leave.top().first <= curtime) {
                // leave.top().second는 퇴장한 사람이 앉았던 좌석번호
                int leavenum = leave.top().second;

                // 퇴장시킴
                leave.pop();

                // 좌석관리(좌석번호 : 1~n)
                // leftseat는 퇴장 좌석을 기준으로 왼쪽의 가장 가까운 사용중인 좌석번호를 의미하고, 퇴장 좌석 기준 왼쪽에 사용중인 좌석이 없으면 0
                // rightseat는 퇴장 좌석을 기준으로 오른쪽의 가장 가까운 사용중인 좌석번호를 의미하고, 퇴장 좌석 기준 오른쪽에 사용중인 좌석이 없으면 n+1
                int leftseat = 0;
                int rightseat = n+1;
                // 퇴장 좌석 기준 leftseat 확인
                for (int j = 1; j < leavenum; j++) {
                    if (seat[j] == 0) {
                        leftseat = j;
                    }
                }
                // 퇴장 좌석 기준 rightseat 확인
                for (int j = n; j > leavenum; j--) {
                    if (seat[j] == 0) {
                        rightseat = j;
                    }
                }

                // 퇴장좌석 기준 양옆으로 누군가가 있긴 할 때
                if(leftseat != 0 && rightseat != n+1) {
                    // leftseat ~ rightseat 사이의 좌석들의 좌석거리 다시 계산
                    for(int j=leftseat; j<=rightseat; j++) {
                        // 현재 위치에서 좌~우 사용중인 좌석까지 더 가까운 쪽으로 할당
                        seat[j] = min(j-leftseat, rightseat-j);
                    }
                }
                // 퇴장좌석 기준으로 왼쪽엔 누군가 있고, 오른쪽엔 사용중이지 않을 때
                else if(leftseat != 0 && rightseat == n+1) {
                    // leftseat~맨 오른쪽 좌석까지의 좌석들의 좌석거리 다시 계산
                    for(int j=leftseat; j<rightseat; j++) {
                        // 오른쪽에 비교대상이 없으므로 min 사용 안 해도 됨
                        seat[j] = j-leftseat;
                    }
                }
                // 퇴장좌석 기준으로 왼쪽에 아무도 없고, 오른쪽엔 누군가 있을 때
                else if(rightseat != n+1 && leftseat == 0) {
                    // 맨 왼쪽 좌석~rightseat까지의 좌석들의 좌석거리 다시 계산
                    for(int j=leftseat+1; j<=rightseat; j++) {
                        // 왼쪽에 비교대상이 없으므로 min 사용 안 해도 됨
                        seat[j] = rightseat-j;
                    }
                }
                // 퇴장좌석 기준으로 좌우에 아무도 없음 == 현재 독서실에 사람이 없음 -> 모든 좌석의 좌석거리를 다시 n으로 초기화
                else if(leftseat == 0 && rightseat == n+1) {
                    for(int j=1;j<=n;j++) {
                        seat[j] = n;
                    }
                }
            }
            // leave.top().first > curtime일 때, 즉 현재 독서실에 있는 사람 중 가장 빨리 퇴장할 사람의 퇴장시각이 아직 되지 않았으므로 아무도 안 퇴장시켜도 됨
            else {
                break;
            }
        }

        // seatnum = reserve[i]가 앉을 자리
        // max_element: STL에서 최대값 구해줌
        int seatnum = max_element(seat.begin(), seat.end(), compare)->first;

        // 퇴장정보 등록
        leave.push({leavetime, seatnum});

        // 자리 배정
        seat[seatnum] = 0;

        // 좌석 최신화
        // seat[j]에는 이미 좌석 정보가 최신화 되어있음
        // 그러므로, 새로 추가된 자리에 대해서만 좌석거리를 계산해주면 됨
        // 현재 자리가 새로 추가된 자리와 더 가깝다면 seatnum-j로 할당해주고, 원래 seat[j]가 더 작다면 그대로 놔둠
        // 새로 추가된 자리의 왼쪽 확인
        for (int j = seatnum - 1; j > 0; j--) {
            // 새로 추가된 자리의 왼쪽을 쭉 보다가 이미 누군가 사용중인 자리 그 너머는 내가 더이상 어떻게 관여할 수 없음
            // seat[j] == 0이면 break;
            if (seat[j] == 0) {
                break;
            }
            seat[j] = min(seat[j], seatnum - j);
        }
        // 새로 추가된 자리의 오른쪽 확인
        for (int j = seatnum + 1; j <= n; j++) {
            // 새로 추가된 자리의 오른쪽을 쭉 보다가 이미 누군가 사용중인 자리 그 너머는 내가 더이상 어떻게 관여할 수 없음
            // seat[j] == 0이면 break;
            if (seat[j] == 0) {
                break;
            }
            seat[j] = min(seat[j], j - seatnum);
        }

        // 좋아하는 좌석에 앉았을 경우 log에 등록
        if (seatnum == p) {
            log.push_back({curtime, leavetime});
        }
    }

    // usedtime은 좋아하는 좌석에 다른 사람들이 앉았던 시간
    // 0900 ~ 2100 은 12시간, 즉 720분이므로 720 - usedtime을 하면 문제의 정답이 나옴
    int usedtime = 0;
    for (int i = 0; i < log.size(); i++) {
        int entertime = log[i].first;
        int leavetime = log[i].second;

        int enterhour = entertime / 100;
        int enterminute = entertime % 100;
        int leavehour = leavetime / 100;
        int leaveminute = leavetime % 100;

        usedtime += (leavehour * 60 + leaveminute) - (enterhour * 60 + enterminute);
    }
    cout << 720 - usedtime;
    return 0;
}