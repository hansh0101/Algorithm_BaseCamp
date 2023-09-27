#include <string>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

string decToBin(int n, int digit) {
    string str = "";
    while (n != 0) {
        if (n % 2 == 0) {
            str += '0';
        } else {
            str += '1';
        }
        
        n /= 2;
    }
    
    int loopCount = digit - str.length();
    for (int i = 0; i < loopCount; i++) {
        str += '0';
    }
    
    reverse(str.begin(), str.end());
    
    return str;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    
    for (int i = 0; i < n; i++) {
        string str = "";
        for (int j = 0; j < n; j++) {
            str += " ";
        }
        answer.push_back(str);
    }
    
    for (int i = 0; i < arr1.size(); i++) {
        string str = decToBin(arr1[i], n);
        for (int j = 0; j < str.length(); j++) {
            if (str[j] == '1') {
                answer[i][j] = '#';
            }
        }
    }
    
    for (int i = 0; i < arr2.size(); i++) {
        string str = decToBin(arr2[i], n);
        for (int j = 0; j < str.length(); j++) {
            if (str[j] == '1') {
                answer[i][j] = '#';
            }
        }
    }
    
    return answer;
}