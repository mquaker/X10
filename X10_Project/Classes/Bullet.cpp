#include "stdafx.h"
#include "Bullet.h"
#include "Target.h"
#include "Explosion.h"

bool Bullet::init()
{
	if (!Layer::init())
		return false;
	speed = 1;
	alive = true;
	direction = Vec2(0, 0);
	bullet = Sprite::create("res/bullet.png");
	bullet->setAnchorPoint(Point(0.5, 0.5));
	bullet->setScaleX(0.2);
	bullet->setScaleY(0.2);
	Size windowSize = Director::getInstance()->getVisibleSize();
	bullet->setPosition(Point(windowSize.width / 2, 10));
	//Start(Vec2(0, 1));
	this->addChild(bullet);
	return true;
}

//Vec2's x,y absolute size is less or equal to 1
void Bullet::Move(Vec2 initialDirection)
{
	if (bullet == nullptr)
		return;

	direction = initialDirection;
	MoveBy* action; ///# 지역변수도 초기화 꼭.
	
	if(IsAlive()){ ///# 코딩 컨벤션: 중괄호 이집트 스타일로 할지 고딕 양식으로 할지? 전체적으로 통일되게..

		action = MoveBy::create(duration, direction * speed / 10);
		bullet->runAction(action);
		return;
	}
	bullet->stopAllActions();

}

void Bullet::HitProgress(Target& target)
{
	target.SetEffect(*this);

}


void Bullet::Start(Vec2 direction, float power)
{
	SetSpeed(power);
	Move(direction);
	SetDirection(direction);

}

void Bullet::boom(Scene* scene, Point p) ///# 코딩 컨벤션: 멤버 함수 이름 시작은 대소문자 어느걸로?
{
	if (alive == false || this->isVisible() == false)
		return;
	Explosion::boom(scene, getPosition());
	this->alive = false; ///# alive가 멤버 변수면 굳이 this를 지정할 필요 없다. 그래서 코딩 컨벤션이 중요.
	this->setVisible(false);
}
