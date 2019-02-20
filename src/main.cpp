#include <chrono>
#include <iostream>
#include <thread>

#include "engine/renderer.hpp"
#include "robot.hpp"

int main() {
    std::cout << "Starting... " << std::endl;

    Robot r(20.0, 10.0, 400.0, 300.0, 5.0);
    std::cout << sizeof(r) << std::endl;

    Renderer engine;
    engine.Render(engine.CreateRobotTexture());

    std::this_thread::sleep_for(std::chrono::seconds(10));
    return 0;
}

