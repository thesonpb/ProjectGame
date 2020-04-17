#ifndef RECT_H
#define RECT_H

#include "window.h"
#include <string>

using namespace std;

class Rect
{
    public:
        Rect(int w, int h, int x, int y, int r, int g, int b, int a);
        Rect(int w, int h, int x, int y, const string &image_path);
        ~Rect();
        void draw() const;
        void pollEvents(SDL_Event &event);
        void update(bool isFalling) ;
        bool check_collision(const Rect& B);
        void explode(const Rect &B);
        void menuEvents(bool play);
        bool isFalling = true;
    private:
        int _w, _h;
        int _x, _y;
        int _r, _g, _b, _a;
        SDL_Texture *player_texture = nullptr;

};

#endif // RECT_H
