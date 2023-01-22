#include "game.hpp"
#include <archeus.hpp>

namespace game {
    Game::Game(){
        arc::config->load("res/config/game.config");
        player = new Player();
    }

    Game::~Game(){
        delete player;
    }

    void Game::update(){
        movePlayer();
    }

    void Game::render(){
        player->render();
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