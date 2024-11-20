#include "Engine.h"
#include "Component.h"
#include <vector>
#define FPS 60

namespace game {
    Engine* Engine::instance = nullptr;

    void Engine::init() {
        // Check for null?
        SDL_Init(SDL_INIT_EVERYTHING);
        win = SDL_CreateWindow("Fighters", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
        ren = SDL_CreateRenderer(win, -1, 0);
        running = true;
    }

    // Calls tick() on every currently existing component (comps)
    // Then goes through the "added" components and puts them in currently existing (comps)
    // Then removes from (comps) whatever was put in "removed"
    void Engine::update() {
		for (Component* c : comps)
			c->tick();

		for (Component* c : added)
			comps.push_back(c);
		added.clear();

		for (Component* c : removed) {
			for (std::vector<Component*>::iterator i = comps.begin();
				i != comps.end();)
			{
				if (*i == c) 
				{
					i = comps.erase(i);
				}
				else {
					i++;
				}
			}
		}
		removed.clear();
    }

    void Engine::render() {
        SDL_SetRenderDrawColor(ren, 128, 128, 128, 255);
        SDL_RenderClear(ren);
        // https://www.youtube.com/watch?v=oDIk8EGmDYQ&list=PL-K0viiuJ2RctP5nlJlqmHGeh66-GOZR_&index=4
        // instead of loop here, should use TextureManager?
        // and then in Engine::clean() call texturemanager.clean() to clean ALL textures from the map
        for (Component* c : comps) 
            c->draw();
        SDL_RenderPresent(ren);
    }

    void Engine::events() {
        SDL_Event event;
        // process multiple events in one frame
        while (SDL_PollEvent(&event)) {
            switch(event.type) {
                case SDL_QUIT:
                quit();
                break;
                case SDL_MOUSEBUTTONDOWN:
                for (Component* c : comps)
                    c->mouseDown(event);
                break;
                case SDL_MOUSEBUTTONUP:
                for (Component* c : comps)
                    c->mouseUp(event);
                break;
                case SDL_KEYDOWN:
                for (Component* c : comps)
                    c->keyDown(event);
                break;
                case SDL_KEYUP:
                for (Component* c : comps)
                    c->keyUp(event);			
                break;
            }
        }
    }

    void Engine::clean() {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        SDL_Quit();
    }


    void Engine::quit() {
        running = false;
    }

    void Engine::add(Component* comp) {
	    added.push_back(comp);
    }

    void Engine::remove(Component* c) {
	    removed.push_back(c);
    }
}