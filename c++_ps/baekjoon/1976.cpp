#include <iostream>
#include <vector>
#include <set>

using namespace std;

int n, m;
int arr[201][201];
set<int> cities;
vector<int> vec[201];
int parent[201];
bool result = true;

int findParent(int v) {
    if (v == parent[v]) {
        return parent[v];
    }
    return parent[v] = findParent(parent[v]);
}

void unionParent(int v1, int v2) {
    int v1Root = findParent(v1);
    int v2Root = findParent(v2);

    if (v1Root < v2Root) {
        parent[v2Root] = v1Root;
    } else {
        parent[v1Root] = v2Root;
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < m; i++) {
        int city;
        cin >> city;
        cities.insert(city);
    }

    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (arr[i][j] == 1 && parent[i] != parent[j]) {
                unionParent(i, j);
            }
        }
    }

    int p = parent[*(cities.begin())];
    for (auto city : cities) {
        if (p != parent[city]) {
            result = false;
        }
    }

    cout << (result ? "YES\n" : "NO\n");
    return 0;
}