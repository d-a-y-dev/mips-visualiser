#include "SDL2/SDL.h"
#include "components.h"
#include <iostream>
#include <vector>


void draw_fetch_mux(SDL_Renderer* renderer, SDL_Color color)
{
    const std::vector< SDL_Vertex > left_pc =
    {
        { SDL_FPoint{ 45, 291 }, color, SDL_FPoint{ 0 }, },
        { SDL_FPoint{ 35, 325 }, color, SDL_FPoint{ 0 }, },
        { SDL_FPoint{ 53, 325 }, color, SDL_FPoint{ 0 }, },
    };
    SDL_RenderGeometry( renderer, nullptr, left_pc.data(), left_pc.size(), nullptr, 0 );
    // Draw pc mux
    SDL_Rect pcRect = {45, 290, 153, 35};
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a); // Blue
    SDL_RenderFillRect(renderer, &pcRect);
    // Draw PC mux right
    const std::vector< SDL_Vertex > right_pc =
    {
        { SDL_FPoint{ 200, 290 }, color, SDL_FPoint{ 0 }, },
        { SDL_FPoint{ 180, 325 }, color, SDL_FPoint{ 0 }, },
        { SDL_FPoint{ 210, 325 }, color, SDL_FPoint{ 0 }, },
    };
    SDL_RenderGeometry( renderer, nullptr, right_pc.data(), right_pc.size(), nullptr, 0 );
    return;
}

void draw_fetch_pc(SDL_Renderer* renderer, SDL_Color color)
{
    SDL_Rect irRect = {93, 176, 150, 44};
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a); // Blue
    SDL_RenderFillRect(renderer, &irRect);
    return;
}

void draw_decode_decoder(SDL_Renderer* renderer, SDL_Color color)
{
    SDL_Rect decodeRect = {315, 358, 150, 60};
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a); // Blue
    SDL_RenderFillRect(renderer, &decodeRect);
    return;
}

void draw_decode_register_files(SDL_Renderer* renderer, SDL_Color color)
{
    SDL_Rect registerfileRect = {316, 484, 150, 76};
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a); // Blue
    SDL_RenderFillRect(renderer, &registerfileRect);
    return;
}

void draw_decode_mux_to_alu(SDL_Renderer* renderer, SDL_Color color)
{
    const std::vector< SDL_Vertex > left_mux_execute =
    {
        { SDL_FPoint{ 560, 340 }, color, SDL_FPoint{ 0 }, },
        { SDL_FPoint{ 560, 360 }, color, SDL_FPoint{ 0 }, },
        { SDL_FPoint{ 590, 360 }, color, SDL_FPoint{ 0 }, },
    };
    SDL_RenderGeometry( renderer, nullptr, left_mux_execute.data(), left_mux_execute.size(), nullptr, 0 );
     // Draw execute mux
    SDL_Rect executeRect = {560, 360, 27, 83};
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a); // Blue
    SDL_RenderFillRect(renderer, &executeRect);
    // Draw mux execute down
    const std::vector< SDL_Vertex > right_mux_execute =
    {
        { SDL_FPoint{ 560, 440 }, color, SDL_FPoint{ 0 }, },
        { SDL_FPoint{ 590, 440 }, color, SDL_FPoint{ 0 }, },
        { SDL_FPoint{ 560, 460 }, color, SDL_FPoint{ 0 }, },
    };
    SDL_RenderGeometry( renderer, nullptr, right_mux_execute.data(), right_mux_execute.size(), nullptr, 0 );
    return;
}

