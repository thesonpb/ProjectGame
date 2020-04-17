#ifndef WINDOW_H
#define WINDOW_H

#include <iostream>
#include <SDL.h>
#include <string>
#include <SDL_image.h>

using namespace std;

class Window{
    public:
        Window(const string &title, int width, int height);
        ~Window();
        void pollEvents(SDL_Event &event);
        void clear() const;
        inline bool isClosed()const
        {
            return _closed;
        }

    private:
        bool init();

    private:
        string _title;
        int _width = 800;
        int _height = 600;
        bool _closed = false;

        SDL_Window* _window = nullptr;
        SDL_Surface* background = nullptr;
        SDL_Surface* screen = nullptr;
        SDL_Texture* img = nullptr;
    public:
        static SDL_Renderer* renderer;

};

#endif
