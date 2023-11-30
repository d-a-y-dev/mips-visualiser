#include "SDL2/SDL.h"

inline bool buttonClicked = false;

void renderMIPSArchitecture(SDL_Window* window, SDL_Renderer* renderer, int currentCycle);

void renderText(const char* text, int x, int y, SDL_Color textColor);