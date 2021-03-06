#ifndef DWR_ENGINE_RENDERER_H
#define DWR_ENGINE_RENDERER_H

#include <memory>

#include <SDL.h>

class Texture {
    friend class Renderer;

private:
    int x_;
    int y_;
    int width_;
    int height_;
    double angle_;
    SDL_Texture *sdl_texture_;

    Texture(SDL_Renderer *sdl_renderer, 
            int x, int y, 
            int width, int height, 
            double angle = 0);

public:
    inline int GetX() const { return x_; }
    inline int GetY() const { return y_; }
    inline int GetWidth() const { return width_; }
    inline int GetHeight() const { return height_; }
    inline double GetAngle() const { return angle_; }

    ~Texture();
};

using PTexture = std::unique_ptr<Texture>;

class Renderer {
private:
    int width_;
    int height_;
    SDL_Window *sdl_window_;
    SDL_Renderer *sdl_renderer_;

public:
    Renderer(int width = 800, int height = 600);
    ~Renderer();

    void Render(PTexture texture);

    PTexture CreateRobotTexture() const;
};

class RenderingContext {
    SDL_Renderer *sdl_renderer_;
    SDL_Texture *saved_target_;

public:
    RenderingContext(SDL_Renderer *renderer, SDL_Texture *target);
    ~RenderingContext();
};

#endif // DWR_ENGINE_RENDERER_H

