#include "stdafx.h"
#include "Target.h"
#include "Cloud.h"

bool Cloud::init()
{
	return true;
}

const Rect& Cloud::GetBoundingArea()
{
	throw std::logic_error("The method or operation is not implemented.");
}

void Cloud::ToBullet(Bullet* collider)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void Cloud::ToExplosion(Explosion* explosion)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void Cloud::ToSelf(Bullet* bullet)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void Cloud::ToSelf(Explosion* explosion)
{
	throw std::logic_error("The method or operation is not implemented.");
}