void draw_decode_mux_to_fetch(SDL_Renderer* renderer, SDL_Color color) {
    // Draw mux execute top
    const std::vector< SDL_Vertex > left_mux_decode =
    {
        { SDL_FPoint{ 485, 625 }, color, SDL_FPoint{ 0 }, },
        { SDL_FPoint{ 450, 650 }, color, SDL_FPoint{ 0 }, },
        { SDL_FPoint{ 485, 650 }, color, SDL_FPoint{ 0 }, },
    };
    SDL_RenderGeometry( renderer, nullptr, left_mux_decode.data(), left_mux_decode.size(), nullptr, 0 );
     // Draw decode mux
    SDL_Rect decodeMuxRect = {450, 648, 35, 40};
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a); // Blue
    SDL_RenderFillRect(renderer, &decodeMuxRect);
    // Draw mux decode down
    const std::vector< SDL_Vertex > right_mux_decode =
    {
        { SDL_FPoint{ 450, 690 }, color, SDL_FPoint{ 0 }, },
        { SDL_FPoint{ 485, 650 }, color, SDL_FPoint{ 0 }, },
        { SDL_FPoint{ 485, 710 }, color, SDL_FPoint{ 0 }, },
    };
    SDL_RenderGeometry( renderer, nullptr, right_mux_decode.data(), right_mux_decode.size(), nullptr, 0 );
    return;
}


void draw_execute_alu(SDL_Renderer* renderer, SDL_Color color)
{
    SDL_Rect aluRect = {620, 335, 150, 240};
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a); // Green
    SDL_RenderFillRect(renderer, &aluRect);
    return;
}


void draw_memory_main_memory(SDL_Renderer* renderer, SDL_Color color)
{
    SDL_Rect memoryRect = {840, 50, 160, 215};
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a); // Green
    SDL_RenderFillRect(renderer, &memoryRect);
    return;
}

void draw_line_pc_to_main_memory(SDL_Renderer* renderer, SDL_Color color)
{
    // Draw line form PC to memory
    // Strat form PC
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a); // Black
    SDL_RenderDrawLine(renderer, 170, 176, 170, 105);
    SDL_RenderDrawLine(renderer, 169, 176, 169, 105);
    SDL_RenderDrawLine(renderer, 168, 176, 168, 105);

    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a); // Black
    SDL_RenderDrawLine(renderer, 170, 104, 836, 104);
    SDL_RenderDrawLine(renderer, 170, 105, 836, 105);
    SDL_RenderDrawLine(renderer, 170, 106, 836, 106);


    const std::vector< SDL_Vertex > irArrow =
    {
        { SDL_FPoint{ 825, 95 }, SDL_Color{ color.r, color.g, color.b, color.a }, SDL_FPoint{ 0 }, },
        { SDL_FPoint{ 845, 105 }, SDL_Color{ color.r, color.g, color.b, color.a }, SDL_FPoint{ 0 }, },
        { SDL_FPoint{ 825, 115 }, SDL_Color{ color.r, color.g, color.b, color.a }, SDL_FPoint{ 0 }, },
    };
    SDL_RenderGeometry( renderer, nullptr, irArrow.data(), irArrow.size(), nullptr, 0 );
    return;
}

void draw_line_mux_to_pc(SDL_Renderer* renderer, SDL_Color color)
{
        // Draw line form Pc mux to IR

    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a); // Black
    SDL_RenderDrawLine(renderer, 133, 292, 133, 220);
    SDL_RenderDrawLine(renderer, 132, 292, 132, 220);
    SDL_RenderDrawLine(renderer, 131, 292, 131, 220);

    const std::vector< SDL_Vertex > pcToIRArrow =
    {
        { SDL_FPoint{ 133, 218 }, SDL_Color{ color.r, color.g, color.b, color.a }, SDL_FPoint{ 0 }, },
        { SDL_FPoint{ 122, 234 }, SDL_Color{ color.r, color.g, color.b, color.a }, SDL_FPoint{ 0 }, },
        { SDL_FPoint{ 142, 234 }, SDL_Color{ color.r, color.g, color.b, color.a }, SDL_FPoint{ 0 }, },
    };
    SDL_RenderGeometry( renderer, nullptr, pcToIRArrow.data(), pcToIRArrow.size(), nullptr, 0 );
    return;
}

