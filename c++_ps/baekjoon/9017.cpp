#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

int t;
int n;
vector<int> records;
int record;
map<int, int> teamMemberCount;
set<int> notAuthorizedTeam;
map<int, vector<int>> authorizedTeamRecords;
map<int, int> scores;
set<int> topScoreTeams;
int winner;

void init() {
    records.clear();
    teamMemberCount.clear();
    notAuthorizedTeam.clear();
    authorizedTeamRecords.clear();
    scores.clear();
    topScoreTeams.clear();
    winner = 0;
}

void input() {
    cin >> n;
    records.push_back(0);
    for (int i = 0; i < n; i++) {
        cin >> record;
        records.push_back(record);
    }
}

void solve() {
    for (int teamNumber : records) {
        teamMemberCount[teamNumber]++;
    }

    for (pair<int, int> p : teamMemberCount) {
        if (p.second != 6) {
            notAuthorizedTeam.insert(p.first);
        }
    }

    int notAuthorizedCount = 0;
    for (int i = 1; i < records.size(); i++) {
        if (notAuthorizedTeam.find(records[i]) != notAuthorizedTeam.end()) {
            notAuthorizedCount++;
        } else {
            if (authorizedTeamRecords.find(records[i]) == authorizedTeamRecords.end()) {
                vector<int> v;
                v.push_back(i - notAuthorizedCount);
                authorizedTeamRecords[records[i]] = v;
            } else {
                authorizedTeamRecords[records[i]].push_back(i - notAuthorizedCount);
            }
        }
    }

    for (pair<int, vector<int>> p : authorizedTeamRecords) {
        for (int i = 0; i < 4; i++) {
            scores[p.first] += p.second[i];
        }
    }

    int minScore = 1e9;
    for (pair<int, int> p : scores) {
        if (minScore > p.second) {
            topScoreTeams.clear();
            topScoreTeams.insert(p.first);
            minScore = p.second;
        } else if (minScore == p.second) {
            topScoreTeams.insert(p.first);
        }
    }

    if (topScoreTeams.size() > 1) {
        int minRank = 1001;
        for (pair<int, vector<int>> p : authorizedTeamRecords) {
            if (topScoreTeams.find(p.first) != topScoreTeams.end() && p.second[4] < minRank) {
                minRank = p.second[4];
                winner = p.first;
            }
        }
    } else if (topScoreTeams.size() == 1) {
        winner = *topScoreTeams.begin();
    }
}

void output() {
    cout << winner << "\n";
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> t;
    while (t--) {
        init();
        input();
        solve();
        output();
    }
}