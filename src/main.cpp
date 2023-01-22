#include "game/game.hpp"
#include <archeus.hpp>

namespace arc {
    State *initState(){
        return new game::Game;
    }
}