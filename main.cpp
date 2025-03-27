#include "pch.h"
#include "Game_Cities.h"
#include <iostream>
#include <conio.h>

using namespace std;

void playWithComputer(Game_Cities& game) {
    srand(time(0));
    string computerCity = game.getCities()[rand() % game.getCityCount()];
    game.startGame(computerCity);
    cout << "Компьютер начинает с города: " << computerCity << endl;

    string playerCity;
    while (true) {
        cout << "Ваш ход: ";
        cin >> playerCity;
        if (playerCity == "exit") break;

        if (!game.proceedToNextCity(playerCity)) {
            cout << "Неверный город! Вы проиграли!" << endl;
            break;
        }

        string computerMove = game.getComputerMove();
        if (computerMove.empty()) {
            cout << "Компьютер не смог назвать город! Вы победили!" << endl;
            break;
        }

        cout << "Компьютер выбрал: " << computerMove << endl;
    }
}

void playWithFriend(Game_Cities& game) {
    string currentCity;
    cout << "Игрок 1, введите первый город: ";
    cin >> currentCity;
    game.startGame(currentCity);
    int player = 2;

    while (true) {
        cout << "Игрок " << player << ", ваш ход: ";
        cin >> currentCity;
        if (currentCity == "exit") break;

        if (!game.proceedToNextCity(currentCity)) {
            cout << "Игрок " << player << " проиграл!" << endl;
            break;
        }

        player = (player == 1) ? 2 : 1;
    }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Game_Cities game;
    game.loadCities("cities.txt");

    do {
        cout << "Выберите режим игры:" << endl;
        cout << "1 - Игра с компьютером" << endl;
        cout << "2 - Игра с другом" << endl;
        cout << "Ваш выбор: ";

        int choice;
        cin >> choice;

        if (choice == 1) {
            playWithComputer(game);
        }
        else if (choice == 2) {
            playWithFriend(game);
        }
        else {
            break;
        }
    } while (true);

    return 0;
}
