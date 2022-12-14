#include <iostream>
#include <vector>
#include <map>
#include <cstring>

using namespace std;

int T, n, m, y, t;
string s, s1, s2;
int result;

map<string, int> cityIndex;
int cityYear[50000];
vector<pair<int, int>> vec[50000];
int memo[50000];

void init() {
    result = 0;
    cityIndex.clear();
    memset(cityYear, 0, sizeof(cityYear));
    for (int i = 0; i < 50000; i++) vec[i].clear();
    memset(memo, 0, sizeof(memo));
}

int dfs(int index) {
    if (memo[index] != 0) return memo[index];
    for (int i=0; i<vec[index].size(); i++) {
        memo[index] = max(memo[index], dfs(vec[index][i].first) + vec[index][i].second);
    }
    return memo[index];
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> T;
    while (T--) {
        init();

        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            cin >> s >> y;
            cityIndex[s] = i;
            cityYear[i] = y;
        }
        for (int i = 0; i < m; i++) {
            cin >> s1 >> s2 >> t;
            int s1Index = cityIndex[s1];
            int s1Year = cityYear[s1Index];
            int s2Index = cityIndex[s2];
            int s2Year = cityYear[s2Index];
            if (s1Year < s2Year) vec[s1Index].emplace_back(s2Index, t);
            else if (s1Year > s2Year) vec[s2Index].emplace_back(s1Index, t);
        }

        for (int i=0; i<n; i++) {
            result = max(result, dfs(i));
        }
        cout << result << "\n";
    }
    return 0;
}

/*
2
7 9
Incheon 2011
Seoul 2012
Daegu 2012
Jeju 2017
Daejeon 2015
Busan 2016
Suwon 2014
Daegu Seoul 20
Seoul Suwon 60
Suwon Incheon 20
Incheon Seoul 10
Daegu Busan 125
Suwon Busan 30
Busan Jeju 45
Busan Daejeon 70
Daejeon Jeju 120
10 15
Ava 2001
Akyab 2002
Bagan 2002
Bago 2003
Mandalay 2004
Mrawk 2005
Naypyidaw 2005
Prome 2006
Toungoo 2007
Yangon 2008
Ava Akyab 15
Ava Yangon 80
Akyab Bagan 10
Akyab Bago 20
Bagan Mandalay 20
Bagan Mrawk 60
Bago Mrawk 20
Bago Yangon 50
Mandalay Prome 65
Naypyidaw Prome 70
Naypyidaw Toungoo 120
Prome Toungoo 45
Akyab Mrawk 20
Bago Prome 80
Mrawk Prome 30
 */