#include "Text.h"
#include "window.h"

#include <iostream>

using namespace std;

Text::Text(SDL_Renderer* renderer, const string& fontPath, int fontSize, const string messageText, const SDL_Color& color)
{
    text_texture = loadFont(renderer, fontPath, fontSize, messageText, color);
    SDL_QueryTexture(text_texture, nullptr, nullptr, &textRect.w, &textRect.h);
}

void Text::display(int x, int y, SDL_Renderer* renderer) const
{
    textRect.x = x;
    textRect.y = y;
    SDL_RenderCopy(renderer, text_texture, nullptr, &textRect);
}

SDL_Texture* Text::loadFont(SDL_Renderer* renderer, const string &fontPath, int fontSize, const string messageText, const SDL_Color &color)
{
    TTF_Font* font = TTF_OpenFont(fontPath.c_str(), fontSize);
    if(!font){
        cout << "Fail to load font \n";
    }
    auto textSurface = TTF_RenderText_Solid(font, messageText.c_str(), color);
    if(!textSurface){
        cout << "Fail to create text surface\n";
    }
    auto textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
    if(!textTexture){
        cout << "Fail to creat text texture\n";
    }
    SDL_FreeSurface(textSurface);
    return textTexture;
};
