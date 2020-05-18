#ifndef RECT_H
#define RECT_H

#include "window.h"
#include <string>

using namespace std;

class Rect
{
    public:
        Rect(int w, int h, int x, int y, const string &image_path);
        ~Rect();
        void draw() const;
        void pollEventsCharacter(SDL_Event &event);
        void update(int &score) ;
        bool check_collision(const Rect& B);
        void menuEvents(SDL_Event &event, bool &is_play);
        bool isFalling = true;
        int vel = rand() % 10 +2;
    private:
        int _w, _h;
        int _x, _y;
        SDL_Texture *player_texture = nullptr;

};

#endif // RECT_H
