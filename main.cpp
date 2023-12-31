// Dear ImGui: standalone example application for SDL2 + SDL_Renderer
// (SDL is a cross-platform general purpose library for handling windows, inputs, OpenGL/Vulkan/Metal graphics context creation, etc.)

// Learn about Dear ImGui:
// - FAQ                  https://dearimgui.com/faq
// - Getting Started      https://dearimgui.com/getting-started
// - Documentation        https://dearimgui.com/docs (same as your local docs/ folder).
// - Introduction, links and more at the top of imgui.cpp

// Important to understand: SDL_Renderer is an _optional_ component of SDL2.
// For a multi-platform app consider using e.g. SDL+DirectX on Windows and SDL+OpenGL on Linux/OSX.

#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#include "emscripten_browser_clipboard.h"
#endif
#include "imgui.h"
#include "imgui_impl_sdl2.h"
#include "imgui_impl_sdlrenderer2.h"
#include "imgui_stdlib.h"
#include "gui/design.h"
#include "shell.hpp"
// #include "pipeline.h"
#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include <chrono>
#include <thread>
#include <iomanip>

#if !SDL_VERSION_ATLEAST(2,0,17)
#error This backend requires SDL 2.0.17+ because of SDL_RenderGeometry() function
#endif

template <typename ... Args>
void log(Args&& ... args)
{
    (std::cout << ... << std::forward<Args>(args));
}

int DESIRED_FPS = 30;

SDL_Window* window = nullptr;
SDL_Renderer* renderer = nullptr;
TTF_Font* font = nullptr;
bool done = false;
bool DATA_FORWARD = false;
int oldMouseX = 0;
int oldMouseY = 0;
int counter = 0;

// Our state
bool show_demo_window = true;
bool show_another_window = false;
ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
ImGuiIO* io = nullptr;

SDL_Surface* background_surface = NULL;
SDL_Texture* background_texture = NULL;

std::chrono::system_clock::time_point a = std::chrono::system_clock::now();
std::chrono::system_clock::time_point b = std::chrono::system_clock::now();

static std::string text{""};
static std::string clipboard_content;
static bool simulatedImguiPaste = false;

#ifdef __EMSCRIPTEN__

char const *get_clipboard_for_imgui(void *user_data [[maybe_unused]]) {
  /// Callback for imgui, to return clipboard content
  std::cout << "ImGui requested clipboard content, returning " << std::quoted(clipboard_content) << std::endl;
  return clipboard_content.c_str();
}

void set_clipboard_from_imgui(void *user_data [[maybe_unused]], char const *text) {
  /// Callback for imgui, to set clipboard content
  clipboard_content = text;
  std::cout << "ImGui setting clipboard content to " << std::quoted(clipboard_content) << std::endl;
  emscripten_browser_clipboard::copy(clipboard_content);
}

#endif

void renderText(const char* text, int x, int y, SDL_Color textColor) {
    SDL_Surface* textSurface = TTF_RenderText_Solid(font, text, textColor);
    SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);

    int textWidth = textSurface->w;
    int textHeight = textSurface->h;

    SDL_Rect renderQuad = {x, y, textWidth, textHeight};

    SDL_RenderCopy(renderer, textTexture, nullptr, &renderQuad);

    SDL_FreeSurface(textSurface);
    SDL_DestroyTexture(textTexture);
}

void handleButtonClick(SDL_Event& e) {
    int mouseX, mouseY;
    SDL_GetMouseState(&mouseX, &mouseY);

    // std::cout << "SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);" << std::endl;
    // log("SDL_RenderDrawLine(renderer,", oldMouseX, ",",oldMouseY, ",", mouseX, ",", mouseY, ");", "\n");
    // log("SDL_RenderDrawLine(renderer,", oldMouseX, ",",oldMouseY+1, ",", mouseX, ",", mouseY+1, ");", "\n");
    // log("SDL_RenderDrawLine(renderer,", oldMouseX, ",",oldMouseY+2, ",", mouseX, ",", mouseY+2, ");", "\n");

    std::cout << "X: " << mouseX << ", Y: " << mouseY << " | diff X: " << oldMouseX - mouseX << ", Y: " << oldMouseY - mouseY << std::endl;

    oldMouseX = mouseX;
    oldMouseY = mouseY;

    // Check if the mouse click is within the button area
    if (mouseX >= 600 && mouseX <= 750 && mouseY >= 500 && mouseY <= 550) {
        // Toggle the button state
        // buttonClicked = !buttonClicked;

        // Render MIPS architecture
        // renderMIPSArchitecture(window, renderer);
    }
}