void draw_line_main_memory_to_decoder(SDL_Renderer* renderer, SDL_Color color)
{
    // memory to decode
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderDrawLine(renderer,390,186,843,186);
    SDL_RenderDrawLine(renderer,390,187,843,187);
    SDL_RenderDrawLine(renderer,390,188,843,188);

    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderDrawLine(renderer,390,186,390,360);
    SDL_RenderDrawLine(renderer,390,187,390,361);
    SDL_RenderDrawLine(renderer,390,188,390,362);


    const std::vector< SDL_Vertex > memoryToDeocdeArrow =
    {
        { SDL_FPoint{ 382, 345 }, SDL_Color{ color.r, color.g, color.b, color.a }, SDL_FPoint{ 0 }, },
        { SDL_FPoint{ 398, 343 }, SDL_Color{ color.r, color.g, color.b, color.a }, SDL_FPoint{ 0 }, },
        { SDL_FPoint{ 391, 359 }, SDL_Color{ color.r, color.g, color.b, color.a }, SDL_FPoint{ 0 }, },
    };
    SDL_RenderGeometry( renderer, nullptr, memoryToDeocdeArrow.data(), memoryToDeocdeArrow.size(), nullptr, 0 );
}

void draw_line_decoder_to_mux_sel(SDL_Renderer* renderer, SDL_Color color)
{
    // Draw line form decode to Pc mux (Sel)
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a); // Black
    SDL_RenderDrawLine(renderer, 207, 305, 342, 305);
    SDL_RenderDrawLine(renderer, 207, 306, 342, 306);
    SDL_RenderDrawLine(renderer, 207, 307, 342, 307);



    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a); // Black
    SDL_RenderDrawLine(renderer, 341, 305, 341, 355);
    SDL_RenderDrawLine(renderer, 342, 305, 342, 355);
    SDL_RenderDrawLine(renderer, 343, 305, 343, 355);


    const std::vector< SDL_Vertex > decodeToPCMuxSelArrow =
    {
        { SDL_FPoint{ 220, 296 }, SDL_Color{ color.r, color.g, color.b, color.a }, SDL_FPoint{ 0 }, },
        { SDL_FPoint{ 205, 306 }, SDL_Color{ color.r, color.g, color.b, color.a }, SDL_FPoint{ 0 }, },
        { SDL_FPoint{ 220, 317 }, SDL_Color{ color.r, color.g, color.b, color.a }, SDL_FPoint{ 0 }, },
    };
    SDL_RenderGeometry( renderer, nullptr, decodeToPCMuxSelArrow.data(), decodeToPCMuxSelArrow.size(), nullptr, 0 );
    return;
}

void draw_line_decoder_to_mux_to_alu_imm(SDL_Renderer* renderer, SDL_Color color)
{


    // decode to decodeMux
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderDrawLine(renderer,487,647,534,647);
    SDL_RenderDrawLine(renderer,487,648,534,648);
    SDL_RenderDrawLine(renderer,487,649,534,649);


    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderDrawLine(renderer,533,380,533,648);
    SDL_RenderDrawLine(renderer,534,380,534,648);
    SDL_RenderDrawLine(renderer,535,380,535,648);

    const std::vector< SDL_Vertex > muxNearAluToDecodeMux =
    {
        { SDL_FPoint{ 485, 648 }, SDL_Color{ color.r, color.g, color.b, color.a }, SDL_FPoint{ 0 }, },
        { SDL_FPoint{ 502, 638 }, SDL_Color{ color.r, color.g, color.b, color.a }, SDL_FPoint{ 0 }, },
        { SDL_FPoint{ 502, 658 }, SDL_Color{ color.r, color.g, color.b, color.a }, SDL_FPoint{ 0 }, },
    };
    SDL_RenderGeometry( renderer, nullptr, muxNearAluToDecodeMux.data(), muxNearAluToDecodeMux.size(), nullptr, 0 );




    // deocode to decodeMuxNearAlu(Imm)
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderDrawLine(renderer,465,379,561,379);
    SDL_RenderDrawLine(renderer,465,380,561,380);
    SDL_RenderDrawLine(renderer,465,381,561,381);


    const std::vector< SDL_Vertex > decodeTodecodeMuxNearAluImmArrow =
    {
        { SDL_FPoint{ 546, 372 }, SDL_Color{ color.r, color.g, color.b, color.a }, SDL_FPoint{ 0 }, },

        { SDL_FPoint{ 547, 388 }, SDL_Color{ color.r, color.g, color.b, color.a }, SDL_FPoint{ 0 }, },
        { SDL_FPoint{ 561, 380 }, SDL_Color{ color.r, color.g, color.b, color.a }, SDL_FPoint{ 0 }, },
    };
    SDL_RenderGeometry( renderer, nullptr, decodeTodecodeMuxNearAluImmArrow.data(), decodeTodecodeMuxNearAluImmArrow.size(), nullptr, 0 );
    return;
}

