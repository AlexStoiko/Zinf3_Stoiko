#pragma once

#include <vector>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

class Game_Cities
{
private:
    vector<string> cities;
public:
    Game_Cities() {};

    void loadCities(const string& filename) {
        ifstream file(filename);
        if (!file) {
            cout << "Ошибка открытия файла: " << filename << endl;
            return;
        }
        string city;
        while (getline(file, city)) {
            if (!city.empty()) {
                cities.push_back(city);
            }
        }
        file.close();
    }

    size_t getCityCount() const { return cities.size(); }
};

