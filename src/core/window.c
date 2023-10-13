#include <skyfall/log/log.h>
#include <skyfall/application.h>
#include <SDL2/SDL.h>

SDL_Window *SFWindowHandler(App *app)
{
    SDL_Window *window = SDL_CreateWindow(app->window.title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                          app->window.width, app->window.height, SDL_WINDOW_OPENGL);

    if ( window == NULL)
    {
        log_error("Failed to create SDL window: %s", SDL_GetError());
        return NULL;
    }
    
    // CREATE THE OPENGL CONTEXT AND MAKE IT CURRENT:

    return window;

}
