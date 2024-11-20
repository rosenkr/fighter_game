#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H
#include <string>
#include <map>
#include "Engine.h"

namespace game { 
    class TextureManager{
        public:
            // Singleton instance instead of extern + constructor/destructor usage
            static TextureManager* get_instance() {
                return instance = (instance != nullptr)? instance : new TextureManager();
            }
            void load_img(std::string id, std::string filename); // load with string key, some texture from a filename
            void drop(std::string id); // drop with string key
            void clean(); // clean textures from map with iterator
            void draw();
        private:
            TextureManager();
            std::map<std::string, SDL_Texture*> texture_map;
            static TextureManager* instance;

    };
}
#endif


/* Some code ideas for surface creation, release, texture creation, release, and drawing components

		SDL_Surface* surf = TTF_RenderText_Solid(sys.get_font(), text.c_str(), { 0,0,0 });
		texture = SDL_CreateTextureFromSurface(sys.get_ren(), surf);
		SDL_FreeSurface(surf);
	}

	void Label::draw() const {
		SDL_RenderCopy(sys.get_ren(), texture, NULL, &getRect());
	}

	Label::~Label()
	{
		SDL_DestroyTexture(texture);
	}
    
    */