#include "stdafx.h"
#include "Target.h"
#include "Bubble.h"

bool Bubble::init()
{
	return true;
}

const Rect& Bubble::GetBoundingArea()
{
	throw std::logic_error("The method or operation is not implemented.");
}

void Bubble::ToBullet(Bullet* collider)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void Bubble::ToExplosion(Explosion* explosion)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void Bubble::ToSelf(Bullet* bullet)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void Bubble::ToSelf(Explosion* explosion)
{
	throw std::logic_error("The method or operation is not implemented.");
}

