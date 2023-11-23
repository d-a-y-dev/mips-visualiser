#include "design.h"
#include "SDL2/SDL.h"
#include <iostream>

void drawDottedLine(SDL_Renderer* renderer, SDL_Window* window, int gap, int height, int dotSpacing, int lineLength, int lineWidth) {
    // Get window dimensions
    int screenWidth, screenHeight;
    SDL_GetWindowSize(window, &screenWidth, &screenHeight);

    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // Set color to red

    for (int i = 0; i < screenWidth/gap ; i++)
    {
        for (int y = 0; y < height; y += dotSpacing)
        {
            SDL_Rect dotRect = {gap * (i + 1), y, lineLength, lineWidth};
            SDL_RenderFillRect(renderer, &dotRect);
        }
    }
}

void renderMIPSArchitecture(SDL_Window* window, SDL_Renderer* renderer) {
    // Get window dimensions
    int screenWidth, screenHeight;
    SDL_GetWindowSize(window, &screenWidth, &screenHeight);

    SDL_Color textColor = {0, 0, 0, 255}; // Black
    int spaceBetween = 256;

    // Draw Top Index

    // if (buttonClicked) {

    //     // Draw CPU
    //     SDL_Rect cpuRect = {50, 50, 200, 100};
    //     SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255); // Blue
    //     SDL_RenderFillRect(renderer, &cpuRect);
    //     renderText("CPU", 50, 150, textColor);
    // }

    // Draw Memory
    SDL_Rect memoryRect = {840, 50, 180, 250};
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255); // Green
    SDL_RenderFillRect(renderer, &memoryRect);


    // Draw ALU
    SDL_Rect aluRect = {615, 335, 150, 250};
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255); // Green
    SDL_RenderFillRect(renderer, &aluRect);

    // Draw DECODE
    SDL_Rect decodeRect = {315, 358, 150, 60};
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255); // Blue
    SDL_RenderFillRect(renderer, &decodeRect);


    // Draw Registerfile
    SDL_Rect registerfileRect = {316, 484, 150, 76};
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255); // Blue
    SDL_RenderFillRect(renderer, &registerfileRect);


    // Draw IR
    SDL_Rect irRect = {93, 176, 150, 44};
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255); // Blue
    SDL_RenderFillRect(renderer, &irRect);




    // Draw PC left
     const std::vector< SDL_Vertex > left_pc =
    {
        { SDL_FPoint{ 45, 291 }, SDL_Color{ 0, 255, 0, 255 }, SDL_FPoint{ 0 }, },
        { SDL_FPoint{ 35, 325 }, SDL_Color{ 0, 255, 0, 255 }, SDL_FPoint{ 0 }, },
        { SDL_FPoint{ 53, 325 }, SDL_Color{ 0, 255, 0, 255 }, SDL_FPoint{ 0 }, },
    };
    SDL_RenderGeometry( renderer, nullptr, left_pc.data(), left_pc.size(), nullptr, 0 );
    // Draw pc mux
    SDL_Rect pcRect = {45, 290, 153, 35};
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255); // Blue
    SDL_RenderFillRect(renderer, &pcRect);    
    // Draw PC mux right
     const std::vector< SDL_Vertex > right_pc =
    {
        { SDL_FPoint{ 200, 290 }, SDL_Color{ 0, 255, 0, 255 }, SDL_FPoint{ 0 }, },
        { SDL_FPoint{ 180, 325 }, SDL_Color{ 0, 255, 0, 255 }, SDL_FPoint{ 0 }, },
        { SDL_FPoint{ 210, 325 }, SDL_Color{ 0, 255, 0, 255 }, SDL_FPoint{ 0 }, },
    };
    SDL_RenderGeometry( renderer, nullptr, right_pc.data(), right_pc.size(), nullptr, 0 );





    // Draw mux execute top
     const std::vector< SDL_Vertex > left_mux_execute =
    {
        { SDL_FPoint{ 560, 340 }, SDL_Color{ 0, 255, 0, 255 }, SDL_FPoint{ 0 }, },
        { SDL_FPoint{ 560, 360 }, SDL_Color{ 0, 255, 0, 255 }, SDL_FPoint{ 0 }, },
        { SDL_FPoint{ 590, 360 }, SDL_Color{ 0, 255, 0, 255 }, SDL_FPoint{ 0 }, },
    };
    SDL_RenderGeometry( renderer, nullptr, left_mux_execute.data(), left_mux_execute.size(), nullptr, 0 );
     // Draw execute mux
    SDL_Rect executeRect = {560, 360, 27, 83};
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255); // Blue
    SDL_RenderFillRect(renderer, &executeRect);    
    // Draw mux execute down
     const std::vector< SDL_Vertex > right_mux_execute =
    {
        { SDL_FPoint{ 560, 440 }, SDL_Color{ 0, 255, 0, 255 }, SDL_FPoint{ 0 }, },
        { SDL_FPoint{ 590, 440 }, SDL_Color{ 0, 255, 0, 255 }, SDL_FPoint{ 0 }, },
        { SDL_FPoint{ 560, 460 }, SDL_Color{ 0, 255, 0, 255 }, SDL_FPoint{ 0 }, },
    };
    SDL_RenderGeometry( renderer, nullptr, right_mux_execute.data(), right_mux_execute.size(), nullptr, 0 );




    // Draw mux execute top
     const std::vector< SDL_Vertex > left_mux_decode =
    {
        { SDL_FPoint{ 485, 625 }, SDL_Color{ 0, 255, 0, 255 }, SDL_FPoint{ 0 }, },
        { SDL_FPoint{ 450, 650 }, SDL_Color{ 0, 255, 0, 255 }, SDL_FPoint{ 0 }, },
        { SDL_FPoint{ 485, 650 }, SDL_Color{ 0, 255, 0, 255 }, SDL_FPoint{ 0 }, },
    };
    SDL_RenderGeometry( renderer, nullptr, left_mux_decode.data(), left_mux_decode.size(), nullptr, 0 );
     // Draw execute mux
    SDL_Rect decodeMuxRect = {450, 648, 35, 40};
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255); // Blue
    SDL_RenderFillRect(renderer, &decodeMuxRect);    
    // Draw mux execute down
     const std::vector< SDL_Vertex > right_mux_decode =
    {
        { SDL_FPoint{ 450, 690 }, SDL_Color{ 0, 255, 0, 255 }, SDL_FPoint{ 0 }, },
        { SDL_FPoint{ 485, 650 }, SDL_Color{ 0, 255, 0, 255 }, SDL_FPoint{ 0 }, },
        { SDL_FPoint{ 485, 710 }, SDL_Color{ 0, 255, 0, 255 }, SDL_FPoint{ 0 }, },
    };
    SDL_RenderGeometry( renderer, nullptr, right_mux_decode.data(), right_mux_decode.size(), nullptr, 0 );

    // Draw Registers
    // SDL_Rect registerRect = {50, 200, 50, 200};
    // SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // Red
    // SDL_RenderFillRect(renderer, &registerRect);
    // renderText("Registers", 50, 400, textColor);

    // Draw text box
    // SDL_Rect textBoxRect = {50, 500, 500, 50};
    // SDL_SetRenderDrawColor(renderer, 200, 200, 200, 255); // Light Gray
    // SDL_RenderFillRect(renderer, &textBoxRect);
    // renderText("Enter Text Here", 50 + 10, 500 + 10, textColor);

    // // Draw button
    // SDL_Rect buttonRect = {600, 500, 150, 50};
    // SDL_SetRenderDrawColor(renderer, 150, 150, 150, 255); // Gray for the button
    // SDL_RenderFillRect(renderer, &buttonRect);
    // renderText("Click Me", 600 + 25, 500 + 10, textColor); // Text on the button

    // Draw name for each pipeline
    renderText("Fetch", 100, 0, textColor);
    renderText("Decode", 350, 0, textColor);
    renderText("Execute", 600, 0, textColor);
    renderText("Memory", 850, 0, textColor);
    renderText("Writeback", 1100, 0, textColor);


     // Draw dotted line vertically for each stage of the pipeline
    drawDottedLine(renderer, window, 256, screenHeight, 50, 10, 30); // 400 is the x-coordinate for the middle of the screen, 10 is the line width
}
