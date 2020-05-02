#include "Robot.h"
#include "../Round.h"
#include <algorithm>

Robot::Robot() {
    this->nameRobot = "";
    this->classOfDroid = "";
    this->positionOnMap.first = 0;
    this->positionOnMap.second = 0;
}

Robot::~Robot() {
}

string &Robot::getNameRobot() {
    return nameRobot;
}

void Robot::setNameRobot(const string &nameRobot) {
    this->nameRobot = nameRobot;
}

void Robot::setClassOfDroid(const string &classOfDroid) {
    this->classOfDroid = classOfDroid;
}

void Robot::setPositionOnMap(const pair<int, int> &positionOnMap) {
    this->positionOnMap = positionOnMap;
}

void Robot::setLives(int lives) {
    this->lives = lives;
}

vector< pair <pair<int, int>, int> > vision (Map* map, int n, int m) {
    vector< pair <pair<int, int>, int> > visionVector;

    int col = 4;
    int row = 0;
    while (col != -1) {
        int newN = n + row;
        for (int i = m - col; i <= m + col; i++) {
            if(newN >= 0 && newN < map->getVertical() && i >= 0 && i < map->getOrizontal() && (newN != n || i != m)) {
                if (map->getOneCell(newN, i) != "_" && map->getOneCell(newN, i) != "X") {
                    double distance = sqrt(pow(n - newN, 2) + pow(m - i, 2));
                    visionVector.emplace_back(make_pair(make_pair(newN, i), distance));
                }
            }
        }
        row++;
        col--;
    }

    row = -1;
    col = 3;
    while (col != -1) {
        int newN = n + row;
        for (int i = m - col; i <= m + col; i++) {
            if(newN >= 0 && newN < map->getVertical() && i >= 0 && i < map->getOrizontal() && (newN != n || i != m)) {
                if (map->getOneCell(newN, i) != "_" && map->getOneCell(newN, i) != "X") {
                    double distance = sqrt(pow(n - newN, 2) + pow(m - i, 2));
                    visionVector.emplace_back(make_pair(make_pair(newN, i), distance));
                }
            }
        }
        row--;
        col--;
    }
    return visionVector;
}

