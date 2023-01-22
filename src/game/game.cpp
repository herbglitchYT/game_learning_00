#include "game.hpp"
#include "arc_cpp/keybinds.hpp"
#include "arc_cpp/sprite.hpp"

namespace game {
    Game::Game(){
        arc::config->load("res/config/game.config");
        player = arc::Sprite("player", 0);

        double *scale = arc::config->get<double>("scale");
        player.scale(*scale);

        ARC_Point center = {
            .x = (arc::data->windowSize.x / 2) - (player.getBounds().w / 2),
            .y = (arc::data->windowSize.y / 2) - (player.getBounds().h / 2)
        };
        player.setPos(center);
    }

    Game::~Game(){
    }

    void Game::update(){
        movePlayer();
    }

    void Game::render(){
        player.render();
    }

    void Game::movePlayer(){
        if(arc::keybinds.isInputState(arc::KEYBIND::UP, arc::INPUT_STATE::PRESSED)){
            //move player up here
        }

        if(arc::keybinds.isInputState(arc::KEYBIND::DOWN, arc::INPUT_STATE::PRESSED)){
            //move player up here
        }

        if(arc::keybinds.isInputState(arc::KEYBIND::RIGHT, arc::INPUT_STATE::PRESSED)){
            //move player right here
        }

        if(arc::keybinds.isInputState(arc::KEYBIND::LEFT, arc::INPUT_STATE::PRESSED)){
            //move player left here
        }
    }
}