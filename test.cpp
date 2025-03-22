#include "pch.h"

TEST(GameCitiesTest, Creation) {
    Game_Cities* game = new Game_Cities();
    ASSERT_NE(game, nullptr);
    delete game;
}
