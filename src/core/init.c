#include <stdlib.h>

#include <skyfall/log/log.h>
#include <skyfall/core/init.h>

#include <SDL2/SDL.h>
#include <glad/glad.h>

int SFInitSdl()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != EXIT_SUCCESS) 
    {
        log_error("Failed to initialize SDL2: %s", SDL_GetError());
        return EXIT_FAILURE;
    }
    log_info("SDL2 initialized!");

    return EXIT_SUCCESS;
}

int SFInitGlad(SDL_Window *window)
{
    // create opengl context on our window
    SDL_GLContext gl_context = SDL_GL_CreateContext(window);
    if(gl_context == NULL)
    {
        log_error("failed to create opengl Context!");
        return EXIT_FAILURE;
    }
    SDL_GL_MakeCurrent(window, gl_context);

    // initialize glad
    if (!gladLoadGLLoader(SDL_GL_GetProcAddress)) 
    {
        log_error("Failed to initialize GLAD");
        return EXIT_FAILURE;
    }

    log_info("GLAD Initialized!");
    log_info("Vendor:   %s", glGetString(GL_VENDOR));
    log_info("Renderer: %s", glGetString(GL_RENDERER));
    log_info("Version:  %s", glGetString(GL_VERSION));

    return EXIT_SUCCESS;
}

void SFPollEvents(SDL_Window *window, App *app)
{
    SDL_Event e;
    while (SDL_PollEvent(&e)) 
    {
        if (e.type == SDL_QUIT) app->isRunning = false;
    }
}

int SFDeinit(SDL_Window *window)
{
    SDL_DestroyWindow(window);
    SDL_Quit();

    return EXIT_SUCCESS;
}
