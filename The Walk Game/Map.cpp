#include "Map.h"
#include <fstream>
#include <utility>

Map::Map (int n, int m) {
    this->vertical = n;
    this->orizontal = m;
    map = new string*[n];
    for (int i = 0; i < n; i++)
        map[i] = new string[m];

    int randomNFinalLocation, randomMFinalLocation;
    randomNFinalLocation = rand() % n;
    randomMFinalLocation = rand() % (m / 2 + 1) + m / 2;        // the other half of the map
    finalLocation = make_pair(randomNFinalLocation, randomMFinalLocation);

    resetMap();
}

Map::Map (Map* map) {
    this->vertical = map->getVertical();
    this->orizontal = map->getOrizontal();
    this->map = new string*[vertical];
    for (int i = 0; i < vertical; i++)
        this->map[i] = new string[orizontal];

    for (int i = 0; i < vertical; i++) {
        for (int j = 0; j < orizontal; j++) {
            this->map[i][j] = map->getOneCell(i, j);
        }
    }

}

void Map::setOneCell(int n, int m, string character) {
    map[n][m] = character;
}

string Map::getOneCell(int n, int m) {
    return map[n][m];
}

int Map::getVertical() {
    return vertical;
}

int Map::getOrizontal() {
    return orizontal;
}

pair<int, int> Map::getFinalLocation() {
    return finalLocation;
}

void Map::printMap() {
    ofstream out;
    out.open("../map.txt");
    for (int i = 0; i < vertical; i++) {
        for (int j = 0; j < orizontal; j++) {
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
}

void Map::resetMap() {
    for (int i = 0; i < vertical; i++){
        for (int j = 0; j < orizontal; j++) {
            if (i == finalLocation.first && j == finalLocation.second) {
                map[i][j] = "F";
            } else {
                map[i][j] = "_";
            }
        }
    }
    map[0][0] = 'R';
}