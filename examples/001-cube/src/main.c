#include <skyfall/application.h>
#include <stdbool.h>

int main(int argc, char *argv[])
{
  App app;

  app.window.title     = "SFDemo";
  app.window.width     = 800;
  app.window.height    = 600;
  app.isRunning        = true;

  SFAppRun(&app);
}
