#include "stdafx.h"
#include "GameScene.h"
#include "GameManager.h"
#include "GameLayer.h"
#include "UILayer.h"
#include "Sling.h"
#include "FileStuff.h"

Scene* GameScene::createScene()
{
	Scene* scene = Scene::create();

	Layer* layer = GameScene::create();
	layer->setName("GameScene");
	scene->addChild(layer);
	
	return scene;
}

bool GameScene::init()
{
	if (Layer::init() == false)
	{
		return false;
	}

	m_gameLayer = GameLayer::create();
	addChild(m_gameLayer);
	
	m_uiLayer = UILayer::create();
	addChild(m_uiLayer, 10);
	
	m_background = LoadBackground();
	addChild(m_background);

	m_gameManager = GameManager::GetInstance();

	scheduleUpdate();

	return true;
}

Sprite* GameScene::LoadBackground()
{
	Sprite* bottom = Sprite::create(FileStuff::BACKGROUND_BOTTOM);
	float scale = (Director::getInstance()->getVisibleSize().width) / (bottom->getContentSize().width);
	bottom->setAnchorPoint(Point::ZERO);
	bottom->setScale(scale);
	return bottom;
}

void GameScene::update(float dt)
{
	m_gameManager->Play();
}