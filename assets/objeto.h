#ifndef OBJETO_H
#define OBJETO_H

#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <iostream>
#include <string>

using namespace std;

class Objeto{
    private:
        SDL_Texture *texture;
        SDL_Surface *surface;
        char *bmp_path;
    protected:
        SDL_FRect *dst_rect;
    public:
        
        Objeto(SDL_Renderer *renderer, string img);
        SDL_FRect* getRect();
        SDL_Texture* getTexture();
};

Objeto::Objeto(SDL_Renderer *renderer, string img){
    int altura;
    SDL_GetWindowSizeInPixels(SDL_GetRenderWindow(renderer), nullptr, &altura);
    
    dst_rect = new SDL_FRect();
    dst_rect->h = 100;
    dst_rect->w = 100;
    dst_rect->x = 50;
    dst_rect->y = altura-50 ;
    img = "%s"+img;
    SDL_asprintf(&bmp_path, img.c_str(), SDL_GetBasePath());
    surface = SDL_LoadBMP(bmp_path);
    texture = SDL_CreateTextureFromSurface(renderer, surface);
}

SDL_FRect* Objeto::getRect(){
    return dst_rect;
}
SDL_Texture* Objeto::getTexture(){
    return texture;
}



#endif