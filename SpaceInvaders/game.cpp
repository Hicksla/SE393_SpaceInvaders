#include "game.h"
#include <iostream>

Game::Game()
{
    Init();
}

void Game::Init()
{
    player = Player(400, 500);

    for (int i=0; i < 4; i++)
    {
        for (int j=0; j < 13; j++)
        {
            if (i == 0){
                if (j==0)
                enemies1[j] = QRect(55, 40, 20, 20);
                else
                {
                    enemies1[j] = QRect(enemies1[j-1].x() + 55, 40, 20, 20);
                }
            }
        }
    }


}

void Game::Update()
{
    CheckCollisions();
    player.Update();

    for (int i=0; i< bullets.size(); i++)
    {
        bullets[i].Update();
    }
}

void Game::CheckCollisions()
{
    for (int i=0; i<bullets.size(); i++)
    {
        if (bullets[i].y <= 0)
        {
            bullets.erase(bullets.begin() + i);
        }
    }
}

void Game::Draw(QPainter *p)
{

    p->drawRect(player.rect);

    p->drawRects(enemies1, 13);

    for (int i=0; i< bullets.size(); i++)
    {
        p->drawEllipse(bullets[i].circle);
    }
}

void Game::KeyBoardInput(QKeyEvent *event)
{
    switch(event->key()) {
    case Qt::Key_Escape:
        break;
    case Qt::Key_W:
        break;
    case Qt::Key_A:
        break;
    case Qt::Key_S:
        break;
    case Qt::Key_D:
        break;
    case Qt::Key_Up:
        player.y -= 5;
        break;
    case Qt::Key_Down:
        player.y += 5;
        break;
    case Qt::Key_Left:
        player.x -= 5;
        break;
    case Qt::Key_Right:
        player.x += 5;
        break;
    case Qt::Key_Space:
        bullets.push_back(Bullet(player.x + ((player.w/2)-5), player.y));
        break;
    }
}
