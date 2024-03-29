#include <iostream>
#include <SDL.h>
#include "window.h"
#include <SDL_image.h>
#include "Rect.h"
#include <ctime>
#include <string>
#include "Text.h"

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

int main(int argc, char* argv[])
{
    srand(time(NULL));

    int score = 0;
    int highScore = 0;

    bool is_play = false;
    Window window("window", 800, 600);

    Rect menu(800, 600, 0, 0, "asset/menu.png");
        Rect player(70, 45, 100, 508, "asset/cat.png");
        Rect stone(50, 50, 100, 0, "asset/stone.png");
        Rect stone1(50, 50, 300, 0, "asset/stone.png");
        Rect stone2(50, 50, 600, 0, "asset/stone.png");
        Rect stone3(50, 50, 250, 0, "asset/stone.png");
        Rect stone4(50, 50, 700, 0, "asset/stone.png");
        Rect stone5(50, 50, 450, 0, "asset/stone.png");
        Rect gameover(800, 600, 0, 0, "asset/gameover.png");

        while(!window.isClosed()){

                pollMenuEvents(window, menu, is_play);
                menu.draw();
                window.clear();
                if(is_play == true ){
                    break;
                }
        }

        if(is_play == false) return 0;

        while(!window.isClosed() && is_play == true)
        {
            pollEvents(window, player);
            player.draw();

            stone.draw();
            stone.update(score);

            stone1.draw();
            stone1.update(score);

            stone2.draw();
            stone2.update(score);

            stone3.draw();
            stone3.update(score);

            stone4.draw();
            stone4.update(score);

            stone5.draw();
            stone5.update(score);
            window.clear();
            if(player.check_collision(stone)) {

                gameover.draw();
                is_play = false;

            }
            if(player.check_collision(stone1)) {

                gameover.draw();
                is_play = false;

            }
            if(player.check_collision(stone2)) {

                gameover.draw();
                is_play = false;

            }
            if(player.check_collision(stone3)) {

                gameover.draw();
                is_play = false;

            }
            if(player.check_collision(stone4)) {

                gameover.draw();
                is_play = false;

            }
            if(player.check_collision(stone5)) {

                gameover.draw();
                is_play = false;

            }
        }

    while(true)
    {
        Rect menu(800, 600, 0, 0, "asset/menu.png");
        Rect player(70, 45, 100, 508, "asset/cat.png");
        Rect stone(50, 50, 100, 0, "asset/stone.png");
        Rect stone1(50, 50, 300, 0, "asset/stone.png");
        Rect stone2(50, 50, 600, 0, "asset/stone.png");
        Rect stone3(50, 50, 250, 0, "asset/stone.png");
        Rect stone4(50, 50, 700, 0, "asset/stone.png");
        Rect stone5(50, 50, 450, 0, "asset/stone.png");
        Rect gameover(800, 600, 0, 0, "asset/gameover.png");

        Text scoreText(Window::renderer, "asset/VNARIALH.ttf", 38, "Your score is: " + to_string(score), {255, 0, 0, 255});
        if(score > highScore) highScore = score;
        Text highScoreText(Window::renderer, "asset/VNARIALH.ttf", 38, "Highest score: " + to_string(highScore), {255, 0, 0, 255});
        score = 0;
        while(!window.isClosed()){

                pollMenuEvents(window, gameover, is_play);
                gameover.draw();
                scoreText.display(200, 205, Window::renderer);
                highScoreText.display(200, 50, Window::renderer);
                window.clear();
                if(is_play == true ){
                    break;
                }
        }

        if(is_play == false) break;

        while(!window.isClosed() && is_play == true)
        {
            pollEvents(window, player);
            player.draw();

            stone.draw();
            stone.update(score);

            stone1.draw();
            stone1.update(score);

            stone2.draw();
            stone2.update(score);

            stone3.draw();
            stone3.update(score);

            stone4.draw();
            stone4.update(score);

            stone5.draw();
            stone5.update(score);
            window.clear();
            if(player.check_collision(stone)) {

                gameover.draw();
                is_play = false;

            }
            if(player.check_collision(stone1)) {

                gameover.draw();
                is_play = false;

            }
            if(player.check_collision(stone2)) {

                gameover.draw();
                is_play = false;

            }
            if(player.check_collision(stone3)) {

                gameover.draw();
                is_play = false;

            }
            if(player.check_collision(stone4)) {

                gameover.draw();
                is_play = false;

            }
            if(player.check_collision(stone5)) {

                gameover.draw();
                is_play = false;

            }
        }
    }

    return 0;
}