void draw_line_decoder_to_mux_to_alu_sel(SDL_Renderer* renderer, SDL_Color color)
{
    // deocode to decodeMuxNearAlu(Sel)

    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderDrawLine(renderer,439,360,439,310);
    SDL_RenderDrawLine(renderer,440,360,440,310);
    SDL_RenderDrawLine(renderer,441,360,441,310);

    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderDrawLine(renderer,440,308,579,308);
    SDL_RenderDrawLine(renderer,440,309,579,309);
    SDL_RenderDrawLine(renderer,440,310,579,310);

    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderDrawLine(renderer,579,309,579,350);
    SDL_RenderDrawLine(renderer,580,309,580,350);
    SDL_RenderDrawLine(renderer,581,309,581,350);

    const std::vector< SDL_Vertex > decodeTodecodeMuxNearAluSelArrow =
    {
        { SDL_FPoint{ 570, 338 }, SDL_Color{ color.r, color.g, color.b, color.a }, SDL_FPoint{ 0 }, },
        { SDL_FPoint{ 590, 338 }, SDL_Color{ color.r, color.g, color.b, color.a }, SDL_FPoint{ 0 }, },
        { SDL_FPoint{ 580, 353 }, SDL_Color{ color.r, color.g, color.b, color.a }, SDL_FPoint{ 0 }, },
    };
    SDL_RenderGeometry( renderer, nullptr, decodeTodecodeMuxNearAluSelArrow.data(), decodeTodecodeMuxNearAluSelArrow.size(), nullptr, 0 );
    return;
}

void draw_line_register_files_to_fetch_mux(SDL_Renderer* renderer, SDL_Color color)
{
    // Draw line form registerfile to Pc mux
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a); // Black
    SDL_RenderDrawLine(renderer, 141, 327, 141, 503);
    SDL_RenderDrawLine(renderer, 142, 327, 142, 503);
    SDL_RenderDrawLine(renderer, 143, 327, 143, 503);


    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a); // Black
    SDL_RenderDrawLine(renderer, 142, 502, 315, 502);
    SDL_RenderDrawLine(renderer, 142, 503, 315, 503);
    SDL_RenderDrawLine(renderer, 142, 504, 315, 504);


    const std::vector< SDL_Vertex > registerToPCMuxArrow =
    {
        { SDL_FPoint{ 142, 325 }, SDL_Color{ color.r, color.g, color.b, color.a }, SDL_FPoint{ 0 }, },
        { SDL_FPoint{ 132, 339 }, SDL_Color{ color.r, color.g, color.b, color.a }, SDL_FPoint{ 0 }, },
        { SDL_FPoint{ 152, 339 }, SDL_Color{ color.r, color.g, color.b, color.a }, SDL_FPoint{ 0 }, },
    };
    SDL_RenderGeometry( renderer, nullptr, registerToPCMuxArrow.data(), registerToPCMuxArrow.size(), nullptr, 0 );
    return;
}

void draw_line_register_files_to_mux_to_alu_2(SDL_Renderer* renderer, SDL_Color color)
{
    // Registerfile to MuxNearAlu
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderDrawLine(renderer,465,501,520,501);
    SDL_RenderDrawLine(renderer,465,502,520,502);
    SDL_RenderDrawLine(renderer,465,503,520,503);

    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderDrawLine(renderer,519,424,519,502);
    SDL_RenderDrawLine(renderer,520,424,520,502);
    SDL_RenderDrawLine(renderer,521,424,521,502);

    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderDrawLine(renderer,520,422,562,422);
    SDL_RenderDrawLine(renderer,520,423,562,423);
    SDL_RenderDrawLine(renderer,520,424,562,424);

    const std::vector< SDL_Vertex > registerFileToMuxNearAlu =
    {
        { SDL_FPoint{ 546, 413 }, SDL_Color{ color.r, color.g, color.b, color.a }, SDL_FPoint{ 0 }, },
        { SDL_FPoint{ 561, 423 }, SDL_Color{ color.r, color.g, color.b, color.a }, SDL_FPoint{ 0 }, },
        { SDL_FPoint{ 546, 433 }, SDL_Color{ color.r, color.g, color.b, color.a }, SDL_FPoint{ 0 }, },
    };
    SDL_RenderGeometry( renderer, nullptr, registerFileToMuxNearAlu.data(), registerFileToMuxNearAlu.size(), nullptr, 0 );
    return;
}

