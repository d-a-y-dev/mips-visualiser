# 5-Stage pipeline visualiser
source code could be found [here](https://github.com/d-a-y-dev/mips-visualiser)

demo [here](https://d-a-y-dev.github.io/mips-visualiser/)
## Caveats
- Not all instructions are supported yet (Wrong visualisation)
    - Branching
    - Load/Store
- Does not have data forwarding lines yet

## Instructions
Clicking "run" (without anything in the box) will run the default instructions, then you could see the dataflow for each instructions.
![image](https://github.com/d-a-y-dev/d-a-y-dev.github.io/assets/88727759/35fbd437-84cc-4a74-bdac-dc0cdb0bbca8)

Dataforwarding could be enabled/disabled via the "Data Forward" checkbox, (after that click 'run', you need to rerun the sim)
![image](https://github.com/d-a-y-dev/d-a-y-dev.github.io/assets/88727759/6e05af46-5219-4686-a211-7e644ac1b9de)

Click on the arrows to move forward/backward 1 cycle                
![image](https://github.com/d-a-y-dev/d-a-y-dev.github.io/assets/88727759/9f3a9c84-96ee-445c-bb3a-26a19eedd9c5)

To put in your own instructions, compiled the instructions then put in the hex'd instruction into the box (as a single line) then click 'run'.           
![image](https://github.com/d-a-y-dev/d-a-y-dev.github.io/assets/88727759/52a6c175-a150-44b3-8e05-6e84b31bf840)

## How to Build locally

- On Windows with Visual Studio's CLI

```
set SDL2_DIR=path_to_your_sdl2_folder
cl /Zi /MD /utf-8 /I.. /I..\.. /I%SDL2_DIR%\include main.cpp ..\..\backends\imgui_impl_sdl2.cpp ..\..\backends\imgui_impl_sdlrenderer2.cpp ..\..\imgui*.cpp /FeDebug/example_sdl2_sdlrenderer.exe /FoDebug/ /link /libpath:%SDL2_DIR%\lib\x86 SDL2.lib SDL2main.lib /subsystem:console
#                 ^^ include paths                  ^^ source files                                                                                         ^^ output exe                         ^^ output dir  ^^ libraries
# or for 64-bit:
cl /Zi /MD /utf-8 /I.. /I..\.. /I%SDL2_DIR%\include main.cpp ..\..\backends\imgui_impl_sdl2.cpp ..\..\backends\imgui_impl_sdlrenderer2.cpp ..\..\imgui*.cpp /FeDebug/example_sdl2_sdlrenderer.exe /FoDebug/ /link /libpath:%SDL2_DIR%\lib\x64 SDL2.lib SDL2main.lib /subsystem:console
```

- On Linux and similar Unixes

```
c++ `sdl2-config --cflags` -I .. -I ../.. main.cpp ../../backends/imgui_impl_sdl2.cpp ../../backends/imgui_impl_sdlrenderer2.cpp ../../imgui*.cpp `sdl2-config --libs` -lGL
```

- On Mac OS X

```
brew install sdl2
c++ `sdl2-config --cflags` -I .. -I ../.. main.cpp ../../backends/imgui_impl_sdl2.cpp ../../backends/imgui_impl_sdlrenderer2.cpp ../../imgui*.cpp `sdl2-config --libs` -framework OpenGl
```
