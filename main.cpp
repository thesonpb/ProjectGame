#include <iostream>
#include <SDL.h>
#include "window.h"
#include <SDL_image.h>
#include "Rect.h"

using namespace std;

void pollEvents(Window &window, Rect &rect)
{
    SDL_Event event;
    if(SDL_PollEvent(&event))
    {
        rect.pollEvents(event);
        window.pollEvents(event);
    }
}


int main(int argc, char* argv[])
{
    bool play=true;
    Window window("window", 800, 600);
    //Rect menu(800, 600, 0, 0, "asset/menu.png");
    Rect player(61, 137, 100, 425, "asset/stickman.png");
    Rect stone(100, 100, 100, 0, "asset/stone.png");
    Rect stone1(100, 100, 300, 0, "asset/stone.png");
    Rect stone2(100, 100, 600, 0, "asset/stone.png");
    Rect explosion(150, 150, 600, 0, "asset/explosion.png");
    Rect gameover(700, 400, 400-300, 300-150, "asset/gameover.png");

    //menu.draw();
    //menu.menuEvents(play);
    //if(play)

        while(!window.isClosed())
        {
            pollEvents(window, player);
            player.draw();

            stone.draw();
            stone.update(stone.isFalling);

            stone1.draw();
            stone1.update(stone1.isFalling);

            stone2.draw();
            stone2.update(stone2.isFalling);
            window.clear();
            if(player.check_collision(stone)) {
                explosion.explode(stone);
                explosion.draw();
                SDL_Delay(200);
                gameover.draw();
                stone.isFalling = false;
                stone1.isFalling = false;
                stone2.isFalling = false;
                //window._closed = true;
            }
            if(player.check_collision(stone1)) {
                explosion.explode(stone1);
                explosion.draw();
                SDL_Delay(200);
                gameover.draw();
                stone1.isFalling = false;
                stone.isFalling = false;
                stone2.isFalling = false;
                //window._closed = true;
            }
            if(player.check_collision(stone2)) {
                explosion.explode(stone2);
                explosion.draw();
                SDL_Delay(200);
                gameover.draw();
                stone2.isFalling = false;
                stone.isFalling = false;
                stone1.isFalling = false;
                //window._closed = true;
            }
        }
    return 0;
}
