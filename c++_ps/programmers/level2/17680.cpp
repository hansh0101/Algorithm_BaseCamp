#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;

    set<string> cache;
    vector<string> cacheList;

    for (int i = 0; i < cities.size(); i++) {
        string city = cities[i];
        transform(city.begin(), city.end(), city.begin(), ::tolower);

        if (cache.find(city) == cache.end()) {
            answer += 5;

            if (cache.size() == cacheSize && cacheList.size() > 0) {
                cache.erase(cacheList[0]);
                cacheList.erase(cacheList.begin());
            }
            if (cache.size() < cacheSize) {
                cache.insert(city);
                cacheList.push_back(city);
            }
        } else {
            answer += 1;

            int index = -1;
            for (int j = 0; j < cacheList.size(); j++) {
                if (cacheList[j] == city) {
                    index = j;
                    break;
                }
            }

            if (cacheSize >= 1) {
                cacheList.erase(cacheList.begin() + index);
                cacheList.push_back(city);
            }
        }
    }

    return answer;
}