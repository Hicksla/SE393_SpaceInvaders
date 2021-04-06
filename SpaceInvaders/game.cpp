#include "game.h"
#include <iostream>

Game::Game()
{
}

void Game::Init()
{
    player = Player(400, 500);
}

void Game::Update()
{
    player.Update();

}

void Game::Draw(QPainter *p)
{

    p->drawRect(player.rect);
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
    }
}
