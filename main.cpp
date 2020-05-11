#include <iostream>
#include <SDL.h>
#include "window.h"
#include <SDL_image.h>
#include "Rect.h"
#include <ctime>

using namespace std;

void pollEvents(Window &window, Rect &rect)
{
    SDL_Event event;
    if(SDL_PollEvent(&event))
    {
        rect.pollEventsCharacter(event);
        window.pollEvents(event);
    }
}
void pollMenuEvents(Window &window, Rect &rect, bool &is_play)
{
    SDL_Event event;
    if(SDL_PollEvent(&event))
    {
        rect.menuEvents(event, is_play);
        window.pollEvents(event);
    }
}

void playThisGame(Window window, bool &is_play){


}

int main(int argc, char* argv[])
{
    srand(time(NULL));

    bool is_play = false;
    Window window("window", 800, 600);

    Rect menu(800, 600, 0, 0, "asset/menu.png");
    Rect player(61, 137, 100, 425, "asset/stickman.png");
    Rect stone(50, 50, 100, 0, "asset/stone.png");
    Rect stone1(50, 50, 300, 0, "asset/stone.png");
    Rect stone2(50, 50, 600, 0, "asset/stone.png");
    Rect stone3(50, 50, 250, 0, "asset/stone.png");
    Rect stone4(50, 50, 700, 0, "asset/stone.png");
    Rect stone5(50, 50, 450, 0, "asset/stone.png");
    Rect explosion(150, 150, 600, 0, "asset/explosion.png");
    Rect gameover(800, 600, 0, 0, "asset/playAgain.png");

    while(!window.isClosed() && is_play == false){
            pollMenuEvents(window, menu, is_play);
            if(is_play == true ) cout << "play";
            menu.draw();
            window.clear();
    }

    while(!window.isClosed())
    {
        pollEvents(window, player);
        player.draw();

        stone.draw();
        stone.update();

        stone1.draw();
        stone1.update();

        stone2.draw();
        stone2.update();

        stone3.draw();
        stone3.update();

        stone4.draw();
        stone4.update();

        stone5.draw();
        stone5.update();
        window.clear();
        if(player.check_collision(stone)) {
            explosion.explode(stone);
            explosion.draw();
            SDL_Delay(200);
            gameover.draw();
            stone.isFalling = false;
            stone1.isFalling = false;
            stone2.isFalling = false;
            stone3.isFalling = false;
            stone4.isFalling = false;
            stone5.isFalling = false;

            is_play = false;

        }
        if(player.check_collision(stone1)) {
            explosion.explode(stone1);
            explosion.draw();
            SDL_Delay(200);
            gameover.draw();
            stone.isFalling = false;
            stone1.isFalling = false;
            stone2.isFalling = false;
            stone3.isFalling = false;
            stone4.isFalling = false;
            stone5.isFalling = false;

            is_play = false;

        }
        if(player.check_collision(stone2)) {
            explosion.explode(stone2);
            explosion.draw();
            SDL_Delay(200);
            gameover.draw();
            stone.isFalling = false;
            stone1.isFalling = false;
            stone2.isFalling = false;
            stone3.isFalling = false;
            stone4.isFalling = false;
            stone5.isFalling = false;

            is_play = false;

        }
        if(player.check_collision(stone3)) {
            explosion.explode(stone3);
            explosion.draw();
            SDL_Delay(200);
            gameover.draw();
            stone.isFalling = false;
            stone1.isFalling = false;
            stone2.isFalling = false;
            stone3.isFalling = false;
            stone4.isFalling = false;
            stone5.isFalling = false;

            is_play = false;

        }
        if(player.check_collision(stone4)) {
            explosion.explode(stone4);
            explosion.draw();
            SDL_Delay(200);
            gameover.draw();
            stone.isFalling = false;
            stone1.isFalling = false;
            stone2.isFalling = false;
            stone3.isFalling = false;
            stone4.isFalling = false;
            stone5.isFalling = false;

            is_play = false;

        }
        if(player.check_collision(stone5)) {
            explosion.explode(stone5);
            explosion.draw();
            SDL_Delay(200);
            gameover.draw();
            stone.isFalling = false;
            stone1.isFalling = false;
            stone2.isFalling = false;
            stone3.isFalling = false;
            stone4.isFalling = false;
            stone5.isFalling = false;

            is_play = false;

        }

    }

    return 0;
}
