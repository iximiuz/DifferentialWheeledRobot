#include <iostream>

#include <SDL.h>

#include "engine/renderer.hpp"
#include "robot.hpp"

int main() {
    std::cout << "Starting... " << std::endl;

    Robot r(20.0, 10.0, 400.0, 300.0, 5.0);

    Renderer engine(800, 600);

    SDL_Event e;
    bool quit = false;
    while (!quit){
        while (SDL_PollEvent(&e)){
            if (e.type == SDL_QUIT){
                quit = true;
            }
            if (e.type == SDL_KEYDOWN){
                quit = true;
            }
            if (e.type == SDL_MOUSEBUTTONDOWN){
                quit = true;
            }
        }
        engine.Render(engine.CreateRobotTexture());
    }
    return 0;
}

