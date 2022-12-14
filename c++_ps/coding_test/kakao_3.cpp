#include <string>
#include <vector>
#include <iostream>

using namespace std;

int sales[4] = {10, 20, 30, 40};
int userCount = 0;
int totalMoney = 0;

void check(vector<vector<int>> users, vector<int> emoticons, vector<int> saleIndices) {
    int userCnt = 0;
    int total = 0;
    for (int i = 0; i < users.size(); i++) {
        vector<int> user = users[i];
        int userSale = user[0];
        int userMoney = user[1];
        int userSpend = 0;

        for (int j = 0; j < emoticons.size(); j++) {
            int emoticonSale = sales[saleIndices[j]];
            int emoticonPrice = (double) emoticons[j] * (double) (100 - emoticonSale) * 0.01;

            if (emoticonSale >= userSale) {
                // 산다.
                userSpend += emoticonPrice;
            }
        }

        if (userSpend >= userMoney) {
            userCnt++;
        } else {
            total += userSpend;
        }
    }

    if (userCnt > userCount) {
        userCount = userCnt;
        totalMoney = total;
    } else if (userCnt == userCount && total > totalMoney) {
        totalMoney = total;
    }
}

void recursion(vector<vector<int>> users, vector<int> emoticons, vector<int> saleIndices) {
//    if (index == emoticons.size()) {
//        check(users, emoticons, saleIndices);
//        return;
//    }
//
//    for (int i = 0; i < 4; i++) {
//        saleIndices[index] = i;
//        recursion(index + 1, users, emoticons, saleIndices);
//    }
    if (saleIndices.size() == emoticons.size()) {
        check(users, emoticons, saleIndices);
        return;
    }

    for (int i = 0; i < 4; i++) {
        saleIndices.push_back(i);
        recursion(users, emoticons, saleIndices);
        saleIndices.pop_back();
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer;

    vector<int> saleIndices;
    recursion(users, emoticons, saleIndices);

    answer.push_back(userCount);
    answer.push_back(totalMoney);

    return answer;
}

int main() {
    vector<vector<int>> users;
    vector<int> user;
    user.push_back(40);
    user.push_back(10000);
    users.push_back(user);
    user.clear();
    user.push_back(25);
    user.push_back(10000);
    users.push_back(user);
    user.clear();

    vector<int> emoticons;
    emoticons.push_back(7000);
    emoticons.push_back(9000);

    vector<int> answer = solution(users, emoticons);
    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << " ";
    }
    cout << "\n";
}