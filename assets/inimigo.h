#ifndef INIMIGO_H
#define NINIMIGO_H

#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include "objeto.h"

class Inimigo : public Objeto{
    public:
        Inimigo(SDL_Renderer *renderer);
};

Inimigo::Inimigo(SDL_Renderer *renderer): Objeto(renderer, "assets/alien1.bmp"){
    dst_rect->h = 100;
    dst_rect->w = 100;
    dst_rect->x = 50;
    dst_rect->y = 50;
}

#endif