#ifndef SKYFALL_APPLICATION_H
#define SKYFALL_APPLICATION_H

#include <stdbool.h>
#include <types.h>

typedef struct {
    bool isRunning;

    struct WindowConfig {
        char *title;
        u32 width;
        u32 height;
    } window;
} App;


void SFAppRun(App *app);

#endif // !SKYFALL_APPLICATION_H
