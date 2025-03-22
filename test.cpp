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