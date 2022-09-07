#include <iostream>
#include <vector>
#define INF 1e9

using namespace std;

int n;
int arr[20][20];
vector<int> start;
vector<int> link;
int res = INF;

void calculate();

void linkTeamBuilding();

void startTeamBuilding(int idx);

void solution();

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    solution();
    cout<<res;
    return 0;
}

void solution() {
    startTeamBuilding(0);
}

void startTeamBuilding(int idx) {
    // 재귀 종료조건
    if (start.size() == n / 2) {
        // 1. start팀 팀빌딩 끝난 경우
        linkTeamBuilding();
        calculate();
        return;
    }
    if (idx == n) {
        return;
    }

    start.push_back(idx);
    startTeamBuilding(idx + 1);
    start.pop_back();
    startTeamBuilding(idx + 1);
}

void linkTeamBuilding() {
    link.clear();

    int idx = 0;
    for(int i=0;i<n;i++) {
        if(i == start[idx]) {
            idx++;
        } else {
            link.push_back(i);
        }
    }
}

void calculate() {
    int startTeamPoint = 0;
    int linkTeamPoint = 0;

    for(int i=0;i<n/2;i++) {
        for(int j=i+1;j<n/2;j++) {
            startTeamPoint += arr[start[i]][start[j]] + arr[start[j]][start[i]];
            linkTeamPoint += arr[link[i]][link[j]] + arr[link[j]][link[i]];
        }
    }

    res = min(res, abs(startTeamPoint - linkTeamPoint));
}