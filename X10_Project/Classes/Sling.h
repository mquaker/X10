#pragma once

class Sling : public Node
{
public:
	const float FONT_SIZE	= 24;
	const float PREDICT_LINE_TIME = 0.5;

	CREATE_FUNC(Sling);
	bool init();

	/*동작 변화를 위해 호출하는 함수들*/
	void Reset(); // --> 매스테이지마다 리셋. 매개변수는 미정.
	void LoadBullet();
	void ShotComplete();
	bool PullStart(Touch* touch, Event* unused_event);
	void Pull(Touch* touch, Event* unused_event);
	void Shot(Touch* touch, Event* unused_event);
	
	void RemoveDots();
	bool IsShotted();
	Vec2 GetDirection();
	float GetAngleInRadian();
	float GetSpeed();
	float GetRotationAngle();
	
	enum STATUS 
	{ 
		EMPTY, 
		LOADED,
		PULLING,
		SHOTTED 
	};

	enum SLING_CONFIG
	{
		WIDTH = 20,
		HEIGHT = 50,
		YPOS = 50,
		MAX_POWER = 120,
		CLICK_RANGE = 150,
		DOTNUM_OF_LINE = 10
	};
	const Point SLING_POSITION = Point(200, 84);
	const float DEFAULT_ARM = 0.0f;
	const float SLING_SCALE = 1.0f;

private: 
	Sling();

	void ChangeToLoaded();	//empty -> load
	void ChangeToPulling(); //loaded -> pulling
	void ChangeToShotted(); //pullig -> shotted
	void ChangeToEmpty();	//shotted -> empty

	Point GetStartLocation();
	
	Sprite* LoadCharacter();

	int m_status;
	Vec2 m_shotAngle;
	Sprite* m_arm;
	Sprite* m_character;
	float m_shotPower;
	Vector<Sprite*> m_expectLine;
	Vector<Sprite*> m_beforeLine;
};