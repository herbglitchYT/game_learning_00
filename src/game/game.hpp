#include <archeus.hpp>

namespace game {
    class Game : public arc::State {
    public:
        Game();
        ~Game();

        void update();
        void render();

        void movePlayer();

    private:
        arc::Sprite player;
    };
}