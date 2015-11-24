#pragma once
#include "Collider.h"
class StageInformation;
class Bullet;
class Sling;

class ColliderManager
{
public:
	ColliderManager() {}
	~ColliderManager() {} ///# 구현이 없으면 선언조차 하지 말 것
	
	void InitBullets(StageInformation* si);
	void ResetBullets();
	Bullet* GetBulletToShot(Sling* sling);
	Vector<Collider*>& GetColliders(){ return m_colliders; }

	bool HasBulletToShot();
	void AddExplosion(Collider* explosion);
	void EraseDeadColliders(); 

private:
	Vector<Collider*> m_colliders;
	int m_curBulletIndex;
	int m_BulletNum;

	friend class GameManager;
};