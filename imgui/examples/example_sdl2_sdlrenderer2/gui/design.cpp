#include "design.h"
#include "SDL2/SDL.h"
#include "components.h"
#include <iostream>

void drawDottedLine(SDL_Renderer* renderer, SDL_Window* window, std::vector<int> gaps, int height, int dotSpacing, int lineLength, int lineWidth) {
    // Get window dimensions
    int screenWidth, screenHeight;
    SDL_GetWindowSize(window, &screenWidth, &screenHeight);

    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // Set color to red

    for (int i : gaps)
    {
        for (int y = 0; y < height; y += dotSpacing)
        {
            SDL_Rect dotRect = {i, y, lineLength, lineWidth};
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

    SDL_Color color = SDL_Color{0,0,0, 255};

    draw_fetch_mux(renderer, color);
    draw_fetch_pc(renderer, color);
    draw_decode_decoder(renderer, color);
    draw_decode_register_files(renderer, color);
    draw_decode_mux_to_alu(renderer, color);
    draw_decode_mux_to_fetch(renderer, color);
    draw_execute_alu(renderer, color);
    draw_memory_main_memory(renderer, color);
    draw_line_pc_to_main_memory(renderer, color);
    draw_line_mux_to_pc(renderer, color);
    draw_line_main_memory_to_decoder(renderer, color);
    draw_line_decoder_to_mux_sel(renderer, color);
    draw_line_decoder_to_mux_imm(renderer, color);
    draw_line_decoder_to_mux_to_fetch(renderer, color);
    draw_line_decoder_to_mux_to_alu_imm(renderer, color);
    draw_line_decoder_to_mux_to_alu_sel(renderer, color);
    draw_line_register_files_to_fetch_mux(renderer, color);
    draw_line_register_files_to_mux_to_alu(renderer, color);
    draw_line_decode_mux_to_alu(renderer, color);
    draw_line_alu_to_main_memory_data(renderer, color);
    draw_line_alu_to_main_memory_address(renderer, color);
    draw_line_alu_to_mux_to_pc(renderer, color);
    draw_line_main_memory_to_mux_to_pc(renderer, color);
    draw_line_mux_to_mux(renderer, color);
    draw_line_decoder_to_register_file(renderer, color);
    draw_line_decoder_to_mux_to_pc(renderer, color);

    // FETCH    renderText("Next", 40, 236, textColor);
    renderText("PC", 50, 263, textColor);

    renderText("PC + 4", 15, 412, textColor);

    renderText("Data", 85, 681, textColor);

    renderText("Reg.", 145, 525, textColor);
    renderText("Data", 145, 565, textColor);

    renderText("Sel", 196, 440, textColor);

    renderText("Imm", 197, 348, textColor);

    renderText("Sel", 243, 264, textColor);


    // Decode
    renderText("Sel", 322, 434, textColor);

    renderText("Operands", 405, 447, textColor);

    renderText("Imm", 479, 343, textColor);

    renderText("Sel", 479, 273, textColor);

    renderText("Instruction", 441, 150, textColor);

    renderText("Address", 401, 68, textColor);

    //Execute
    renderText("Data", 621, 247, textColor);

    renderText("Address", 692, 265, textColor);

    renderText("ALU", 645, 589, textColor);

    //Memory
    renderText("Main Memory", 832, 277, textColor);

    renderText("Data", 885, 389, textColor);

    //Writeback
    renderText("Data", 1036, 198, textColor);

    // Draw name for each pipeline
    renderText("Fetch", 100, 0, textColor);
    renderText("Decode", 350, 0, textColor);
    renderText("Execute", 600, 0, textColor);
    renderText("Memory", 850, 0, textColor);
    renderText("Writeback", 1100, 0, textColor);


     // Draw dotted line vertically for each stage of the pipeline
    drawDottedLine(renderer, window, {298, 597, 812, 1017}, screenHeight, 50, 10, 30); // 400 is the x-coordinate for the middle of the screen, 10 is the line width
}
