#pragma once

class Collider;
class Bullet;

class ColliderManager
{
public:
	static ColliderManager* GetInstance();
	void Init();
	Bullet* GetBulletToShot();
	Vector<Collider*>& GetColliders(){ return colliders; } ///# 내부 컬랙션을 통째로 밖으로 보여준다는 소리는 colliders가 private일 이유가 없지 않은가? 반-객체지향적인데..
	/// 차라리 충돌 처리는 ColliderMananger에서 하던가...

	void AddExplosion(Collider* explosion);
	bool HasBullet();
	void Reset();
	void EraseCollider(Collider* collider);

private:
	void InitColliders(); // called in Init()
	static ColliderManager* instance;
	Vector<Collider*> colliders;
	int curBulletIndex;
	int defaultBulletNum;
	ColliderManager();
	~ColliderManager();
};