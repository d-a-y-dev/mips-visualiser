#include "design.h"
#include "SDL2/SDL.h"
#include "components.h"
#include "../shell.hpp"
#include <iostream>
#include <sstream>

void drawDottedLine(SDL_Renderer* renderer, SDL_Window* window, std::vector<int> gaps, int height, int dotSpacing, int lineLength, int lineWidth) {
    // Get window dimensions
    int screenWidth, screenHeight;
    SDL_GetWindowSize(window, &screenWidth, &screenHeight);

    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 0); // Set color to red

    for (int i : gaps)
    {
        for (int y = 0; y < height; y += dotSpacing)
        {
            SDL_Rect dotRect = {i, y, lineLength, lineWidth};
            SDL_RenderFillRect(renderer, &dotRect);
        }
    }
}

void renderMIPSArchitecture(SDL_Window* window, SDL_Renderer* renderer, int currentCycle) {
    // Get window dimensions
    int screenWidth, screenHeight;
    SDL_GetWindowSize(window, &screenWidth, &screenHeight);

    SDL_Color textColor = {0, 0, 0, 255}; // Black
    int spaceBetween = 256;

    SDL_Color color = SDL_Color{0,0,0, 255}; // Black
    SDL_Color black = SDL_Color{0,0,0, 255}; // Black
    SDL_Color red = SDL_Color{255,0,0,255}; // Red
    SDL_Color blue = SDL_Color{0,0,255,255}; // Blue
    SDL_Color green = SDL_Color{0,255,0,255}; // Green
    SDL_Color orange = SDL_Color{255,148,112,255}; // Green


    // Inside Fetch
    draw_fetch_mux(renderer, black);
    draw_fetch_pc(renderer, black);
    draw_line_pc_to_main_memory(renderer, black);
    draw_line_mux_to_pc(renderer, black);

    if (!Cycle_Instances.empty() && (currentCycle < Cycle_Instances.size() - 4))
    {
        draw_fetch_mux(renderer, red);
        draw_fetch_pc(renderer, red);
        draw_line_pc_to_main_memory(renderer, red);
        draw_line_mux_to_pc(renderer, red);

        std::stringstream ss;
        ss << std::hex << Cycle_Instances[currentCycle].CPU_State.PC - 4;
        renderText(ss.str().c_str(), 120, 185, textColor);
    }
    renderText("PC", 100, 140, textColor);
    renderText("PC + 4", 15, 412, textColor);

    // Inside Decode
    draw_decode_decoder(renderer, black);
    draw_decode_mux_to_alu(renderer, black);
    draw_decode_register_files(renderer, black);
    draw_line_decoder_to_mux_sel(renderer, black);
    draw_line_decoder_to_mux_imm(renderer, black);
    draw_line_decoder_to_mux_to_fetch(renderer, black);
    draw_line_decoder_to_mux_to_alu_sel(renderer, black);
    draw_line_decoder_to_mux_to_alu_imm(renderer, black);
    draw_line_decode_mux_to_alu(renderer, black);
    draw_line_decoder_to_register_file(renderer, black);
    draw_line_decoder_to_mux_to_pc(renderer, black);
    draw_line_register_files_to_fetch_mux(renderer, black);
    draw_line_register_files_to_mux_to_alu_1(renderer, black);
    draw_line_register_files_to_mux_to_alu_2(renderer, black);

    if
    (
        (currentCycle-1 >= 0) && (currentCycle < Cycle_Instances.size() - 3)
        // Check if no ops
        &&
        !(Cycle_Instances[currentCycle].IDEX_Reg.ALUOp == 0 &&
        Cycle_Instances[currentCycle].IDEX_Reg.ALUSrc == 0 &&
        Cycle_Instances[currentCycle].IDEX_Reg.Jump == 0 &&
        Cycle_Instances[currentCycle].IDEX_Reg.RegWrite == 0 &&
        Cycle_Instances[currentCycle].IDEX_Reg.Syscall == 0
        )
    )
    {
        draw_decode_decoder(renderer, blue);

        std::stringstream ss;
        ss << std::hex << Cycle_Instances[currentCycle-1].CPU_State.PC - 4;
        renderText(ss.str().c_str(), 340, 372, textColor);

        IDEX_PILELINE_REG idex_regs = Cycle_Instances[currentCycle].IDEX_Reg;

        if (idex_regs.Jump == HIGH)
        {
            if (idex_regs.RegWrite == HIGH)
            {

            }
            else
            {
                if (DATA_FORWARD == false)
                {
                    draw_line_decoder_to_mux_to_alu_sel(renderer, blue);
                    draw_line_decoder_to_mux_to_alu_imm(renderer, blue);
                }
                else
                {
                    draw_line_decoder_to_mux_sel(renderer, blue);
                    draw_line_decoder_to_mux_imm(renderer, blue);
                }
            }
        }

        else if (idex_regs.ALUOp == HIGH && idex_regs.ALUSrc == HIGH)
        {
            draw_decode_mux_to_alu(renderer, blue);
            draw_decode_register_files(renderer, blue);

            draw_line_decoder_to_register_file(renderer, blue);
            draw_line_decoder_to_mux_to_alu_sel(renderer, blue);
            draw_line_register_files_to_mux_to_alu_1(renderer, blue);
            draw_line_decoder_to_mux_to_alu_imm(renderer, blue);
            draw_line_decode_mux_to_alu(renderer, blue);
        } else if (idex_regs.ALUOp == HIGH || idex_regs.Syscall == HIGH)
        {
            draw_decode_mux_to_alu(renderer, blue);
            draw_decode_register_files(renderer, blue);

            draw_line_register_files_to_mux_to_alu_1(renderer, blue);
            draw_line_register_files_to_mux_to_alu_2(renderer, blue);
            draw_line_decoder_to_mux_to_alu_sel(renderer, blue);
            draw_line_decoder_to_register_file(renderer, blue);
            draw_line_decode_mux_to_alu(renderer, blue);
        }
        // IF Jump/Branch
        // IF use ALU.OP = high
        // IF ALUSrc = high, use extendimm (no need to access registerfiles)
    }


    // Inside Execute
    draw_execute_alu(renderer, black);
    draw_line_alu_to_main_memory_data(renderer, black);
    draw_line_alu_to_main_memory_address(renderer, black);
    draw_line_alu_to_mux_to_pc_1(renderer, black);

    if (currentCycle-2 >= 0 && (currentCycle < Cycle_Instances.size() - 2) &&
    (Cycle_Instances[currentCycle-1].Stall_Unit.Decode == 0 && Cycle_Instances[currentCycle-2].Stall_Unit.Decode == 0 )
    // check no ops
    && !(Cycle_Instances[currentCycle].EXMEM_Reg.Jump == 0 && Cycle_Instances[currentCycle].EXMEM_Reg.RegWrite == 0 && Cycle_Instances[currentCycle].EXMEM_Reg.Syscall == 0)
    )
    {
        EXMEM_PIPELINE_REG exmem_regs = Cycle_Instances[currentCycle].EXMEM_Reg;

        if (exmem_regs.Jump == LOW)
        {
            draw_execute_alu(renderer, green);
        }
        else if (exmem_regs.Jump == HIGH && DATA_FORWARD == false)
        {
            draw_execute_alu(renderer, green);
            draw_line_alu_to_mux_to_pc_1(renderer, green);
        }

        std::stringstream ss;
        ss << std::hex << Cycle_Instances[currentCycle-2].CPU_State.PC - 4;
        renderText(ss.str().c_str(), 638, 355, textColor);


        if(exmem_regs.MemWrite == HIGH)
        {
            draw_line_alu_to_main_memory_data(renderer, green);
            draw_line_alu_to_main_memory_address(renderer, green);
        }
        else if (exmem_regs.MemRead == HIGH)
        {
            draw_line_alu_to_main_memory_address(renderer, green);
        }
        else if (exmem_regs.RegDst == HIGH || exmem_regs.Syscall == HIGH)
        {
            draw_line_alu_to_mux_to_pc_1(renderer, green);
        }
    }

    //


    // Inside Memory
    draw_memory_main_memory(renderer, black);
    draw_line_main_memory_to_decoder(renderer, black);
    draw_line_main_memory_to_mux_to_pc(renderer, black);
    draw_line_alu_to_mux_to_pc_2(renderer, black);

    if ((currentCycle-1 >= 0) && (currentCycle < Cycle_Instances.size() - 3)
    && // Check if no ops
    !(Cycle_Instances[currentCycle].IDEX_Reg.ALUOp == 0 &&
    Cycle_Instances[currentCycle].IDEX_Reg.ALUSrc == 0 &&
    Cycle_Instances[currentCycle].IDEX_Reg.Jump == 0 &&
    Cycle_Instances[currentCycle].IDEX_Reg.RegWrite == 0 &&
    Cycle_Instances[currentCycle].IDEX_Reg.Syscall == 0)
    )
    {
        draw_memory_main_memory(renderer, blue);
        draw_line_main_memory_to_decoder(renderer, blue);
    }

    if (currentCycle - 3 >= 0  && (currentCycle < Cycle_Instances.size() - 1) &&
    (Cycle_Instances[currentCycle-2].Stall_Unit.Decode == 0 && Cycle_Instances[currentCycle-3].Stall_Unit.Decode == 0 )
    // Check no ops
    && !(Cycle_Instances[currentCycle].MEMWB_Reg.Jump == 0 && Cycle_Instances[currentCycle].MEMWB_Reg.RegWrite == 0 && Cycle_Instances[currentCycle].MEMWB_Reg.Syscall == 0)
    )
    {
        MEMWB_PIPELINE_REG memwb_regs = Cycle_Instances[currentCycle].MEMWB_Reg;

        if (memwb_regs.RegDst == HIGH || memwb_regs.Syscall == HIGH)
        {
            std::stringstream ss;
            ss << std::hex << Cycle_Instances[currentCycle-3].CPU_State.PC - 4;
            renderText(ss.str().c_str(), 860, 440, textColor);
            draw_line_alu_to_mux_to_pc_2(renderer, green);
        }
        else if (memwb_regs.Jump == HIGH && DATA_FORWARD == false)
        {
            std::stringstream ss;
            ss << std::hex << Cycle_Instances[currentCycle-3].CPU_State.PC - 4;
            renderText(ss.str().c_str(), 860, 440, textColor);
            draw_line_alu_to_mux_to_pc_2(renderer, green);
        }
    }


    // Inside Writeback
    draw_line_alu_to_mux_to_pc_3(renderer, black);
    // Under
    draw_decode_mux_to_fetch(renderer, black);
    draw_line_mux_to_mux(renderer, black);

    if (currentCycle - 4 >= 0 && currentCycle != Cycle_Instances.size())
    {
        WROTE_BACK wrote_regs = Cycle_Instances[currentCycle].WROTE_Reg;

        if (wrote_regs.RegWrite == HIGH || wrote_regs.Syscall == HIGH || (wrote_regs.Jump == HIGH && DATA_FORWARD == FALSE))
        {
            std::stringstream ss;
            ss << std::hex << Cycle_Instances[currentCycle-4].CPU_State.PC - 4;
            renderText(ss.str().c_str(), 860, 635, textColor);

            draw_line_alu_to_mux_to_pc_3(renderer, green);
            draw_decode_mux_to_fetch(renderer, green);
            draw_line_mux_to_mux(renderer, green);
        }
    }




    // FETCH    renderText("Next", 40, 236, textColor);


    renderText("Data", 85, 681, textColor);

    renderText("Reg.", 145, 525, textColor);
    renderText("Data", 145, 565, textColor);

    renderText("Sel", 196, 440, textColor);

    renderText("Imm", 197, 348, textColor);

    renderText("Sel", 243, 264, textColor);


    // Decode
    renderText("Sel", 322, 434, textColor);

    renderText("Data2", 440, 441, textColor);

    renderText("Data1", 525, 509, textColor);

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
