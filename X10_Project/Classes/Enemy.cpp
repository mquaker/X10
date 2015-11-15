#include "stdafx.h"
#include "Enemy.h"
#include "Bullet.h"

bool Enemy::init()
{
	spr = Sprite::create(FILE_ENEMY);
	addChild(spr);
	//�׽�Ʈ��.
	sprScaleRatio = 0.03f;
	spr->setScale(sprScaleRatio);
	return true;
}


void Enemy::ToBullet(Bullet* bullet)
{
	bullet->Crashed(); 
	bullet->removeFromParent();
}

void Enemy::ToExplosion(Explosion* explosion)
{

}

void Enemy::ToSelf(const Bullet* bullet)
{
	spr->removeFromParent();
	spr = Sprite::create(FILE_ENEMY_DEAD);
	addChild(spr);
	spr->setScale(0.03f);
	this->removeFromParent();
}

void Enemy::ToSelf(const Explosion* explosion)
{
	spr->removeFromParent();
	spr = Sprite::create(FILE_ENEMY_DEAD);
	addChild(spr);
	spr->setScale(0.03f);
	this->removeFromParent();
}
