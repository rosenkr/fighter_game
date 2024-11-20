#ifndef ENGINE_H
#define ENGINE_H
#define SCREEN_WIDTH 1024
#define SCREEN_HEIGHT 768

#include <vector>
#include <SDL2/SDL.h>
#include "Component.h"

/* Mixes Session + System from F11-F13. */
namespace game {
    class Engine {
        public:
            void add(Component* c);
            void remove(Component* c);

            // Singleton instance
            static Engine* get_instance() {
                return instance = (instance != nullptr)? instance : new Engine();
            }
            SDL_Renderer* get_ren() const { return ren;};
            
            void init();
            void clean();
            void quit();
            void update();
            void render();
            void events();
            bool is_running() { return running; }
        private:
            std::vector<Component*> comps;
            std::vector<Component*> added, removed;
            SDL_Window* win;
            SDL_Renderer* ren;
            Engine(){}
            bool running = true;
            static Engine* instance;
    };
}
#endif