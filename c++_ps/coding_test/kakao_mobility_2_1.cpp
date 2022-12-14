#include <string>
#include <vector>
#include <cstring>

#define MAX 2e6 + 1

using namespace std;

int solution(vector<vector<int>> infos, int m) {
    int answer = 0;

    int car[20000];
    int bike[20000][2];
    int bikeWalk = 0;
    int bus[20000][2];
    int busWalk = 0;
    int walk[20000];
    memset(car, 0, sizeof(car));
    memset(bike, 0, sizeof(bike));
    memset(bus, 0, sizeof(bus));
    memset(walk, 0, sizeof(walk));

    // base case
    car[0] = infos[0][0];
    bike[0][0] = infos[0][1];
    bike[0][1] = infos[0][3];
    bikeWalk = infos[0][3];
    if (infos[0][2] == -1) {
        bus[0][0] = MAX;
    } else {
        bus[0][0] = infos[0][2];
    }
    bus[0][1] = infos[0][3];
    busWalk = infos[0][3];
    walk[0] = infos[0][3];

    for (int i = 1; i < infos.size(); i++) {
        // car
        car[i] = car[i - 1] + infos[i][0];

        // bike
        bike[i][0] = min(bike[i - 1][0], bike[i - 1][1]) + infos[i][1];
        if (bike[i - 1][0] > bike[i - 1][1] && bikeWalk + infos[i][3] <= m) {
            bike[i][1] = bike[i - 1][1] + infos[i][3];
            bikeWalk += infos[i][3];
        } else {
            bike[i][1] = bike[i - 1][0] + infos[i][3];
            bikeWalk = infos[i][3];
        }

        // bus
        if (infos[i][2] == -1) {
            bus[i][0] = MAX;
            if (bus[i][1] != MAX && busWalk + infos[i][3] <= m) {
                bus[i][1] = bus[i - 1][1] + infos[i][3];
                busWalk += infos[i][3];
            } else {
                bus[i][1] = MAX;
                busWalk = MAX;
            }
        } else {
            bus[i][0] = min(bus[i - 1][0], bus[i - 1][1]) + infos[i][2];
            if (bus[i - 1][0] > bus[i - 1][1] && busWalk + infos[i][3] <= m) {
                bus[i][1] = bus[i - 1][1] + infos[i][3];
                busWalk += infos[i][3];
            } else {
                if (bus[i - 1][0] == MAX) {
                    bus[i][1] = MAX;
                    busWalk = MAX;
                } else {
                    bus[i][1] = bus[i - 1][0] + infos[i][3];
                    busWalk = infos[i][3];
                }
            }
        }

        // walk
        if (walk[i - 1] + infos[i][3] > m) {
            walk[i] = MAX;
        } else {
            walk[i] = walk[i - 1] + infos[i][3];
        }
    }

    int last = infos.size() - 1;
    answer = min(min(car[last], min(bike[last][0], bike[last][1])), min(min(bus[last][0], bus[last][1]), walk[last]));

    return answer;
}

/*
 * 자동차 이용 시 처음부터 끝까지 자동차만 가능
 * 자전거 이용 시 자전거 or 도보만 가능
 * 대중교통 이용 시 대중교통 or 도보만 가능
 * 대중교통이 없는 경우도 있을 수 있음 (-1)
 * 도보의 경우 연속 m분 이상 걸을 수 없음
 */