void Robot::moveRobot(vector<AlongTheWay *> itemsAndTraps, Map* map , Round* round) {
    int numberOfVisitedCells = 0;
    int nFinalLoc = map->getFinalLocation().first;
    int mFinalLoc = map->getFinalLocation().second;
    int length = map->getOrizontal();
    int width = map->getVertical();

    vector<pair<pair<int, int>, int> > vis;

    while (positionOnMap.first != nFinalLoc && positionOnMap.second != mFinalLoc && lives != 0) {
        vis = vision(map, positionOnMap.first, positionOnMap.second);
        numberOfVisitedCells++;
        bool finalLocationInVision = false;
        for (auto it : vis) {
            pair<int, int> coord = it.first;
            if (map->getOneCell(coord.first, coord.second) == "F") {
                finalLocationInVision = true;
                int fLFirst = coord.first;      // coordinates for the final location
                int fLSecond = coord.second;
                /// Fourth quadrant
                if (fLFirst < positionOnMap.first && fLSecond < positionOnMap.second) {
                    cout << "ya";
                    // Nord - west

                    // trying to go up
                    string up = map->getOneCell(positionOnMap.first - 1, positionOnMap.second);
                    if (up == "I1" || up == "I2") {
                        if (up == "I1" && classOfDroid == "First Class") {
                            lives++;
                        } else {
                            round->setCoins();
                        }
                        map->setOneCell(positionOnMap.first, positionOnMap.second, "X");
                        positionOnMap.first--;
                        map->setOneCell(positionOnMap.first, positionOnMap.second, "R");
                    } else {
                        if (up == "F1" || up == "F2") {

                            // trying to go left
                            string left = map->getOneCell(positionOnMap.first, positionOnMap.second - 1);
                            map->setOneCell(positionOnMap.first, positionOnMap.second, "X");
                            if ( (left == "I1" && classOfDroid == "First class") || left == "I2" || left == "F1") {
                                if (left == "I1") {
                                    lives++;
                                } else {
                                    if (left == "I2") {
                                        round->setCoins();

                                    } else {
                                        lives--;
                                    }
                                }
                                positionOnMap.second--;
                            }
                            if (left == "F2") {
                                if (positionOnMap.first + 2 < map->getVertical() && positionOnMap.second + 2 < map->getOrizontal()) {
                                    positionOnMap.first += 2;
                                    positionOnMap.second += 2;
                                } else {
                                    round->setDamage();
                                }
                            } else {
                                positionOnMap.second--;
                            }
                            map->setOneCell(positionOnMap.first, positionOnMap.second, "R");
                        } else {
                            map->setOneCell(positionOnMap.first, positionOnMap.second, "X");

                            string left = map->getOneCell(positionOnMap.first, positionOnMap.second - 1);
                            if ( (left == "I1" && classOfDroid == "First class") || left == "I2") {
                                if (left == "I1") {
                                    lives++;
                                } else {
                                    round->setCoins();
                                }
                                positionOnMap.second--;
                            } else {
                                positionOnMap.first--;
                            }
                            map->setOneCell(positionOnMap.first, positionOnMap.second, "R");
                        }
                    }
                }

                /// First quadrant
                if (fLFirst < positionOnMap.first && fLSecond > positionOnMap.second) {
                    // Nord - east

                    // trying to go right
                    string right = map->getOneCell(positionOnMap.first, positionOnMap.second + 1);
                    if ((right == "I1" && classOfDroid == "First class") || right == "I2") {
                        if (right == "I1") {
                            lives++;
                        } else {
                            round->setCoins();
                        }
                        map->setOneCell(positionOnMap.first, positionOnMap.second, "X");
                        positionOnMap.second++;
                        map->setOneCell(positionOnMap.first, positionOnMap.second, "R");
                    } else {
                        if (right == "F1" || right == "F2") {

                            // trying to go up
                            string up = map->getOneCell(positionOnMap.first - 1, positionOnMap.second);
                            if ((up == "I1" && classOfDroid == "First class") || up == "I2" || up == "F1") {
                                if (up == "I1") {
                                    lives++;
                                } else {
                                    if (up == "I2") {
                                        round->setCoins();
                                    } else {
                                        lives--;
                                    }
                                }
                                positionOnMap.first--;
                            } else {
                                if (up == "F2") {
                                    if (positionOnMap.first + 2 < map->getVertical() && positionOnMap.second - 2 > 0) {
                                        positionOnMap.first += 2;
                                        positionOnMap.second -= 2;
                                    } else {
                                        round->setDamage();
                                    }
                                } else {
                                    positionOnMap.first--;
                                }
                            }
                            map->setOneCell(positionOnMap.first, positionOnMap.second, "R");
                        } else {
                            map->setOneCell(positionOnMap.first, positionOnMap.second, "X");

                            string left = map->getOneCell(positionOnMap.first - 1, positionOnMap.second);
                            if ( (left == "I1" && classOfDroid == "First class") || left == "I2") {
                                if (left == "I1") {
                                    lives++;
                                } else {
                                    round->setCoins();
                                }
                                positionOnMap.first--;
                            } else {
                                positionOnMap.second++;
                            }
                            map->setOneCell(positionOnMap.first, positionOnMap.second, "R");
                        }
                    }
                }

                /// Second quadrant
                if (fLFirst > positionOnMap.first && fLSecond > positionOnMap.second) {
                    // South - east

                    // trying to go down
                    string down = map->getOneCell(positionOnMap.first + 1, positionOnMap.second);
                    if ((down == "I1" && classOfDroid == "First Class") || down == "I2") {
                        if (down == "I1") {
                            lives++;
                        } else {
                            round->setCoins();
                        }
                        map->setOneCell(positionOnMap.first, positionOnMap.second, "X");
                        positionOnMap.first++;
                        map->setOneCell(positionOnMap.first, positionOnMap.second, "R");
                    } else {
                        if (down == "F1" || down == "F2") {
                            // trying to go right
                            string right = map->getOneCell(positionOnMap.first, positionOnMap.second + 1);
                            if ((right == "I1" && classOfDroid == "First class") || right == "I2" || right == "F1") {
                                if (right == "I1") {
                                    lives++;
                                } else {
                                    if (right == "I2") {
                                        round->setCoins();
                                    } else {
                                        lives--;
                                    }
                                }
                                positionOnMap.second++;
                            } else {
                                if (right == "F2") {
                                    if (positionOnMap.first - 2 > 0 && positionOnMap.second - 2 > 0) {
                                        positionOnMap.first -= 2;
                                        positionOnMap.second -= 2;
                                    } else {
                                        round->setDamage();
                                    }
                                } else {
                                    positionOnMap.second++;
                                }
                            }
                            map->setOneCell(positionOnMap.first, positionOnMap.second, "R");
                        } else {
                            map->setOneCell(positionOnMap.first, positionOnMap.second, "X");

                            // going right if down has nothing and right has Items
                            string right = map->getOneCell(positionOnMap.first, positionOnMap.second + 1);
                            if ( (right == "I1" && classOfDroid == "First class") || right == "I2") {
                                if (right == "I1") {
                                    lives++;
                                } else {
                                    round->setCoins();
                                }
                                positionOnMap.second++;
                            } else {
                                positionOnMap.first++;
                            }
                            map->setOneCell(positionOnMap.first, positionOnMap.second, "R");
                        }
                    }
                }

                /// Third quadrant
                if (fLFirst > positionOnMap.first && fLSecond < positionOnMap.second) {
                    // South - west

                    // trying to go left
                    string left = map->getOneCell(positionOnMap.first, positionOnMap.second - 1);
                    if ((left == "I1" && classOfDroid == "First class") || left == "I2") {
                        if (left == "I1") {
                            lives++;
                        } else {
                            round->setCoins();
                        }
                        map->setOneCell(positionOnMap.first, positionOnMap.second, "X");
                        positionOnMap.second--;
                        map->setOneCell(positionOnMap.first, positionOnMap.second, "R");
                    } else {
                        if (left == "T1" || left == "T2") {

                            // trying to go down
                            map->setOneCell(positionOnMap.first, positionOnMap.second, "X");
                            string down = map->getOneCell(positionOnMap.first + 1, positionOnMap.second);
                            if ((down == "I1" && classOfDroid == "First class") || down == "I2" || down == "T1") {
                                if (down == "I1") {
                                    lives++;
                                } else {
                                    if (down == "I2") {
                                        round->setCoins();
                                    } else {
                                        lives--;
                                    }
                                }
                                positionOnMap.first++;
                            } else {
                                if (down == "T2") {
                                    if (positionOnMap.first - 2 > 0 && positionOnMap.second + 2 < map->getOrizontal()) {
                                        positionOnMap.first -= 2;
                                        positionOnMap.second += 2;
                                    } else {
                                        round->setDamage();
                                    }
                                } else {
                                    positionOnMap.first++;
                                }
                            }
                            map->setOneCell(positionOnMap.first, positionOnMap.second, "R");
                        } else {
                            map->setOneCell(positionOnMap.first, positionOnMap.second, "X");

                            // trying to go down to see if there is an item if left has nothing
                            string down = map->getOneCell(positionOnMap.first + 1, positionOnMap.second);
                            if ( (down == "I1" && classOfDroid == "First class") || down == "I2") {
                                if (down == "I1") {
                                    lives++;
                                } else {
                                    round->setCoins();
                                }
                                positionOnMap.first++;
                            } else {
                                positionOnMap.second--;
                            }
                            map->setOneCell(positionOnMap.first, positionOnMap.second, "R");
                        }
                    }
                }

                /// Verification on row
                if (fLFirst == positionOnMap.first) {
                    // verify if final location is right or left

                    // left
                    if (fLSecond < positionOnMap.second) {
                        string left = map->getOneCell(positionOnMap.first, positionOnMap.second - 1);
                        map->setOneCell(positionOnMap.first, positionOnMap.second, "X");
                        if (left == "F") {
                            positionOnMap.second--;
                            cout << "Mission complete! You are naturally strong in the Force! ";
                            cout << nameRobot << " reached Naboo at coordinates " << fLFirst << " " << fLSecond << endl;
                            map->setOneCell(positionOnMap.first, positionOnMap.second, "$");
                            return;
                        } else {
                            if (left == "I1" && classOfDroid == "First class") {
                                lives++;
                            } else {
                                if (left == "I2") {
                                    round->setCoins();
                                } else {
                                    if (left == "T1") {
                                        lives--;
                                    } else {
                                        round->setDamage();
                                    }
                                }
                            }
                        }
                        positionOnMap.second--;
                        map->setOneCell(positionOnMap.first, positionOnMap.second, "R");
                    }

                    // right
                    if (fLSecond > positionOnMap.second) {
                        string right = map->getOneCell(positionOnMap.first, positionOnMap.second + 1);
                        map->setOneCell(positionOnMap.first, positionOnMap.second, "X");
                        if (right == "F") {
                            positionOnMap.second++;
                            cout << "Mission complete! You saved the world! ";
                            cout << nameRobot << " reached Dagobah at coordinates " << fLFirst << " " << fLSecond << endl;
                            map->setOneCell(positionOnMap.first, positionOnMap.second, "$");
                            return;
                        } else {
                            if (right == "I1" && classOfDroid == "First class") {
                                lives++;
                            } else {
                                if (right == "I2") {
                                    round->setCoins();
                                } else {
                                    if (right == "T1") {
                                        lives--;
                                    } else {
                                        round->setDamage();
                                    }
                                }
                            }
                        }
                        positionOnMap.second++;
                        map->setOneCell(positionOnMap.first, positionOnMap.second, "R");
                    }
                }

                /// Verification on column
                if (fLFirst == positionOnMap.first) {
                    // verify if final location is up or down

                    // up
                    if (fLFirst < positionOnMap.first) {
                        string up = map->getOneCell(positionOnMap.first - 1, positionOnMap.second);
                        map->setOneCell(positionOnMap.first, positionOnMap.second, "X");
                        if (up == "F") {
                            positionOnMap.first--;
                            cout << "Mission complete! You are now a hero of the Galaxy! ";
                            cout << nameRobot << " reached Alderaan at coordinates " << fLFirst << " " << fLSecond << endl;
                            map->setOneCell(positionOnMap.first, positionOnMap.second, "$");
                            return;
                        } else {
                            if (up == "I1" && classOfDroid == "First class") {
                                lives++;
                            } else {
                                if (up == "I2") {
                                    round->setCoins();
                                } else {
                                    if (up == "T1") {
                                        lives--;
                                    } else {
                                        round->setDamage();
                                    }
                                }
                            }
                        }
                        positionOnMap.first--;
                        map->setOneCell(positionOnMap.first, positionOnMap.second, "R");
                    }

                    // down
                    if (fLFirst > positionOnMap.second) {
                        string down = map->getOneCell(positionOnMap.first + 1, positionOnMap.second);
                        map->setOneCell(positionOnMap.first, positionOnMap.second, "X");
                        if (down == "F") {
                            positionOnMap.first++;
                            cout << "Mission complete! You rescued Han Solo from Jabba the Hutt";
                            cout << nameRobot << " reached Naboo at coordinates " << fLFirst << " " << fLSecond << endl;
                            map->setOneCell(positionOnMap.first, positionOnMap.second, "$");
                            return;
                        } else {
                            if (down == "I1" && classOfDroid == "First class") {
                                lives++;
                            } else {
                                if (down == "I2") {
                                    round->setCoins();
                                } else {
                                    if (down == "T1") {
                                        lives--;
                                    } else {
                                        round->setDamage();
                                    }
                                }
                            }
                        }
                        positionOnMap.first++;
                        map->setOneCell(positionOnMap.first, positionOnMap.second, "R");
                    }
                }

            }
        }
        if (!finalLocationInVision) {
            bool itemFound = false;
            if (positionOnMap.first > 0 &&
                (map->getOneCell(positionOnMap.first - 1, positionOnMap.second) == "I1" || map->getOneCell(positionOnMap.first - 1, positionOnMap.second) == "I2")) {
                map->setOneCell(positionOnMap.first, positionOnMap.second, "X");
                string up = map->getOneCell(positionOnMap.first - 1, positionOnMap.second);
                if (up == "I1" && classOfDroid == "First class") {
                    positionOnMap.first--;
                    lives++;
                } else {
                    if (up == "I2"){
                        round->setCoins();
                        positionOnMap.first--;
                    }
                }
                map->setOneCell(positionOnMap.first, positionOnMap.second, "R");
                itemFound = true;
            }

            if (positionOnMap.first < map->getVertical() && !itemFound &&
                (map->getOneCell(positionOnMap.first + 1, positionOnMap.second) == "I1" || map->getOneCell(positionOnMap.first + 1, positionOnMap.second) == "I2")) {
                map->setOneCell(positionOnMap.first, positionOnMap.second, "X");
                string down = map->getOneCell(positionOnMap.first + 1, positionOnMap.second);
                if (down == "I1" && classOfDroid == "First class") {
                    positionOnMap.first++;
                    lives++;
                } else {
                    if (down == "I2"){
                        round->setCoins();
                        positionOnMap.first++;
                    }
                }
                map->setOneCell(positionOnMap.first, positionOnMap.second, "R");
                itemFound = true;
            }

            if (positionOnMap.second > 0 && !itemFound &&
                (map->getOneCell(positionOnMap.first, positionOnMap.second - 1) == "I1" || map->getOneCell(positionOnMap.first, positionOnMap.second - 1) == "I2")) {
                map->setOneCell(positionOnMap.first, positionOnMap.second, "X");
                string left = map->getOneCell(positionOnMap.first, positionOnMap.second - 1);
                if (left == "I1" && classOfDroid == "First class") {
                    positionOnMap.second--;
                    lives++;
                } else {
                    if (left == "I2"){
                        round->setCoins();
                        positionOnMap.second--;
                    }
                }
                map->setOneCell(positionOnMap.first, positionOnMap.second, "R");
                itemFound = true;
            }

            if (positionOnMap.second < map->getOrizontal() && !itemFound &&
                (map->getOneCell(positionOnMap.first, positionOnMap.second + 1) == "I1" || map->getOneCell(positionOnMap.first, positionOnMap.second + 1) == "I2")) {
                map->setOneCell(positionOnMap.first, positionOnMap.second, "X");
                string right = map->getOneCell(positionOnMap.first, positionOnMap.second + 1);
                if (right == "I1" && classOfDroid == "First class") {
                    positionOnMap.second++;
                    lives++;
                } else {
                    if (right == "I2"){
                        round->setCoins();
                        positionOnMap.second++;
                    }
                }
                map->setOneCell(positionOnMap.first, positionOnMap.second, "R");
                itemFound = true;
            }

            if (!itemFound) {
                if ((numberOfVisitedCells - 1) % 2 == 0) {
                    if (positionOnMap.second + 1 < length) {
                        map->setOneCell(positionOnMap.first, positionOnMap.second, "X");
                        string charac = map->getOneCell(positionOnMap.first, positionOnMap.second + 1);
                        if (charac == "F1") {
                            lives--;
                        } else {
                            if (charac == "F2") {
                                round->setDamage();
                            }
                        }
                        positionOnMap = make_pair(positionOnMap.first, positionOnMap.second + 1);
                        map->setOneCell(positionOnMap.first, positionOnMap.second, "R");
                    } else {
                        if (positionOnMap.first + 1 < width) {
                            map->setOneCell(positionOnMap.first, positionOnMap.second, "X");
                            string charac = map->getOneCell(positionOnMap.first + 1, positionOnMap.second);
                            if (charac == "F1") {
                                lives--;
                            } else {
                                if (charac == "F2") {
                                    round->setDamage();
                                }
                            }
                            positionOnMap = make_pair(positionOnMap.first + 1, positionOnMap.second);
                            map->setOneCell(positionOnMap.first, positionOnMap.second, "R");
                        } else {
                            cout << "You are blocked. Game over!";
                            return;
                        }
                    }
                } else {
                    if (positionOnMap.first + 1 < width) {
                        map->setOneCell(positionOnMap.first, positionOnMap.second, "X");
                        string charac = map->getOneCell(positionOnMap.first + 1, positionOnMap.second);
                        if (charac == "F1") {
                            lives--;
                        } else {
                            if (charac == "F2") {
                                round->setDamage();
                            }
                        }
                        positionOnMap = make_pair(positionOnMap.first + 1, positionOnMap.second);
                        map->setOneCell(positionOnMap.first, positionOnMap.second, "R");
                    } else {
                        if (positionOnMap.second + 1 < length) {
                            map->setOneCell(positionOnMap.first, positionOnMap.second, "X");
                            string charac = map->getOneCell(positionOnMap.first, positionOnMap.second + 1);
                            if (charac == "F1") {
                                lives--;
                            } else {
                                if (charac == "F2") {
                                    round->setDamage();
                                }
                            }
                            positionOnMap = make_pair(positionOnMap.first, positionOnMap.second + 1);
                            map->setOneCell(positionOnMap.first, positionOnMap.second, "R");
                        } else {
                            cout << "You are blocked. Game over!";
                            return;
                        }
                    }
                }
            }
        }
    }
}