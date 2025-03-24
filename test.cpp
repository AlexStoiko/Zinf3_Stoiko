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
    ASSERT_TRUE(game.isCityValid(game.toUTF8(L"������")));
    ASSERT_FALSE(game.isCityValid(game.toUTF8(L"�������������������")));
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