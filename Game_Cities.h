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

    // Преобразование string -> wstring (UTF-8 -> Unicode)
    wstring toWString(const string& str) {
        int size_needed = MultiByteToWideChar(CP_UTF8, 0, str.c_str(), -1, NULL, 0);
        wstring wstr(size_needed, 0);
        MultiByteToWideChar(CP_UTF8, 0, str.c_str(), -1, &wstr[0], size_needed);
        return wstr;
    }

    // Преобразование wstring -> string (Unicode -> UTF-8)
    string toUTF8(const wstring& wstr) {
        int size_needed = WideCharToMultiByte(CP_UTF8, 0, wstr.c_str(), -1, NULL, 0, NULL, NULL);
        string str(size_needed, 0);
        WideCharToMultiByte(CP_UTF8, 0, wstr.c_str(), -1, &str[0], size_needed, NULL, NULL);
        return str;
    }

    bool isCityValid(const string& city) {
        for (const auto& c : cities) {
            if (toUTF8(toWString(c)) == city) {
                return true;
            }
        }
        return false;
    }

};

