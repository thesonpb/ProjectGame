#ifndef MEDIA_H
#define MEDIA_H

#include <SDL_mixer.h>
#include <iostream>
using namespace std;

class Media
{
    public:
        Mix_Chunk* sound = NULL;
        Media();
        ~Media();
        bool loadMedia();
        void closeMedia();
};

#endif // MEDIA_H
