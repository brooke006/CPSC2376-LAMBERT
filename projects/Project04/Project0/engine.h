#pragma once
#pragma once
#include <SDL.h>
#include <SDL_ttf.h>
#include <string>

class Engine {
public:
    Engine(const std::string& title = "Game Window", int width = 600, int height = 600);
    ~Engine();

    void clear();
    void present();
    void drawRect(int x, int y, int w, int h, Uint8 r, Uint8 g, Uint8 b, Uint8 a = 255);
    void drawText(const std::string& text, int x, int y, Uint8 r = 255, Uint8 g = 255, Uint8 b = 255);

    SDL_Renderer* getRenderer() { return renderer; }

private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    TTF_Font* font;
};