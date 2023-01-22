#pragma once
#include <archeus.hpp>
#include "player.hpp"

namespace game {
    class Game : public arc::State {
    public:
        Game();
        ~Game();

        void update();
        void render();

        void movePlayer();

    private:
        Player *player;
    };
}