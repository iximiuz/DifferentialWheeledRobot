#include "renderer.hpp"

#include <exception>
#include <string>

#include <SDL.h>

static void SDL_OK(int code) {
    if (code != 0) {
        throw std::runtime_error(
                "SDL call failed with code " + std::to_string(code) + ": " 
                + std::string(SDL_GetError()));
    }
}

Texture::Texture(SDL_Renderer *renderer, int width, int height)
    : width_(width), height_(height) {
    sdl_texture_ = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, 
                                     SDL_TEXTUREACCESS_TARGET, width_, height_);
    SDL_OK(sdl_texture_ == nullptr ? -1 : 0);
}

Texture::~Texture() {
    SDL_DestroyTexture(sdl_texture_);
}

Renderer::Renderer(int width, int height) 
    : width_(width), 
      height_(height),
      sdl_window_(nullptr), 
      sdl_renderer_(nullptr) {
    SDL_OK(SDL_Init(SDL_INIT_VIDEO));
    SDL_OK(SDL_CreateWindowAndRenderer(width_, height_, 0, 
                                       &sdl_window_, &sdl_renderer_));
}

Renderer::~Renderer() {
    if (sdl_renderer_ != nullptr) {
        SDL_DestroyRenderer(sdl_renderer_);
    }
    if (sdl_window_ != nullptr) {
        SDL_DestroyWindow(sdl_window_);
    }
    SDL_Quit();
}

void Renderer::Render(PTexture texture) {
    SDL_Rect dest;
    dest.x = width_ / 2;
    dest.y = height_ / 2;
    dest.w = texture->GetWidth();
    dest.h = texture->GetHeight();

    SDL_OK(SDL_RenderCopy(sdl_renderer_, texture->sdl_texture_, NULL, &dest));
    SDL_RenderPresent(sdl_renderer_);
}

PTexture Renderer::CreateRobotTexture() const {
    PTexture texture(new Texture(sdl_renderer_, 10, 10));

    RenderingContext _ctx(sdl_renderer_, texture->sdl_texture_);
    
    SDL_OK(SDL_SetRenderDrawColor(sdl_renderer_, 255, 0, 0, 0));
    SDL_OK(SDL_RenderClear(sdl_renderer_));
    // SDL_RenderDrawRect(renderer, &r);
    // SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0x00);
    // SDL_RenderFillRect(renderer, &r);
    return texture;
}

RenderingContext::RenderingContext(SDL_Renderer *renderer, SDL_Texture *target) 
    : sdl_renderer_(renderer) {
    saved_target_ = SDL_GetRenderTarget(sdl_renderer_);
    SDL_OK(SDL_SetRenderTarget(sdl_renderer_, target));
}

RenderingContext::~RenderingContext() {
    SDL_SetRenderTarget(sdl_renderer_, saved_target_);
}

