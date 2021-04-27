#include "playermanager.h"

PlayerManager::PlayerManager()
{
    laser2.setSource(QUrl::fromLocalFile(":/laser2/Music/laser2.wav"));
    connect(shootTimer, &QTimer::timeout, this, &PlayerManager::SetPlayerCanShoot);
    shootTimer->setInterval(500);
}

void PlayerManager::LoadPlayer()
{
    player = new Player;
    player->Alive = true;
}
void PlayerManager::LoadPlayers()
{
    player = new Player;
    player->Alive = true;
    altPlayer = new Player;
    altPlayer->Alive = true;
}

void PlayerManager::SetPlayerCanShoot()
{
    shootTimeOut = true;
}

bool PlayerManager::Shoot()
{
    if (shootTimeOut)
    {
       laser2.play();
       bullets.push_back(Bullet(player->x + ((player->w/2)-5), player->y, 10, 20));
       shootTimeOut = false;
       shootTimer->start();
       return true;
    }
    return false;
}
