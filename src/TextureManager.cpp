#include "TextureManager.h"
#include <SDL_image.h>

namespace game { 
    // Initialize the instance to null
    TextureManager* TextureManager::instance = nullptr;

    // Takes a filename (handles most image types) and adds it to a map as a texture
    void TextureManager::load_img(std::string id, std::string filename) {
        SDL_Surface* surf = IMG_Load(filename.c_str());
        SDL_Texture* texture = SDL_CreateTextureFromSurface(Engine::get_instance()->get_ren(), surf);
        SDL_FreeSurface(surf);
        texture_map[id] = texture;
    }

    void TextureManager::drop(std::string id) {

    }

    void TextureManager::clean() {

    }
}
