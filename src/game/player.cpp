#include "player.hpp"
#include "arc/math/point.h"

namespace game {
    Player::Player(){
        sprite = arc::Sprite("player", 0);

        double *scale = arc::config->get<double>("scale");
        sprite.scale(*scale);

        ARC_Point center = {
            .x = (arc::data->windowSize.x / 2) - (sprite.getBounds().w / 2),
            .y = (arc::data->windowSize.y / 2) - (sprite.getBounds().h / 2)
        };
        sprite.setPos(center);
    }

    Player::~Player(){}

    void Player::update(){}

    void Player::render(){
        sprite.render();
    }

    ARC_FPoint Player::getPos(){
        return pos;
    }

    ARC_Rect Player::getBounds(){
        return sprite.getBounds();
    }

    void Player::setPos(ARC_Point pos){
        this->pos.x = (float)pos.x;
        this->pos.y = (float)pos.y;

        sprite.setPos(pos);
    }

    void Player::setPos(ARC_FPoint pos){
        this->pos.x = pos.x;
        this->pos.y = pos.y;

        ARC_Point newPos = { (int32_t)pos.x, (int32_t)pos.y };
        sprite.setPos(newPos);
    }
}