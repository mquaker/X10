#include "stdafx.h"
#include "MainScene.h"
#include "TWScene.h"

Scene* MainScene::createScene()
{
    auto scene = Scene::create();
    
    auto layer = MainScene::create();

    scene->addChild(layer);

    return scene;
}

bool MainScene::init()
{
	if (!Layer::init())
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto closeItem = MenuItemImage::create(
		"CloseNormal.png",
		"CloseSelected.png",
		CC_CALLBACK_1(MainScene::menuCloseCallback, this));

	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width / 2,
		origin.y + closeItem->getContentSize().height / 2));

	auto twScene = MenuItemFont::create("TW_SecretButton", CC_CALLBACK_1(MainScene::GoToTW, this));
	twScene->setScaleX(0.5);
	twScene->setScaleY(0.5);
	twScene->setPosition(Point(200, 10));

	auto menu = Menu::create(closeItem, twScene, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1);
}

void MainScene::GoToTW(Ref* pSender)
{
	Director::getInstance()->replaceScene(TWScene::createScene());
}

void MainScene::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
