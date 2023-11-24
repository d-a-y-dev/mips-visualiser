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
     // Draw decode mux
    SDL_Rect decodeMuxRect = {450, 648, 35, 40};
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255); // Blue
    SDL_RenderFillRect(renderer, &decodeMuxRect);    
    // Draw mux decode down
     const std::vector< SDL_Vertex > right_mux_decode =
    {
        { SDL_FPoint{ 450, 690 }, SDL_Color{ 0, 255, 0, 255 }, SDL_FPoint{ 0 }, },
        { SDL_FPoint{ 485, 650 }, SDL_Color{ 0, 255, 0, 255 }, SDL_FPoint{ 0 }, },
        { SDL_FPoint{ 485, 710 }, SDL_Color{ 0, 255, 0, 255 }, SDL_FPoint{ 0 }, },
    };
    SDL_RenderGeometry( renderer, nullptr, right_mux_decode.data(), right_mux_decode.size(), nullptr, 0 );


    // Draw line form IR to memory
    // Strat form IR
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Black
    SDL_RenderDrawLine(renderer, 170, 176, 170, 100);
    SDL_RenderDrawLine(renderer, 169, 176, 169, 100);
    SDL_RenderDrawLine(renderer, 168, 176, 168, 100);
    
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Black
    SDL_RenderDrawLine(renderer, 170, 99, 840, 104);
    SDL_RenderDrawLine(renderer, 170, 100, 840, 105);
    SDL_RenderDrawLine(renderer, 170, 101, 840, 106);
   
    
    const std::vector< SDL_Vertex > irArrow =
    {
        { SDL_FPoint{ 825, 98 }, SDL_Color{ 0, 0, 0, 255 }, SDL_FPoint{ 0 }, },
        { SDL_FPoint{ 840, 105 }, SDL_Color{ 0, 0, 0, 255 }, SDL_FPoint{ 0 }, },
        { SDL_FPoint{ 825, 112 }, SDL_Color{ 0, 0, 0, 255 }, SDL_FPoint{ 0 }, },
    };
    SDL_RenderGeometry( renderer, nullptr, irArrow.data(), irArrow.size(), nullptr, 0 );


    // Draw line form Pc mux to IR

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Black
    SDL_RenderDrawLine(renderer, 133, 288, 133, 225);
    SDL_RenderDrawLine(renderer, 132, 288, 132, 225);
    SDL_RenderDrawLine(renderer, 131, 288, 131, 225);

    const std::vector< SDL_Vertex > pcToIRArrow =
    {
        { SDL_FPoint{ 134, 226 }, SDL_Color{ 0, 0, 0, 255 }, SDL_FPoint{ 0 }, },
        { SDL_FPoint{ 124, 239 }, SDL_Color{ 0, 0, 0, 255 }, SDL_FPoint{ 0 }, },
        { SDL_FPoint{ 142, 235 }, SDL_Color{ 0, 0, 0, 255 }, SDL_FPoint{ 0 }, },
    };
    SDL_RenderGeometry( renderer, nullptr, pcToIRArrow.data(), pcToIRArrow.size(), nullptr, 0 );


    // Draw line form Pc+4 to PC mux
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Black
    SDL_RenderDrawLine(renderer, 66, 388, 67, 330);
    SDL_RenderDrawLine(renderer, 65, 388, 66, 330);
    SDL_RenderDrawLine(renderer, 64, 388, 65, 330);

    const std::vector< SDL_Vertex > pcPlus4Arrow =
    {
        { SDL_FPoint{ 65, 327 }, SDL_Color{ 0, 0, 0, 255 }, SDL_FPoint{ 0 }, },
        { SDL_FPoint{ 73, 338 }, SDL_Color{ 0, 0, 0, 255 }, SDL_FPoint{ 0 }, },
        { SDL_FPoint{ 58, 338 }, SDL_Color{ 0, 0, 0, 255 }, SDL_FPoint{ 0 }, },
    };
    SDL_RenderGeometry( renderer, nullptr, pcPlus4Arrow.data(), pcPlus4Arrow.size(), nullptr, 0 );
    


    // Draw line form mux decode to Pc mux

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Black
    SDL_RenderDrawLine(renderer, 99, 329, 99, 666);
    SDL_RenderDrawLine(renderer, 100, 329, 100, 666);
    SDL_RenderDrawLine(renderer, 101, 329, 101, 666);
    
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Black
    SDL_RenderDrawLine(renderer, 100, 664, 449, 667);
    SDL_RenderDrawLine(renderer, 100, 665, 449, 668);
    SDL_RenderDrawLine(renderer, 100, 666, 449, 669);
   
    const std::vector< SDL_Vertex > deocdeMuxArrow =
    {
        { SDL_FPoint{ 101, 326 }, SDL_Color{ 0, 0, 0, 255 }, SDL_FPoint{ 0 }, },
        { SDL_FPoint{ 93, 341 }, SDL_Color{ 0, 0, 0, 255 }, SDL_FPoint{ 0 }, },
        { SDL_FPoint{ 107, 339 }, SDL_Color{ 0, 0, 0, 255 }, SDL_FPoint{ 0 }, },
    };
    SDL_RenderGeometry( renderer, nullptr, deocdeMuxArrow.data(), deocdeMuxArrow.size(), nullptr, 0 );



    // Draw line form registerfile to Pc mux
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Black
    SDL_RenderDrawLine(renderer, 141, 327, 141, 503);
    SDL_RenderDrawLine(renderer, 142, 327, 142, 503);
    SDL_RenderDrawLine(renderer, 143, 327, 143, 503);

    
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Black
    SDL_RenderDrawLine(renderer, 142, 502, 315, 502);
    SDL_RenderDrawLine(renderer, 142, 503, 315, 503);
    SDL_RenderDrawLine(renderer, 142, 504, 315, 504);

    
    const std::vector< SDL_Vertex > registerToPCMuxArrow =
    {
        { SDL_FPoint{ 140, 326 }, SDL_Color{ 0, 0, 0, 255 }, SDL_FPoint{ 0 }, },
        { SDL_FPoint{ 133, 339 }, SDL_Color{ 0, 0, 0, 255 }, SDL_FPoint{ 0 }, },
        { SDL_FPoint{ 149, 339 }, SDL_Color{ 0, 0, 0, 255 }, SDL_FPoint{ 0 }, },
    };
    SDL_RenderGeometry( renderer, nullptr, registerToPCMuxArrow.data(), registerToPCMuxArrow.size(), nullptr, 0 );




    // Draw line form decode to Pc mux (Imm)
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Black
    SDL_RenderDrawLine(renderer, 178, 328, 178, 378);
    SDL_RenderDrawLine(renderer, 179, 328, 179, 378);
    SDL_RenderDrawLine(renderer, 180, 328, 180, 378);
    
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Black
    SDL_RenderDrawLine(renderer, 179, 379, 316, 379);
    SDL_RenderDrawLine(renderer, 179, 380, 316, 380);
    SDL_RenderDrawLine(renderer, 179, 381, 316, 381);

    const std::vector< SDL_Vertex > decodeToPCMuxImmArrow =
    {
        { SDL_FPoint{ 179, 328 }, SDL_Color{ 0, 0, 0, 255 }, SDL_FPoint{ 0 }, },
        { SDL_FPoint{ 170, 340 }, SDL_Color{ 0, 0, 0, 255 }, SDL_FPoint{ 0 }, },
        { SDL_FPoint{ 186, 339 }, SDL_Color{ 0, 0, 0, 255 }, SDL_FPoint{ 0 }, },
    };
    SDL_RenderGeometry( renderer, nullptr, decodeToPCMuxImmArrow.data(), decodeToPCMuxImmArrow.size(), nullptr, 0 );




    // Draw line form decode to Pc mux (Sel)
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Black
    SDL_RenderDrawLine(renderer, 205, 305, 342, 305);
    SDL_RenderDrawLine(renderer, 205, 306, 342, 306);
    SDL_RenderDrawLine(renderer, 205, 307, 342, 307);
   
    
    
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Black
    SDL_RenderDrawLine(renderer, 341, 305, 341, 355);
    SDL_RenderDrawLine(renderer, 342, 305, 342, 355);
    SDL_RenderDrawLine(renderer, 343, 305, 343, 355);
    

    const std::vector< SDL_Vertex > decodeToPCMuxSelArrow =
    {
        { SDL_FPoint{ 221, 300 }, SDL_Color{ 0, 0, 0, 255 }, SDL_FPoint{ 0 }, },
        { SDL_FPoint{ 207, 307 }, SDL_Color{ 0, 0, 0, 255 }, SDL_FPoint{ 0 }, },
        { SDL_FPoint{ 220, 314 }, SDL_Color{ 0, 0, 0, 255 }, SDL_FPoint{ 0 }, },
    };
    SDL_RenderGeometry( renderer, nullptr, decodeToPCMuxSelArrow.data(), decodeToPCMuxSelArrow.size(), nullptr, 0 );




    // Draw line form decodeMux to registerfile
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Black
    SDL_RenderDrawLine(renderer, 386, 669, 386, 566);
    SDL_RenderDrawLine(renderer, 387, 669, 387, 566);
    SDL_RenderDrawLine(renderer, 388, 669, 388, 566);
   
    const std::vector< SDL_Vertex > decodeToRegisterFileArrow =
    {
        { SDL_FPoint{ 389, 563 }, SDL_Color{ 0, 0, 0, 255 }, SDL_FPoint{ 0 }, },
        { SDL_FPoint{ 380, 575 }, SDL_Color{ 0, 0, 0, 255 }, SDL_FPoint{ 0 }, },
        { SDL_FPoint{ 394, 575 }, SDL_Color{ 0, 0, 0, 255 }, SDL_FPoint{ 0 }, },
    };
    SDL_RenderGeometry( renderer, nullptr, decodeToRegisterFileArrow.data(), decodeToRegisterFileArrow.size(), nullptr, 0 );









    // Draw line form decodeMux to registerfile
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Black



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



   
    // const std::vector< SDL_Vertex > decodeToRegisterFileArrow =
    // {
    //     { SDL_FPoint{ 389, 563 }, SDL_Color{ 0, 0, 0, 255 }, SDL_FPoint{ 0 }, },
    //     { SDL_FPoint{ 380, 575 }, SDL_Color{ 0, 0, 0, 255 }, SDL_FPoint{ 0 }, },
    //     { SDL_FPoint{ 394, 575 }, SDL_Color{ 0, 0, 0, 255 }, SDL_FPoint{ 0 }, },
    // };
    // SDL_RenderGeometry( renderer, nullptr, decodeToRegisterFileArrow.data(), decodeToRegisterFileArrow.size(), nullptr, 0 );



    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderDrawLine(renderer,390,186,843,183);
    SDL_RenderDrawLine(renderer,390,187,843,184);
    SDL_RenderDrawLine(renderer,390,188,843,185);

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderDrawLine(renderer,390,184,390,357);
    SDL_RenderDrawLine(renderer,390,185,390,358);
    SDL_RenderDrawLine(renderer,390,186,390,359);








// SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
// SDL_RenderDrawLine(renderer,388,183,843,183);
// SDL_RenderDrawLine(renderer,388,184,843,184);
// SDL_RenderDrawLine(renderer,388,185,843,185);






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