static void mainloop()
{
    if (done) {
        // Cleanup
        ImGui_ImplSDLRenderer2_Shutdown();
        ImGui_ImplSDL2_Shutdown();
        ImGui::DestroyContext();

        // Destroy the renderer, window, and font
        SDL_DestroyTexture(background_texture);
        SDL_FreeSurface(background_surface);
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        TTF_CloseFont(font);

        // Quit SDL_ttf and SDL
        TTF_Quit();
        SDL_Quit();

        #ifdef __EMSCRIPTEN__
        emscripten_cancel_main_loop();  /* this should "kill" the app. */
        #else
        exit(0);
        #endif
    }

    // Poll and handle events (inputs, window resize, etc.)
    // You can read the io.WantCaptureMouse, io.WantCaptureKeyboard flags to tell if dear imgui wants to use your inputs.
    // - When io.WantCaptureMouse is true, do not dispatch mouse input data to your main application, or clear/overwrite your copy of the mouse data.
    // - When io.WantCaptureKeyboard is true, do not dispatch keyboard input data to your main application, or clear/overwrite your copy of the keyboard data.
    // Generally you may always pass all inputs to dear imgui, and hide them from your application based on those two flags.
    if (simulatedImguiPaste) {
		simulatedImguiPaste = false;
		ImGui::GetIO().AddKeyEvent(ImGuiKey_ModCtrl, false);
		ImGui::GetIO().AddKeyEvent(ImGuiKey_V, false);
	}

    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        ImGui_ImplSDL2_ProcessEvent(&event);
        if (event.type == SDL_QUIT)
            done = true;
        if (event.type == SDL_WINDOWEVENT && event.window.event == SDL_WINDOWEVENT_CLOSE && event.window.windowID == SDL_GetWindowID(window))
            done = true;
        // if (event.type == SDL_MOUSEBUTTONDOWN)
            // handleButtonClick(event);
    }

    int ms = 1000/DESIRED_FPS;

    // Maintain designated frequency of 5 Hz (200 ms per frame)
    a = std::chrono::system_clock::now();
    std::chrono::duration<double, std::milli> work_time = a - b;

    if (work_time.count() < ms)
    {
        std::chrono::duration<double, std::milli> delta_ms(ms - work_time.count());
        auto delta_ms_duration = std::chrono::duration_cast<std::chrono::milliseconds>(delta_ms);
        std::this_thread::sleep_for(std::chrono::milliseconds(delta_ms_duration.count()));
    }

    b = std::chrono::system_clock::now();
    std::chrono::duration<double, std::milli> sleep_time = b - a;


    // Start the Dear ImGui frame
    ImGui_ImplSDLRenderer2_NewFrame();
    ImGui_ImplSDL2_NewFrame();
    ImGui::NewFrame();

    // 1. Show the big demo window (Most of the sample code is in ImGui::ShowDemoWindow()! You can browse its code to learn more about Dear ImGui!).
    // if (show_demo_window)
    //     ImGui::ShowDemoWindow(&show_demo_window);

    // 2. Show a simple window that we create ourselves. We use a Begin/End pair to create a named window.
    {
        static float f = 0.0f;

        ImGui::SetNextWindowSize(ImVec2(0.0f, 0.0f));
        ImGui::Begin("Stats");                          // Create a window called "Hello, world!" and append into it.

        // ImGui::Text("This is some useful text.");               // Display some text (you can use a format strings too)
        // ImGui::Checkbox("Demo Window", &show_demo_window);      // Edit bools storing our window open/close state
        // ImGui::Checkbox("Another Window", &show_another_window);

        // ImGui::SliderFloat("float", &f, 0.0f, 1.0f);            // Edit 1 float using a slider from 0.0f to 1.0f
        // ImGui::ColorEdit3("clear color", (float*)&clear_color); // Edit 3 floats representing a color

        // if (ImGui::Button("Button"))                            // Buttons return true when clicked (most widgets return true when edited/activated)
        //     counter++;
        // ImGui::SameLine();
        // ImGui::Text("counter = %d", counter);

        // Note: we are using a fixed-sized buffer for simplicity here. See ImGuiInputTextFlags_CallbackResize
        // and the code in misc/cpp/imgui_stdlib.h for how to setup InputText() for dynamically resizing strings.
        // static char text[1024 * 16] = "";

        static ImGuiInputTextFlags flags = ImGuiInputTextFlags_AllowTabInput;
        // HelpMarker("You can use the ImGuiInputTextFlags_CallbackResize facility if you need to wire InputTextMultiline() to a dynamic string type. See misc/cpp/imgui_stdlib.h for an example. (This is not demonstrated in imgui_demo.cpp because we don't want to include <string> in here)");
        // ImGui::CheckboxFlags("ImGuiInputTextFlags_ReadOnly", &flags, ImGuiInputTextFlags_ReadOnly);
        // ImGui::CheckboxFlags("ImGuiInputTextFlags_AllowTabInput", &flags, ImGuiInputTextFlags_AllowTabInput);
        // ImGui::CheckboxFlags("ImGuiInputTextFlags_CtrlEnterForNewLine", &flags, ImGuiInputTextFlags_CtrlEnterForNewLine);
        // ImGui::InputTextMultiline("##source", text, IM_ARRAYSIZE(text), ImVec2(-FLT_MIN, ImGui::GetTextLineHeight() * 4), flags);
        ImGui::InputTextMultiline("##source", &text, ImVec2(-FLT_MIN, ImGui::GetTextLineHeight() * 4));

        if (ImGui::Button("Run"))// Buttons return true when clicked (most widgets return true when edited/activated)
        {
            Cycle_Instances.clear();
            counter = 0;
            std::cout << text << std::endl;
            run_shell(text);
        }
        ImGui::SameLine();
        ImGui::Checkbox("Data Forward", &DATA_FORWARD);


        // if(ImGui::Button("Next Cycle"))
        //     //

        ImGui::Text("Total Cycle - %lu", Cycle_Instances.size());

        ImGui::AlignTextToFramePadding();
        // ImGui::Text("Hold to repeat:");
        ImGui::SameLine();

        // Arrow buttons with Repeater
        // IMGUI_DEMO_MARKER("Widgets/Basic/Buttons (Repeating)");
        // int counter = 0;
        float spacing = ImGui::GetStyle().ItemInnerSpacing.x;
        ImGui::PushButtonRepeat(true);
        if (ImGui::ArrowButton("##left", ImGuiDir_Left)) { if (counter > 0) {counter--;} }
        ImGui::SameLine(0.0f, spacing);
        if (ImGui::ArrowButton("##right", ImGuiDir_Right)) { if (counter < Cycle_Instances.size()) {counter++;} }
        ImGui::PopButtonRepeat();
        ImGui::SameLine();
        ImGui::Text("Cycle: %d", counter);

        if(!Cycle_Instances.empty())
        {
            ImGui::Text("PC: %x", Cycle_Instances[counter].CPU_State.PC);

            ImGuiStyle& style = ImGui::GetStyle();
            float child_w = (ImGui::GetContentRegionAvail().x - 4 * style.ItemSpacing.x) / 5;
            for (int i = 0; i < 5; i++)
            {
                if (i > 0) ImGui::SameLine();
                ImGui::BeginGroup();
                const char* names[] = { "Fetch", "Decode", "Execute", "Memory", "Writeback" };
                ImGui::TextUnformatted(names[i]);

                const ImGuiWindowFlags child_flags = 0;
                const ImGuiID child_id = ImGui::GetID((void*)(intptr_t)i);
                const bool child_is_visible = ImGui::BeginChild(child_id, ImVec2(child_w, 200.0f), ImGuiChildFlags_Border, child_flags);
                if (ImGui::BeginMenuBar())
                {
                    ImGui::TextUnformatted("abc");
                    ImGui::EndMenuBar();
                }
                if (child_is_visible) // Avoid calling SetScrollHereY when running with culled items
                {
                    for (int item = 0; item < 32; item++)
                    {
                        ImGui::Text("R%d: %d",item,  Cycle_Instances[i+counter].CPU_State.REGS[item]);
                    }
                }
                float scroll_y = ImGui::GetScrollY();
                float scroll_max_y = ImGui::GetScrollMaxY();
                ImGui::EndChild();
                ImGui::Text("%.0f/%.0f", scroll_y, scroll_max_y);
                ImGui::EndGroup();
            }

            ImGui::Text("IDEX - ALUOp: %d  ALUSrc: %d  Jump: %d  RegWrite: %d  Syscall: %d", Cycle_Instances[counter].IDEX_Reg.ALUOp, Cycle_Instances[counter].IDEX_Reg.ALUSrc, Cycle_Instances[counter].IDEX_Reg.Jump, Cycle_Instances[counter].IDEX_Reg.RegWrite, Cycle_Instances[counter].IDEX_Reg.Syscall);
            ImGui::Text("EXMEM - Jump: %d  RegWrite: %d  Syscall: %d",Cycle_Instances[counter].EXMEM_Reg.Jump, Cycle_Instances[counter].EXMEM_Reg.RegWrite, Cycle_Instances[counter].EXMEM_Reg.Syscall);
            ImGui::Text("MEMWB - Jump: %d  RegWrite: %d  Syscall: %d",Cycle_Instances[counter].MEMWB_Reg.Jump, Cycle_Instances[counter].MEMWB_Reg.RegWrite, Cycle_Instances[counter].MEMWB_Reg.Syscall);
            ImGui::Text("Writeback - Jump: %d  RegWrite: %d  Syscall: %d", Cycle_Instances[counter].WROTE_Reg.Jump, Cycle_Instances[counter].WROTE_Reg.RegWrite, Cycle_Instances[counter].WROTE_Reg.Syscall);
            ImGui::Text("STALL-F: %d  STALL-D: %d", Cycle_Instances[counter].Stall_Unit.Fetch, Cycle_Instances[counter].Stall_Unit.Decode);
        }


        ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / io->Framerate, io->Framerate);

        ImGui::End();
    }

    // 3. Show another simple window.
    if (show_another_window)
    {
        ImGui::Begin("Another Window", &show_another_window);   // Pass a pointer to our bool variable (the window will have a closing button that will clear the bool when clicked)
        ImGui::Text("Hello from another window!");
        if (ImGui::Button("Close Me"))
            show_another_window = false;
        ImGui::End();
    }

    // Rendering
    ImGui::Render();
    SDL_RenderSetScale(renderer, io->DisplayFramebufferScale.x, io->DisplayFramebufferScale.y);
    SDL_SetRenderDrawColor(renderer, (Uint8)(clear_color.x * 255), (Uint8)(clear_color.y * 255), (Uint8)(clear_color.z * 255), (Uint8)(clear_color.w * 255));
    SDL_RenderClear(renderer);

        // Draw a rectangle outside the ImGui window
    // SDL_Rect rect = { 50, 50, 100, 50 }; // x, y, width, height
    // SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // RGBA color format (red)
    // SDL_RenderFillRect(renderer, &rect);
    renderMIPSArchitecture(window, renderer, counter);

    // Get window dimensions
    int screenWidth, screenHeight;
    SDL_GetWindowSize(window, &screenWidth, &screenHeight);

    // SDL_Rect background_dest = {0, 0, screenWidth, screenHeight};
    // SDL_RenderCopy(renderer, background_texture, NULL, &background_dest);


    ImGui_ImplSDLRenderer2_RenderDrawData(ImGui::GetDrawData());
    SDL_RenderPresent(renderer);
}

