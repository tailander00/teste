#ifndef NAVE_H
#define NAVE_H

#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include "objeto.h"

class Nave : public Objeto {
    public:
        Objeto *tiro;
        Nave(SDL_Renderer *renderer);
        void direita();
        void esquerda();
};

Nave::Nave(SDL_Renderer *renderer) : Objeto(renderer, "assets/nave.bmp"){
    int altura;
    SDL_GetWindowSizeInPixels(SDL_GetRenderWindow(renderer), nullptr, &altura);
    dst_rect->h = 100;
    dst_rect->w = 100;
    dst_rect->x = 50;
    dst_rect->y = altura-50 ;

    tiro = new Objeto(renderer, "assets/tiro_simples.bmp");
    tiro->dst_rect->h = 100;
    tiro->dst_rect->w = 100;
    tiro->dst_rect->x = 0;
    tiro->dst_rect->y = 0;
}
void Nave::direita(){
    dst_rect->x++;
}
void Nave::esquerda(){
    dst_rect->x--;
}



#endif