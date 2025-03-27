#include "pch.h"
#include "Game_Cities.h"

TEST(GameCitiesTest, Creation) {
    Game_Cities* game = new Game_Cities();
    ASSERT_NE(game, nullptr);
    delete game;
}

TEST(GameCitiesTest, LoadCities) {
    Game_Cities game;
    game.loadCities("cities.txt");
   
    ASSERT_GT(game.getCityCount(), 0);
}

TEST(GameCitiesTest, IsCityValid) {
    Game_Cities game;
    game.loadCities("cities.txt");
    ASSERT_TRUE(game.isCityValid("������"));
    ASSERT_FALSE(game.isCityValid("�������������������"));
}

TEST(GameCitiesTest, IsCorrectNextCity) {
    Game_Cities game;
    ASSERT_TRUE(game.isCorrectNextCity("������", "���������"));
    ASSERT_FALSE(game.isCorrectNextCity("������", "�������"));
}

TEST(GameCitiesTest, StartGame) {
    Game_Cities game;
    game.loadCities("cities.txt");
    game.startGame("������");
    ASSERT_EQ(game.getCurrentCity(), "������");
}

TEST(GameCitiesTest, HasCityBeenUsed) {
    Game_Cities game;
    game.loadCities("cities.txt");
    game.startGame("������");

    ASSERT_TRUE(game.hasCityBeenUsed("������"));
    ASSERT_FALSE(game.hasCityBeenUsed("���������"));
}

TEST(GameCitiesTest, AddCityToUsedList) {
    Game_Cities game;
    game.addCityToUsedList("������");
    ASSERT_TRUE(game.hasCityBeenUsed("������"));
    ASSERT_FALSE(game.hasCityBeenUsed("�������"));
}

TEST(GameCitiesTest, ProceedToNextCity) {
    Game_Cities game;
    game.loadCities("cities.txt");
    game.startGame("������");

    ASSERT_TRUE(game.proceedToNextCity("���������"));
    ASSERT_EQ(game.getCurrentCity(), "���������");
    ASSERT_FALSE(game.proceedToNextCity("�������"));
}

TEST(GameCitiesTest, GetComputerMove) {
    Game_Cities game;
    game.loadCities("cities.txt");
    game.startGame("������");

    string computerMove = game.getComputerMove();
    ASSERT_FALSE(computerMove.empty());
    ASSERT_TRUE(game.isCorrectNextCity("������", computerMove));
}