void draw_line_register_files_to_mux_to_alu_1(SDL_Renderer* renderer, SDL_Color color)
{
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderDrawLine(renderer,465,539,600,539);
    SDL_RenderDrawLine(renderer,465,540,600,540);
    SDL_RenderDrawLine(renderer,465,541,600,541);

    const std::vector< SDL_Vertex > registerFileToMuxNearAlu =
    {
        { SDL_FPoint{ 600, 530 }, SDL_Color{ color.r, color.g, color.b, color.a }, SDL_FPoint{ 0 }, },
        { SDL_FPoint{ 620, 540 }, SDL_Color{ color.r, color.g, color.b, color.a }, SDL_FPoint{ 0 }, },
        { SDL_FPoint{ 600, 550 }, SDL_Color{ color.r, color.g, color.b, color.a }, SDL_FPoint{ 0 }, },
    };
    SDL_RenderGeometry( renderer, nullptr, registerFileToMuxNearAlu.data(), registerFileToMuxNearAlu.size(), nullptr, 0 );
    return;
}


void draw_line_decode_mux_to_alu(SDL_Renderer* renderer, SDL_Color color)
{
    // MuxNearAlu to Alu
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderDrawLine(renderer,584,403,612,403);
    SDL_RenderDrawLine(renderer,584,404,612,404);
    SDL_RenderDrawLine(renderer,584,405,612,405);

    const std::vector< SDL_Vertex > muxNearAluToAlu =
    {
        { SDL_FPoint{ 610, 398 }, color , SDL_FPoint{ 0 }, },
        { SDL_FPoint{ 620, 404 }, color, SDL_FPoint{ 0 }, },
        { SDL_FPoint{ 610, 411 }, color, SDL_FPoint{ 0 }, },
    };
    SDL_RenderGeometry( renderer, nullptr, muxNearAluToAlu.data(), muxNearAluToAlu.size(), nullptr, 0 );
    return;
}

void draw_line_alu_to_main_memory_data(SDL_Renderer* renderer, SDL_Color color)
{
    // Alu to memory (data)
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderDrawLine(renderer,660,208,842,208);
    SDL_RenderDrawLine(renderer,660,209,842,209);
    SDL_RenderDrawLine(renderer,660,210,842,210);


    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderDrawLine(renderer,660,330,660,212);
    SDL_RenderDrawLine(renderer,661,330,661,212);
    SDL_RenderDrawLine(renderer,662,330,662,212);


    const std::vector< SDL_Vertex > AluToMemoryData =
    {
        { SDL_FPoint{ 828, 201 }, SDL_Color{ color.r, color.g, color.b, color.a }, SDL_FPoint{ 0 }, },
        { SDL_FPoint{ 843, 208 }, SDL_Color{ color.r, color.g, color.b, color.a }, SDL_FPoint{ 0 }, },
        { SDL_FPoint{ 829, 214 }, SDL_Color{ color.r, color.g, color.b, color.a }, SDL_FPoint{ 0 }, },
    };
    SDL_RenderGeometry( renderer, nullptr, AluToMemoryData.data(), AluToMemoryData.size(), nullptr, 0 );
    return;
}

