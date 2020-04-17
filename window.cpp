#include "window.h"
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

using namespace std;

Window::Window(const string& title, int width, int height):
    _title(title), _width(width), _height(height)
{
    if(!init()){
        _closed = true;
    }
    //_closed = !init();
}

Window::~Window()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(_window);
    IMG_Quit();
    SDL_Quit();
}

bool Window::init()
{
    if(SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        cout << "Failed to initialize SDL \n";
        return false;
    }
    if(SDL_Init(IMG_INIT_PNG) != 0)
    {
        cout << "Failed to initialize SDL image.\n";
    }
    _window = SDL_CreateWindow(_title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _width, _height, 0);

    if(_window == nullptr){
        cout << "Failed to create window. \n";
        return false;
    }

    renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);
    if(renderer == nullptr){
        cout << "Failed to create renderer. \n";
        return false;
    }
    img = IMG_LoadTexture(renderer, "asset/background.png");
    //background = IMG_Load("green.png");


    return true;
}
void Window::pollEvents(SDL_Event &event)
{
    switch(event.type)
        {
        case SDL_QUIT:
            _closed = true;
            break;
        case SDL_KEYDOWN:
            switch(event.key.keysym.sym)
            {
                case SDLK_ESCAPE:
                    _closed = true;
                    break;
                default:
                    break;
            }
        default:
            break;
        }
}
void Window::clear() const{
    SDL_RenderPresent(renderer);
    //SDL_SetRenderDrawColor(_renderer, 0, 0, 255, 1);
    SDL_RenderClear(renderer);
    SDL_Rect txr;
        txr.x=0;
        txr.y=0;
        txr.w=800;
        txr.h=600;
    SDL_RenderCopy(renderer, img, NULL, &txr);

}

