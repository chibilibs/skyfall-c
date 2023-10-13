#include <types.h>

#include <skyfall/log/log.h>
#include <skyfall/core/init.h>
#include <skyfall/application.h>
#include <skyfall/core/window.h>

#include <SDL2/SDL.h>
#include <glad/glad.h>

void SFAppRun(App *app)
{
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 6);
    SDL_GL_SetAttribute(SDL_GL_ACCELERATED_VISUAL, 1);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

    // initialize SDL2 and GLAD
    log_info("Initializing libraries");
    SFInitSdl();
    
    // create window
    SDL_Window *SFWindow = SFWindowHandler(app);

    // initialize glad and create opengl context on our main window
    SFInitGlad(SFWindow);

    glViewport(0, 0, app->window.width, app->window.height);
    glClearColor(1.0f, 1.0f, 1.0f, 0.0f);

    app->isRunning = true;
    while(app->isRunning)
    {
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
  
        SDL_GL_SwapWindow(SFWindow);

        SFPollEvents(SFWindow, app);
    }

    SFDeinit(SFWindow);
}