void draw_line_alu_to_main_memory_address(SDL_Renderer* renderer, SDL_Color color)
{
    // Alu to memory address
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderDrawLine(renderer,765,357,783,357);
    SDL_RenderDrawLine(renderer,765,358,783,358);
    SDL_RenderDrawLine(renderer,765,359,783,359);

    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderDrawLine(renderer,782,359,782,225);
    SDL_RenderDrawLine(renderer,783,359,783,225);
    SDL_RenderDrawLine(renderer,784,359,784,225);

    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderDrawLine(renderer,783,226,841,226);
    SDL_RenderDrawLine(renderer,783,227,841,227);
    SDL_RenderDrawLine(renderer,783,228,841,228);

    const std::vector< SDL_Vertex > aluToMemoryAddress =
    {
        { SDL_FPoint{ 827, 217 }, SDL_Color{ color.r, color.g, color.b, color.a }, SDL_FPoint{ 0 }, },
        { SDL_FPoint{ 843, 225 }, SDL_Color{ color.r, color.g, color.b, color.a }, SDL_FPoint{ 0 }, },
        { SDL_FPoint{ 830, 236 }, SDL_Color{ color.r, color.g, color.b, color.a }, SDL_FPoint{ 0 }, },
    };
    SDL_RenderGeometry( renderer, nullptr, aluToMemoryAddress.data(), aluToMemoryAddress.size(), nullptr, 0 );
    return;
}

void draw_line_alu_to_mux_to_pc_1(SDL_Renderer* renderer, SDL_Color color)
{
    // alu to decodeMux Data
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderDrawLine(renderer,768,422,817,422);
    SDL_RenderDrawLine(renderer,768,423,817,423);
    SDL_RenderDrawLine(renderer,768,424,817,424);
}

void draw_line_alu_to_mux_to_pc_2(SDL_Renderer* renderer, SDL_Color color)
{
    // alu to decodeMux Data
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderDrawLine(renderer,817,422,1020,422);
    SDL_RenderDrawLine(renderer,817,423,1020,423);
    SDL_RenderDrawLine(renderer,817,424,1020,424);
}

void draw_line_alu_to_mux_to_pc_3(SDL_Renderer* renderer, SDL_Color color)
{
    // alu to decodeMux Data
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderDrawLine(renderer,1020,422,1098,422);
    SDL_RenderDrawLine(renderer,1020,423,1098,423);
    SDL_RenderDrawLine(renderer,1020,424,1098,424);

    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderDrawLine(renderer,1098,424,1098,669);
    SDL_RenderDrawLine(renderer,1099,424,1099,669);
    SDL_RenderDrawLine(renderer,1100,424,1100,669);

    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderDrawLine(renderer,486,668,1097,668);
    SDL_RenderDrawLine(renderer,486,669,1097,669);
    SDL_RenderDrawLine(renderer,486,670,1097,670);


    const std::vector< SDL_Vertex > aluToDecodeMuxData =
    {
        { SDL_FPoint{ 502, 662 }, SDL_Color{ color.r, color.g, color.b, color.a }, SDL_FPoint{ 0 }, },
        { SDL_FPoint{ 486, 668 }, SDL_Color{ color.r, color.g, color.b, color.a }, SDL_FPoint{ 0 }, },
        { SDL_FPoint{ 502, 676 }, SDL_Color{ color.r, color.g, color.b, color.a }, SDL_FPoint{ 0 }, },
    };
    SDL_RenderGeometry( renderer, nullptr, aluToDecodeMuxData.data(), aluToDecodeMuxData.size(), nullptr, 0 );
}

void draw_line_main_memory_to_mux_to_pc(SDL_Renderer* renderer, SDL_Color color)
{
    // memory to decodeMux
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderDrawLine(renderer,995,231,1153,229);
    SDL_RenderDrawLine(renderer,995,232,1153,230);
    SDL_RenderDrawLine(renderer,995,233,1153,231);

    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderDrawLine(renderer,1152,232,1152,689);
    SDL_RenderDrawLine(renderer,1153,232,1153,689);
    SDL_RenderDrawLine(renderer,1154,232,1154,689);

    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderDrawLine(renderer,486,686,1152,686);
    SDL_RenderDrawLine(renderer,486,687,1152,687);
    SDL_RenderDrawLine(renderer,486,688,1152,688);

    const std::vector< SDL_Vertex > memoryToDecodeMux =
    {
        { SDL_FPoint{ 503, 680 }, SDL_Color{ color.r, color.g, color.b, color.a }, SDL_FPoint{ 0 }, },
        { SDL_FPoint{ 486, 687 }, SDL_Color{ color.r, color.g, color.b, color.a }, SDL_FPoint{ 0 }, },
        { SDL_FPoint{ 504, 695 }, SDL_Color{ color.r, color.g, color.b, color.a }, SDL_FPoint{ 0 }, },
    };
    SDL_RenderGeometry( renderer, nullptr, memoryToDecodeMux.data(), memoryToDecodeMux.size(), nullptr, 0 );
}

