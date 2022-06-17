#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int v, e, a, b;
vector<int> vec[10001];
stack<int> st;
bool isScc[10001];
int visitOrder[10001];
vector<vector<int>> sccs;
int order = 0;

int findScc(int curIdx) {
    int minOrder = visitOrder[curIdx] = ++order;
    st.push(curIdx);

    for (int i = 0; i < vec[curIdx].size(); i++) {
        int nxtIdx = vec[curIdx][i];
        if (visitOrder[nxtIdx] == 0) {
            minOrder = min(minOrder, findScc(nxtIdx));
        } else if (!isScc[nxtIdx]) {
            minOrder = min(minOrder, visitOrder[nxtIdx]);
        }
    }

    if (minOrder == visitOrder[curIdx]) {
        vector<int> scc;
        while (true) {
            int tmpIdx = st.top();
            st.pop();
            isScc[tmpIdx] = true;
            scc.push_back(tmpIdx);
            if (tmpIdx == curIdx) {
                break;
            }
        }
        sort(scc.begin(), scc.end());
        sccs.push_back(scc);
    }

    return minOrder;
}

bool compareIntVector(vector<int> &v1, vector<int> &v2) {
    return v1[0] < v2[0];
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    // Input
    cin >> v >> e;
    for (int i = 0; i < e; i++) {
        cin >> a >> b;
        vec[a].push_back(b);
    }

    // Execute
    for (int i = 1; i <= v; i++) {
        if (visitOrder[i] == 0) {
            findScc(i);
        }
    }

    sort(sccs.begin(), sccs.end(), compareIntVector);

    // Output
    cout << sccs.size() << "\n";
    for (int i = 0; i < sccs.size(); i++) {
        for (int j = 0; j < sccs[i].size(); j++) {
            cout << sccs[i][j] << " ";
        }
        cout << "-1\n";
    }

    return 0;
}