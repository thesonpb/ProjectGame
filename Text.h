#ifndef TEXT_H
#define TEXT_H

#include <SDL_ttf.h>
#include <SDL.h>
#include <string>

using namespace std;

class Text
{
public:
    Text(SDL_Renderer* renderer, const string &fontPath, int fontSize, const string messageText, const SDL_Color &color);
    void display(int x, int y, SDL_Renderer* renderer) const;
    static SDL_Texture * loadFont(SDL_Renderer* renderer, const string &fontPath, int fontSize, const string messageText, const SDL_Color &color);
private:
    SDL_Texture * text_texture = nullptr;
    mutable SDL_Rect textRect; //mutable để có thể thay đổi được, vì trong hàm display có thay giá trị của textrect
};

#endif // TEXT_H
