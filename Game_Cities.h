#pragma once

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <windows.h>
#include <algorithm>

using namespace std;

class Game_Cities
{
private:
    vector<string> cities;
    vector<string> citiesUsed;
    string currentCity;
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

    bool isCityValid(const string& city) {
        for (const auto& c : cities) {
            if (c == city) {
                return true;
            }
        }
        return false;
    }

    bool isCorrectNextCity(const string& prevCity, const string& newCity) {
        if (prevCity.empty() || newCity.empty()) return false;
        char lastChar = prevCity.back() - 32;
        char firstChar = newCity.front();
        return lastChar == firstChar;
    }

    void startGame(const string& firstCity) {
        currentCity = firstCity;
        citiesUsed.clear();
        citiesUsed.push_back(firstCity);
    }

    string getCurrentCity() {
        return currentCity;
    }

    bool hasCityBeenUsed(const string& city) {
        return find(citiesUsed.begin(), citiesUsed.end(), city) != citiesUsed.end();
    }

    void addCityToUsedList(const string& city) {
        citiesUsed.push_back(city);
    }

    bool proceedToNextCity(const string& newCity) {
        if (isCorrectNextCity(currentCity, newCity) && !hasCityBeenUsed(newCity)) {
            currentCity = newCity;
            addCityToUsedList(newCity);
            return true;
        }
        return false;
    }

};