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
    ASSERT_TRUE(game.isCityValid("Москва"));
    ASSERT_FALSE(game.isCityValid("НесуществующийГород"));
}

TEST(GameCitiesTest, IsCorrectNextCity) {
    Game_Cities game;
    ASSERT_TRUE(game.isCorrectNextCity("Москва", "Астрахань"));
    ASSERT_FALSE(game.isCorrectNextCity("Москва", "Воронеж"));
}

TEST(GameCitiesTest, StartGame) {
    Game_Cities game;
    game.loadCities("cities.txt");
    game.startGame("Москва");
    ASSERT_EQ(game.getCurrentCity(), "Москва");
}

TEST(GameCitiesTest, HasCityBeenUsed) {
    Game_Cities game;
    game.loadCities("cities.txt");
    game.startGame("Москва");

    ASSERT_TRUE(game.hasCityBeenUsed("Москва"));
    ASSERT_FALSE(game.hasCityBeenUsed("Астрахань"));
}

TEST(GameCitiesTest, AddCityToUsedList) {
    Game_Cities game;
    game.addCityToUsedList("Москва");
    ASSERT_TRUE(game.hasCityBeenUsed("Москва"));
    ASSERT_FALSE(game.hasCityBeenUsed("Воронеж"));
}

TEST(GameCitiesTest, ProceedToNextCity) {
    Game_Cities game;
    game.loadCities("cities.txt");
    game.startGame("Москва");

    ASSERT_TRUE(game.proceedToNextCity("Астрахань"));
    ASSERT_EQ(game.getCurrentCity(), "Астрахань");
    ASSERT_FALSE(game.proceedToNextCity("Воронеж"));
}

TEST(GameCitiesTest, GetComputerMove) {
    Game_Cities game;
    game.loadCities("cities.txt");
    game.startGame("Москва");

    string computerMove = game.getComputerMove();
    ASSERT_FALSE(computerMove.empty());
    ASSERT_TRUE(game.isCorrectNextCity("Москва", computerMove));
}