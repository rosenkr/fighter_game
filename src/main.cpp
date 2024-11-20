#include "Engine.h"
using namespace game;

int main(int argc, char* argv[]) {

    Engine::get_instance()->init();

    Uint32 tickInterval = 1000 / FPS;
    while(Engine::get_instance()->is_running()) {
        Uint32 nextTick = SDL_GetTicks() + tickInterval;
        Engine::get_instance()->events();
        Engine::get_instance()->update();
        Engine::get_instance()->render();
        int delay = nextTick - SDL_GetTicks();
		if (delay > 0)
			SDL_Delay(delay);
    }

    Engine::get_instance()->clean();
	return 0;
}
