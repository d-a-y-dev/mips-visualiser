#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#endif
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>

// Define color sets
SDL_Color colorSet1[] = {{0, 0, 255, 255}, {0, 255, 0, 255}, {255, 0, 0, 255}, {200, 200, 200, 255}};
SDL_Color colorSet2[] = {{255, 0, 0, 255}, {0, 255, 0, 255}, {0, 0, 255, 255}, {100, 100, 100, 255}};

SDL_Color* currentColorSet = colorSet1;

void handleButtonClick(SDL_Event& e);

SDL_Window* gWindow = nullptr;
SDL_Renderer* gRenderer = nullptr;
TTF_Font* gFont = nullptr;
bool buttonClicked = false;
bool quit = false;

void renderText(const char* text, int x, int y, SDL_Color textColor);

void renderMIPSArchitecture(bool test = true) {
    // Clear the renderer
    SDL_SetRenderDrawColor(gRenderer, 255, 255, 255, 255);
    SDL_RenderClear(gRenderer);

    // Get window dimensions
    int screenWidth, screenHeight;
    SDL_GetWindowSize(gWindow, &screenWidth, &screenHeight);

    // Use different color sets based on the button state
    SDL_Color* currentColorSet = buttonClicked ? colorSet2 : colorSet1;

    if (buttonClicked) {

    // Draw CPU
    SDL_Rect cpuRect = {50, 50, 200, 100};
    SDL_SetRenderDrawColor(gRenderer, 0, 0, 255, 255); // Blue
    SDL_RenderFillRect(gRenderer, &cpuRect);

    }

    // Draw Memory
    SDL_Rect memoryRect = {300, 50, 200, 400};
    SDL_SetRenderDrawColor(gRenderer, 0, 255, 0, 255); // Green
    SDL_RenderFillRect(gRenderer, &memoryRect);

    // Draw Registers
    SDL_Rect registerRect = {50, 200, 50, 200};
    SDL_SetRenderDrawColor(gRenderer, 255, 0, 0, 255); // Red
    SDL_RenderFillRect(gRenderer, &registerRect);

    // Render labels
    SDL_Color textColor = {0, 0, 0, 255}; // Black
    renderText("CPU", 50, 150, textColor);
    renderText("Memory", 350, 250, textColor);
    renderText("Registers", 50, 400, textColor);

    // Draw text box
    SDL_Rect textBoxRect = {50, 500, 500, 50};
    SDL_SetRenderDrawColor(gRenderer, 200, 200, 200, 255); // Light Gray
    SDL_RenderFillRect(gRenderer, &textBoxRect);
    renderText("Enter Text Here", 50 + 10, 500 + 10, textColor);

    // Draw button
    SDL_Rect buttonRect = {600, 500, 150, 50};
    SDL_SetRenderDrawColor(gRenderer, 150, 150, 150, 255); // Gray for the button
    SDL_RenderFillRect(gRenderer, &buttonRect);
    renderText("Click Me", 600 + 25, 500 + 10, textColor); // Text on the button

    // Present the renderer
    SDL_RenderPresent(gRenderer);
}

void handleButtonClick(SDL_Event& e) {
    int mouseX, mouseY;
    SDL_GetMouseState(&mouseX, &mouseY);

    // Check if the mouse click is within the button area
    if (mouseX >= 600 && mouseX <= 750 && mouseY >= 500 && mouseY <= 550) {
        // Toggle the button state
        buttonClicked = !buttonClicked;

        // Render MIPS architecture
        renderMIPSArchitecture(false);
    }
}

void renderText(const char* text, int x, int y, SDL_Color textColor) {
    SDL_Surface* textSurface = TTF_RenderText_Solid(gFont, text, textColor);
    SDL_Texture* textTexture = SDL_CreateTextureFromSurface(gRenderer, textSurface);

    int textWidth = textSurface->w;
    int textHeight = textSurface->h;

    SDL_Rect renderQuad = {x, y, textWidth, textHeight};

    SDL_RenderCopy(gRenderer, textTexture, nullptr, &renderQuad);

    SDL_FreeSurface(textSurface);
    SDL_DestroyTexture(textTexture);
}

static void mainloop()
{
    if (quit) {

        // Destroy the renderer, window, and font
        SDL_DestroyRenderer(gRenderer);
        SDL_DestroyWindow(gWindow);
        TTF_CloseFont(gFont);

        // Quit SDL_ttf and SDL
        TTF_Quit();
        SDL_Quit();

        #ifdef __EMSCRIPTEN__
        emscripten_cancel_main_loop();  /* this should "kill" the app. */
        #else
        exit(0);
        #endif
    }

    SDL_Event e;

    // Handle events on queue
    while (SDL_PollEvent(&e) != 0) {
        switch (e.type) {
            case SDL_QUIT:
                quit = true;
                break;
            case SDL_WINDOWEVENT:
                if (e.window.event == SDL_WINDOWEVENT_RESIZED) {
                    // Handle window resize
                    SDL_GetWindowSize(gWindow, nullptr, nullptr);
                    renderMIPSArchitecture();
                }
                break;

            case SDL_MOUSEBUTTONDOWN:
                // Handle button click
                std::cout << "why it no work" << std::endl;
                handleButtonClick(e);
                break;
        }
    }

    // Render MIPS architecture
    renderMIPSArchitecture();
}

int Init()
{
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    // Create a window
    gWindow = SDL_CreateWindow("MIPS Architecture", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    if (gWindow == nullptr) {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    // Create a renderer
    gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
    if (gRenderer == nullptr) {
        printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    // Initialize SDL_ttf
    if (TTF_Init() == -1) {
        printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
        return 1;
    }

    // Load font
    gFont = TTF_OpenFont("Roboto-Bold.ttf", 28); // Replace "arial.ttf" with the path to your font file
    if (gFont == nullptr) {
        printf("Failed to load font! SDL_ttf Error: %s\n", TTF_GetError());
        return 1;
    }
    return 0;
}

int main(int argc, char* argv[]) {
    Init();

    // Main event loop
    #ifdef __EMSCRIPTEN__
    emscripten_set_main_loop(mainloop, 0, 1);
    #else
    while (1) { mainloop(); }
    #endif

    return 0;
}
