#define SDL_MAIN_USE_CALLBACKS 1  /* use the callbacks instead of main() */
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include "assets/nave.h"
#include "assets/inimigo.h"

/* We will use this renderer to draw into this window every frame. */
static SDL_Window *window = NULL;
static SDL_Renderer *renderer = NULL;

const int bmp_size = 32;
Nave *player;
Inimigo *inimigos;

int tecla = 0;


SDL_AppResult SDL_AppInit(void **appstate, int argc, char *argv[]){

    SDL_SetAppMetadata("Example Renderer Clear", "1.0", "com.example.renderer-clear");

    if (!SDL_Init(SDL_INIT_VIDEO)) {
        SDL_Log("Couldn't initialize SDL: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }

    if (!SDL_CreateWindowAndRenderer("examples/renderer/clear", 640, 480, 0, &window, &renderer)) {
        SDL_Log("Couldn't create window/renderer: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }
    
    player = new Nave(renderer);
    inimigos = new Inimigo(renderer);

    return SDL_APP_CONTINUE;  
}

/* This function runs when a new event (mouse input, keypresses, etc) occurs. */
SDL_AppResult SDL_AppEvent(void *appstate, SDL_Event *event){
    if (event->type == SDL_EVENT_QUIT) {
        return SDL_APP_SUCCESS;  
    }else if(event->type == SDL_EVENT_KEY_DOWN){
        tecla = event->key.scancode;
    }else if(event->type == SDL_EVENT_KEY_UP){
        tecla = 0;
    }
    return SDL_APP_CONTINUE; 
}

/* This function runs once per frame, and is the heart of the program. */
SDL_AppResult SDL_AppIterate(void *appstate){
    
    if(tecla == SDL_SCANCODE_LEFT){
        player->esquerda();

    }else if(tecla == SDL_SCANCODE_RIGHT){
        player->direita();
    }

    SDL_SetRenderDrawColorFloat(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE); 

    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE); 
    SDL_RenderDebugText(renderer, 10, 10, "It can be scaled.");

    SDL_RenderTexture(renderer, player->getTexture(), NULL, player->getRect());
    SDL_RenderTexture(renderer, inimigos->getTexture(), NULL, inimigos->getRect());

    SDL_RenderPresent(renderer);
    return SDL_APP_CONTINUE;  
}

/* This function runs once at shutdown. */
void SDL_AppQuit(void *appstate, SDL_AppResult result){
    /* SDL will clean up the window/renderer for us. */
}
