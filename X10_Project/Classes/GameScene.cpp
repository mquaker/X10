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
	
	m_background = loadBackground();
	addChild(m_background);

	m_character = loadCharacter();
	addChild(m_character, 2.0);

	m_gameLayer = GameLayer::create();
	addChild(m_gameLayer);
	
	m_uiLayer = UILayer::create();
	addChild(m_uiLayer);
	
	m_gameManager = GameManager::GetInstance();

	scheduleUpdate();

	return true;
}

void GameScene::CleanUp()
{
	removeAllChildrenWithCleanup(true);
	removeFromParentAndCleanup(true);
}

Sprite* GameScene::loadBackground()
{
	Sprite* background = Sprite::create(FileStuff::BACKGROUND);
	float scale = (Director::getInstance()->getVisibleSize().width) / (background->getContentSize().width);
	background->setAnchorPoint(Point::ZERO);
	background->setScale(scale);
	background->setOpacity(140);
	return background;
}

Sprite* GameScene::loadCharacter()
{
	Sprite* character = Sprite::createWithSpriteFrameName(FileStuff::CHARACTER_HARDPIXEL);
	character->setPosition(Sling::create()->SLING_POSITION - Point(0, 15));
	return character;
}

void GameScene::update(float dt)
{
	m_gameManager->Play(m_gameLayer, m_uiLayer);
}