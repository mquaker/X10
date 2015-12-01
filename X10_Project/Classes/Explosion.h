#pragma once

#include "Collider.h"

class Explosion : public Collider
{
public:
	CREATE_FUNC(Explosion);
	virtual bool init();
	void Act();
	const float& GetBoundingRadius(); ///#왜 참조로 리턴? 
	bool IsBullet() { return false; }

	enum
	{
		DEFAULT_RADIUS = 30
	};

protected:
	Explosion();
	virtual ~Explosion();

	void RemoveSelf();
	ParticleExplosion* m_explosion;
	float m_lifeTime;
	float m_lifeDecrease;
	float m_radius;
	float m_maxRadius;
};