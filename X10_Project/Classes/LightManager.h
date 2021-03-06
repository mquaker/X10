#pragma once

#include "cocos2d/cocos/math/Vec2.h"

class LightManager
{
public:
	LightManager();
	Sprite* GetLight(int stageNum);
	Vec2 GetPosition(int stageNum);

private:
	void SetLights();
	void InitPositions();
	Sprite* MakeLight(const string& fileDir, int idx);
	Vector<Sprite*> m_lights;
	vector<Vec2> m_positions;
};