#include "stdafx.h"
#include "Collider.h"
#include "Explosion.h"
#include "Bullet.h"
#include "Target.h"

//Base class of all Targets

bool Target::init()
{
	setAnchorPoint(Vec2(0, 0));
	spr->setAnchorPoint(Vec2(0, 0));
	return true;
}

void Target::ApplyCollisionEffect(Collider* collider)
{
	if (collider->IsBullet())
	{
		ToBullet(static_cast<Bullet*>(collider));
		ToSelf(static_cast<Bullet*>(collider));
	}
	else
	{
		ToExplosion(static_cast<Explosion*>(collider));
		ToSelf(static_cast<Explosion*>(collider));
	}
}

const Rect& Target::GetBoundingArea() 
{ 
	Point nodePos = getPosition();
	Size sprSize = spr->getContentSize() * sprScaleRatio;
	nodePos.x -= sprSize.width / 2;
	nodePos.y -= sprSize.height / 2;
	return Rect(nodePos, sprSize);
}
