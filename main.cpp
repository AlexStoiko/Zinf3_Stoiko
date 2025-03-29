#include "pch.h"
#include "Game_Cities.h"
#include <iostream>
#include <conio.h>

using namespace std;

void playWithComputer(Game_Cities& game) {
    srand(time(0));
    string computerCity = game.getCities()[rand() % game.getCityCount()];
    game.startGame(computerCity);
    cout << "��������� �������� � ������: " << computerCity << endl;

    string playerCity;
    while (true) {
        cout << "��� ���: ";
        cin >> playerCity;
        if (playerCity == "exit") break;

        if (!game.proceedToNextCity(playerCity)) {
            cout << "�������� �����! �� ���������!" << endl;
            break;
        }

        string computerMove = game.getComputerMove();
        if (computerMove.empty()) {
            cout << "��������� �� ���� ������� �����! �� ��������!" << endl;
            break;
        }

        cout << "��������� ������: " << computerMove << endl;
    }
}

void playWithFriend(Game_Cities& game) {
    string currentCity;
    cout << "����� 1, ������� ������ �����: ";
    cin >> currentCity;
    game.startGame(currentCity);
    int player = 2;

    while (true) {
        cout << "����� " << player << ", ��� ���: ";
        cin >> currentCity;
        if (currentCity == "exit") break;

        if (!game.proceedToNextCity(currentCity)) {
            cout << "����� " << player << " ��������!" << endl;
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
        cout << "�������� ����� ����:" << endl;
        cout << "1 - ���� � �����������" << endl;
        cout << "2 - ���� � ������" << endl;
        cout << "��� �����: ";

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
