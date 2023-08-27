#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

struct Player {
    int level;
    string nickname;

    Player(int level, string nickname) {
        this->level = level;
        this->nickname = nickname;
    }
};

struct Room {
    int level;
    vector<Player> players;

    Room(int level, Player roomOwner) {
        this->level = level;
        this->players = vector<Player>();
        this->players.push_back(roomOwner);
    } 
};

int p, m;
int l;
string n;
vector<Room> rooms;

bool compare(Player player1, Player player2) {
    return player1.nickname < player2.nickname;
}

void addPlayer(Player player) {
    for (int i = 0; i < rooms.size(); i++) {
        if (rooms[i].level + 10 >= player.level && rooms[i].level - 10 <= player.level && rooms[i].players.size() < m) {
            rooms[i].players.push_back(player);
            return;
        }
    }

    rooms.push_back(Room(l, player));
}

void printResult() {
    for (Room room : rooms) {
        if (room.players.size() == m) {
            cout << "Started!\n";
        } else {
            cout << "Waiting!\n";
        }

        sort(room.players.begin(), room.players.end(), compare);
        for (Player player : room.players) {
            cout << player.level << " " << player.nickname << "\n";
        }
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> p >> m;

    for (int i = 0; i < p; i++) {
        cin >> l >> n;
        addPlayer(Player(l, n));
    }

    printResult();
    return 0;
}