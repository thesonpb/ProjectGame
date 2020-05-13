#include "Media.h"
#include <iostream>
#include <SDL_mixer.h>

using namespace std;

Media::Media()
{
    sound = Mix_LoadWAV("asset/punch.wav");
}

Media::~Media()
{
}

bool Media::loadMedia()
{
    bool success = true;

    if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
    {
        printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
        success = false;
    }

    //Load sound effects
    if( sound == NULL )
    {
        cout << "Failed to load punch sound effect! SDL_mixer Error: %s\n" << Mix_GetError();
        success = false;
    }
    return success;
}

void Media::closeMedia()
{
    Mix_FreeChunk(sound);
    sound = NULL;
    Mix_Quit();
}
