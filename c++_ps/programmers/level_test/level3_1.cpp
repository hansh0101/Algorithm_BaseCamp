#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int p[100];

int Find(int v) {
    if (v == p[v]) {
        return p[v];
    }
    return p[v] = Find(p[v]);
}

void Union(int v1, int v2) {
    int v1Root = Find(v1);
    int v2Root = Find(v2);
    p[v1Root] = v2Root;
}

bool compare(vector<int> v1, vector<int> v2) {
    return v1[v1.size() - 1] < v2[v2.size() - 1];
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;

    for (int i = 1; i < 100; i++) {
        p[i] = i;
    }
    sort(costs.begin(), costs.end(), compare);

    for(int i=0; i<costs.size(); i++) {
        int cost = costs[i][2];
        int v1 = costs[i][0];
        int v2 = costs[i][1];

        if(Find(v1) != Find(v2)) {
            Union(v1, v2);
            answer += cost;
        }
    }

    return answer;
}