void draw_line_mux_to_mux(SDL_Renderer* renderer, SDL_Color color)
{




    // Draw line form decodeMux to registerfile
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a); // Black
    SDL_RenderDrawLine(renderer, 386, 669, 386, 566);
    SDL_RenderDrawLine(renderer, 387, 669, 387, 566);
    SDL_RenderDrawLine(renderer, 388, 669, 388, 566);

    const std::vector< SDL_Vertex > decodeToRegisterFileArrow =
    {
        { SDL_FPoint{ 389, 563 }, SDL_Color{ color.r, color.g, color.b, color.a }, SDL_FPoint{ 0 }, },
        { SDL_FPoint{ 380, 575 }, SDL_Color{ color.r, color.g, color.b, color.a }, SDL_FPoint{ 0 }, },
        { SDL_FPoint{ 394, 575 }, SDL_Color{ color.r, color.g, color.b, color.a }, SDL_FPoint{ 0 }, },
    };
    SDL_RenderGeometry( renderer, nullptr, decodeToRegisterFileArrow.data(), decodeToRegisterFileArrow.size(), nullptr, 0 );


        // Draw line form mux decode to Pc mux

    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a); // Black
    SDL_RenderDrawLine(renderer, 99, 329, 99, 666);
    SDL_RenderDrawLine(renderer, 100, 329, 100, 666);
    SDL_RenderDrawLine(renderer, 101, 329, 101, 666);

    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a); // Black
    SDL_RenderDrawLine(renderer, 100, 664, 449, 667);
    SDL_RenderDrawLine(renderer, 100, 665, 449, 668);
    SDL_RenderDrawLine(renderer, 100, 666, 449, 669);

    const std::vector< SDL_Vertex > deocdeMuxArrow =
    {
        { SDL_FPoint{ 101, 326 }, SDL_Color{ color.r, color.g, color.b, color.a }, SDL_FPoint{ 0 }, },
        { SDL_FPoint{ 93, 341 }, SDL_Color{ color.r, color.g, color.b, color.a }, SDL_FPoint{ 0 }, },
        { SDL_FPoint{ 107, 339 }, SDL_Color{ color.r, color.g, color.b, color.a }, SDL_FPoint{ 0 }, },
    };
    SDL_RenderGeometry( renderer, nullptr, deocdeMuxArrow.data(), deocdeMuxArrow.size(), nullptr, 0 );

    return;
}


void draw_line_decoder_to_mux_to_fetch(SDL_Renderer* renderer, SDL_Color color)
{
    // Draw line form decode to Pc mux (Sel)
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a); // Black
    SDL_RenderDrawLine(renderer, 207, 305, 342, 305);
    SDL_RenderDrawLine(renderer, 207, 306, 342, 306);
    SDL_RenderDrawLine(renderer, 207, 307, 342, 307);



    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a); // Black
    SDL_RenderDrawLine(renderer, 341, 305, 341, 355);
    SDL_RenderDrawLine(renderer, 342, 305, 342, 355);
    SDL_RenderDrawLine(renderer, 343, 305, 343, 355);


    const std::vector< SDL_Vertex > decodeToPCMuxSelArrow =
    {
        { SDL_FPoint{ 220, 296 }, SDL_Color{ color.r, color.g, color.b, color.a }, SDL_FPoint{ 0 }, },
        { SDL_FPoint{ 205, 306 }, SDL_Color{ color.r, color.g, color.b, color.a }, SDL_FPoint{ 0 }, },
        { SDL_FPoint{ 220, 317 }, SDL_Color{ color.r, color.g, color.b, color.a }, SDL_FPoint{ 0 }, },
    };
    SDL_RenderGeometry( renderer, nullptr, decodeToPCMuxSelArrow.data(), decodeToPCMuxSelArrow.size(), nullptr, 0 );
}