// Main code
int main(int, char**)
{
    // Setup SDL
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_GAMECONTROLLER) != 0)
    {
        printf("Error: %s\n", SDL_GetError());
        return -1;
    }

    // From 2.0.18: Enable native IME.
#ifdef SDL_HINT_IME_SHOW_UI
    SDL_SetHint(SDL_HINT_IME_SHOW_UI, "1");
#endif

    // Create window with SDL_Renderer graphics context
    SDL_WindowFlags window_flags = (SDL_WindowFlags)(SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI);
    window = SDL_CreateWindow("Dear ImGui SDL2+SDL_Renderer example", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, window_flags);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED);

    background_surface = SDL_LoadBMP("static/rachadta.bmp");
    background_texture = SDL_CreateTextureFromSurface(renderer, background_surface);
    SDL_SetTextureAlphaMod(background_texture, 128); // 128 corresponds to 50% opacity (255 is fully opaque)

     // Initialize SDL_ttf
    if (TTF_Init() == -1) {
        printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
        return 1;
    }

    // Load font
    font = TTF_OpenFont("Roboto-Bold.ttf", 28); // Replace "arial.ttf" with the path to your font file
    if (font == nullptr) {
        printf("Failed to load font! SDL_ttf Error: %s\n", TTF_GetError());
        return 1;
    }

    if (renderer == nullptr)
    {
        SDL_Log("Error creating SDL_Renderer!");
        return 0;
    }
    //SDL_RendererInfo info;
    //SDL_GetRendererInfo(renderer, &info);
    //SDL_Log("Current SDL_Renderer: %s", info.name);

    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    io = &ImGui::GetIO(); (void)io;
    io->ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
    io->ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls

    // Setup Dear ImGui style
    ImGui::StyleColorsDark();
    //ImGui::StyleColorsLight();

    // Setup Platform/Renderer backends
    ImGui_ImplSDL2_InitForSDLRenderer(window, renderer);
    ImGui_ImplSDLRenderer2_Init(renderer);

    // Load Fonts
    // - If no fonts are loaded, dear imgui will use the default font. You can also load multiple fonts and use ImGui::PushFont()/PopFont() to select them.
    // - AddFontFromFileTTF() will return the ImFont* so you can store it if you need to select the font among multiple.
    // - If the file cannot be loaded, the function will return a nullptr. Please handle those errors in your application (e.g. use an assertion, or display an error and quit).
    // - The fonts will be rasterized at a given size (w/ oversampling) and stored into a texture when calling ImFontAtlas::Build()/GetTexDataAsXXXX(), which ImGui_ImplXXXX_NewFrame below will call.
    // - Use '#define IMGUI_ENABLE_FREETYPE' in your imconfig file to use Freetype for higher quality font rendering.
    // - Read 'docs/FONTS.md' for more instructions and details.
    // - Remember that in C/C++ if you want to include a backslash \ in a string literal you need to write a double backslash \\ !
    //io.Fonts->AddFontDefault();
    //io.Fonts->AddFontFromFileTTF("c:\\Windows\\Fonts\\segoeui.ttf", 18.0f);
    //io.Fonts->AddFontFromFileTTF("../../misc/fonts/DroidSans.ttf", 16.0f);
    //io.Fonts->AddFontFromFileTTF("../../misc/fonts/Roboto-Medium.ttf", 16.0f);
    //io.Fonts->AddFontFromFileTTF("../../misc/fonts/Cousine-Regular.ttf", 15.0f);
    //ImFont* font = io.Fonts->AddFontFromFileTTF("c:\\Windows\\Fonts\\ArialUni.ttf", 18.0f, nullptr, io.Fonts->GetGlyphRangesJapanese());
    //IM_ASSERT(font != nullptr);

    #ifdef __EMSCRIPTEN__

    emscripten_browser_clipboard::paste([](std::string const &paste_data, void *callback_data [[maybe_unused]]){
		std::cout << "Copied clipboard data: " << paste_data << std::endl;
		clipboard_content = std::move(paste_data);
		simulatedImguiPaste = true;
	});

    io->GetClipboardTextFn = get_clipboard_for_imgui;
	io->SetClipboardTextFn = set_clipboard_from_imgui;

    #endif

    // Main loop
    #ifdef __EMSCRIPTEN__
    emscripten_set_main_loop(mainloop, 0, 1);
    #else
    while (1) { mainloop(); }
    #endif

    return 0;
}
