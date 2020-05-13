#include "Rect.h"
#include <SDL_image.h>
#include <iostream>
#include <ctime>

using namespace std;

SDL_Renderer *Window::renderer = nullptr;

Rect::Rect(int w, int h, int x, int y, int r, int g, int b, int a):
_w(w), _h(h), _x(x), _y(y), _r(r), _g(g), _b(b), _a(a)
{

}
Rect::Rect(int w, int h, int x, int y, const string &image_path):
_w(w), _h(h), _x(x), _y(y)
{
    SDL_Surface* surface = IMG_Load(image_path.c_str());

    if(!surface)
    {
        cout << "Failed to create surface\n";
    }
    player_texture = SDL_CreateTextureFromSurface(Window::renderer, surface);
    if(!player_texture)
    {
        cout << "Failed to create texture.\n";
    }
    SDL_FreeSurface(surface);
}
Rect::~Rect()
{
    SDL_DestroyTexture(player_texture);
};
void Rect::draw() const
{
    SDL_Rect rect = {_x, _y, _w, _h};
    if(player_texture)
    {
        SDL_RenderCopy(Window::renderer, player_texture, nullptr, &rect);
    }
    else
    {
    SDL_SetRenderDrawColor(Window::renderer, _r, _g, _b, _a);
    SDL_RenderFillRect(Window::renderer, &rect);
    }
}
void Rect::pollEventsCharacter(SDL_Event &event)
{
    if(event.type=SDL_KEYDOWN)
    {
        switch(event.key.keysym.sym)
        {
            case SDLK_LEFT:
                _x-=20;
                break;
            case SDLK_RIGHT:
                _x+=20;
                break;
            default:
                break;
        }
    }
}
void Rect::update()
{

    if(isFalling)
    {
    if(vel < 5) vel = 5;
    _y+=vel;
    SDL_Delay(3);
    if(_y >= 600)
    {

        _y = 0;
        _x = rand() % 800;
    }
    if(_x>=800) _x -= 800;
    }
}

bool Rect::check_collision(const Rect & B)
{
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;

    leftA = _x;
    rightA = _x + _w;
    topA = _y;
    bottomA = _y + _h;

    leftB = B._x;
    rightB = B._x + B._w;
    topB = B._y;
    bottomB = B._y + B._h;

    if( bottomA <= topB ){return false;}
    if( topA >= bottomB ){return false;}
    if( rightA <= leftB ){return false;}
    if( leftA >= rightB ){return false;}
    return true;
}

void Rect::explode(const Rect & B)
{
    _x = B._x + B._w - _w;
    _y = B._y + B._h - _h;
}

void Rect::menuEvents(SDL_Event &event, bool &is_play)
{
    if(event.type=SDL_KEYDOWN)
    {
        switch(event.key.keysym.sym)
        {
            case SDLK_SPACE:
                is_play = true;
                break;
            case SDLK_ESCAPE:
                is_play = false;
                break;
            default:
                break;
        }
    }
}

