#include "stdafx.h"
#include "Mirror_y.h"
#include "Bullet.h"

bool Mirror_y::init()
{
	if (!Target::init())
	{
		return false;
	}

	m_spr = Sprite::create(FILE_MIRROR);
	addChild(m_spr);

	return true;
}

void Mirror_y::ToBullet(Bullet* bullet)
{
	Vec2 curDir = bullet->GetDirection();
	Vec2 reflect = Vec2(curDir.x , curDir.y * -1);
	bullet->SetDirection(reflect); 
}

void Mirror_y::ToSelf(const Bullet* bullet)
{
	if (m_applyEffectToMe)
	{
		m_applyEffectToMe = false;
	}
}

void Mirror_y::ToSelf(const Explosion* explosion)
{

}