void draw_line_decoder_to_mux_imm(SDL_Renderer* renderer, SDL_Color color)
{
    // Draw line form decode to Pc mux (Imm)
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a); // Black
    SDL_RenderDrawLine(renderer, 178, 328, 178, 378);
    SDL_RenderDrawLine(renderer, 179, 328, 179, 378);
    SDL_RenderDrawLine(renderer, 180, 328, 180, 378);

    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a); // Black
    SDL_RenderDrawLine(renderer, 179, 377, 316, 377);
    SDL_RenderDrawLine(renderer, 179, 378, 316, 378);
    SDL_RenderDrawLine(renderer, 179, 379, 316, 379);

    const std::vector< SDL_Vertex > decodeToPCMuxImmArrow =
    {
        { SDL_FPoint{ 180, 325 }, SDL_Color{ color.r, color.g, color.b, color.a }, SDL_FPoint{ 0 }, },
        { SDL_FPoint{ 170, 340 }, SDL_Color{ color.r, color.g, color.b, color.a }, SDL_FPoint{ 0 }, },
        { SDL_FPoint{ 190, 340 }, SDL_Color{ color.r, color.g, color.b, color.a }, SDL_FPoint{ 0 }, },
    };
    SDL_RenderGeometry( renderer, nullptr, decodeToPCMuxImmArrow.data(), decodeToPCMuxImmArrow.size(), nullptr, 0 );
}

void draw_line_decoder_to_register_file(SDL_Renderer* renderer, SDL_Color color)
{
    // decode to register file
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderDrawLine(renderer,390,418,390,480);
    SDL_RenderDrawLine(renderer,391,418,391,480);
    SDL_RenderDrawLine(renderer,392,418,392,480);

    const std::vector< SDL_Vertex > decideToRegisterFile =
    {
        { SDL_FPoint{ 381, 468 }, SDL_Color{ color.r, color.g, color.b, color.a }, SDL_FPoint{ 0 }, },

        { SDL_FPoint{ 401, 468 }, SDL_Color{ color.r, color.g, color.b, color.a }, SDL_FPoint{ 0 }, },
        { SDL_FPoint{ 391, 485 }, SDL_Color{ color.r, color.g, color.b, color.a }, SDL_FPoint{ 0 }, },
    };
    SDL_RenderGeometry( renderer, nullptr, decideToRegisterFile.data(), decideToRegisterFile.size(), nullptr, 0 );

}

void draw_line_decoder_to_mux_to_pc(SDL_Renderer* renderer, SDL_Color color)
{
    // Draw line form decode to decodeMux
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a); // Black


    SDL_RenderDrawLine(renderer, 315, 397, 271, 397);
    SDL_RenderDrawLine(renderer, 315, 398, 271, 398);
    SDL_RenderDrawLine(renderer, 315, 399, 271, 399);


    SDL_RenderDrawLine(renderer, 270, 398, 270, 592);
    SDL_RenderDrawLine(renderer, 271, 398, 271, 592);
    SDL_RenderDrawLine(renderer, 272, 398, 272, 592);



    SDL_RenderDrawLine(renderer, 271, 591, 468, 591);
    SDL_RenderDrawLine(renderer, 271, 592, 468, 592);
    SDL_RenderDrawLine(renderer, 271, 593, 468, 593);


    SDL_RenderDrawLine(renderer, 467, 592, 467, 628);
    SDL_RenderDrawLine(renderer, 468, 592, 468, 628);
    SDL_RenderDrawLine(renderer, 469, 592, 469, 628);

    const std::vector< SDL_Vertex > decodeToDecodeMuxArrow =
    {
        { SDL_FPoint{ 460, 625 }, SDL_Color{ color.r, color.g, color.b, color.a }, SDL_FPoint{ 0 }, },
        { SDL_FPoint{ 475, 625 }, SDL_Color{ color.r, color.g, color.b, color.a }, SDL_FPoint{ 0 }, },
        { SDL_FPoint{ 468, 638 }, SDL_Color{ color.r, color.g, color.b, color.a }, SDL_FPoint{ 0 }, },
    };
    SDL_RenderGeometry( renderer, nullptr, decodeToDecodeMuxArrow.data(), decodeToDecodeMuxArrow.size(), nullptr, 0 );
}

