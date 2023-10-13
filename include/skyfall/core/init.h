#ifndef SF_CORE_INIT_H
#define SF_CORE_INIT_H

#include <skyfall/application.h>
#include <SDL2/SDL.h>

int SFInitSdl();
int SFInitGlad(SDL_Window *window);

void SFPollEvents(SDL_Window *window, App *app);

int SFDeinit(SDL_Window *window);

#endif // !SF_CORE_INIT_H
