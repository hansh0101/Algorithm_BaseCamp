#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> sub(vector<int> v) {
    int index = 0;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] != 0) index = i + 1;
    }

//    cout << "\nbefore:\n";
//    for (int i: v) {
//        cout << i << " ";
//    }
//    cout << "\n";

    v.erase(v.begin() + index, v.end());

//    cout << "\nafter:\n";
//    for (int i: v) {
//        cout << i << " ";
//    }
//    cout << "\n";

    vector<int> vec = v;
    return vec;
}

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;

//    cout << "\ndeliveries sub\n";
//    deliveries = sub(deliveries);
//    cout << "\npickups sub\n";
//    pickups = sub(pickups);
    int dIndex = deliveries.size() - 1;
    int pIndex = pickups.size() - 1;

    bool flag = false;
    for (int i = 0; i < deliveries.size(); i++) {
        if (deliveries[i] != 0) flag = true;
    }
    if (!flag) dIndex = -1;
    flag = false;
    for (int i = 0; i < pickups.size(); i++) {
        if (pickups[i] != 0) flag = true;
    }
    if (!flag) pIndex = -1;

    while (dIndex != -1 || pIndex != -1) {
        int deliverCount = 0;
        int pickupCount = 0;

        for (int i = dIndex; i >= 0; i--) {
            int capacity = cap - deliverCount;
            if (capacity == 0) {
                break;
            }

            if (deliveries[i] > capacity) {
                deliverCount += capacity;
                deliveries[i] -= capacity;
            } else {
                deliverCount += deliveries[i];
                deliveries[i] = 0;
            }
        }

        for (int i = pIndex; i >= 0; i--) {
            int capacity = cap - pickupCount;
            if (capacity == 0) {
                break;
            }

            if (pickups[i] > capacity) {
                pickupCount += capacity;
                pickups[i] -= capacity;
            } else {
                pickupCount += pickups[i];
                pickups[i] = 0;
            }
        }

//        cout << "dIndex: " << dIndex << ", pIndex : " << pIndex << "\n";
        answer += dIndex > pIndex ? dIndex + 1 : pIndex + 1;
//        cout << "answer: " << answer << "\n";

        for (int i = dIndex; i >= -1; i--) {
            if (i == -1) {
                dIndex = -1;
            } else if (deliveries[i] != 0) {
                dIndex = i;
                break;
            }
        }

        for (int i = pIndex; i >= -1; i--) {
            if (i == -1) {
                pIndex = -1;
            } else if (pickups[i] != 0) {
                pIndex = i;
                break;
            }
        }
//        cout << "\n배송을 위한 거리: " << max(deliveries.size(), pickups.size()) << "\n";
//        cout << "\ndeliveries sub\n";
//        deliveries = sub(deliveries);
//        cout << "\npickups sub\n";
//        pickups = sub(pickups);
    }

    return answer * (long long) 2;
}