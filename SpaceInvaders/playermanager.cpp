#include "playermanager.h"

PlayerManager::PlayerManager()
{
    connect(shootTimer, &QTimer::timeout, this, &PlayerManager::SetPlayerCanShoot);
    shootTimer->setInterval(500);
}

void PlayerManager::LoadPlayer()
{
    player = new Player;
    player->Alive = true;
}

void PlayerManager::SetPlayerCanShoot()
{
    shootTimeOut = true;
}

void PlayerManager::Shoot()
{
    if (shootTimeOut)
    {
       bullets.push_back(Bullet(player->x + ((player->w/2)-5), player->y, 10, 20));
       shootTimeOut = false;
       shootTimer->start();
    }
}
