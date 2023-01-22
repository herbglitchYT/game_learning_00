#pragma once
#include "arc/math/point.h"
#include "arc_cpp/sprite.hpp"
#include <archeus.hpp>

namespace game {
    class Player {
    public:
        Player();
        ~Player();

        void update();
        void render();

        ARC_FPoint getPos();
        ARC_Rect getBounds();

        void setPos(ARC_Point pos);
        void setPos(ARC_FPoint pos);

    private:
        arc::Sprite sprite;
        ARC_FPoint pos;
    };
}