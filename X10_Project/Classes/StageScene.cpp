#include "stdafx.h"
//scene
#include "StageScene.h"
#include "MainScene.h"
#include "GameScene.h"
//layer
#include "UILayer.h"
//info
#include "LightManager.h"
#include "StageInformation.h"
//manager
#include "GameManager.h"
//config
#include "ConstVars.h"
#include "FileStuff.h"
//etc
#include "Sling.h"
#include <SimpleAudioEngine.h>

Scene* StageScene::createScene()
{
	Scene* scene = Scene::create();
	scene->setAnchorPoint(Vec2::ZERO);
	scene->setPosition(Vec2::ZERO);

	Layer* layer = StageScene::create();
	layer->setAnchorPoint(Vec2::ZERO);
	layer->setPosition(Vec2::ZERO);

	scene->addChild(layer);

	return scene;
}

bool StageScene::m_hasCharacterMoved = false;

bool StageScene::init()
{
	if (!LayerColor::initWithColor(Color4B::BLACK))
	{
		return false;
	}

	setName("StageScene");

	m_stageToPlay = UserDefault::getInstance()->getIntegerForKey(ConstVars::LASTSTAGE);
	m_maxStageNum = StageInformation::GetMaxStageNum();

	if (m_stageToPlay == 0)
	{
		scheduleOnce(schedule_selector(StageScene::IntroEvent), 0.0f);
		return true;
	}

	if (m_stageToPlay == 13)
	{
		scheduleOnce(schedule_selector(StageScene::EndingEvent), 0.0f);
		return true;
	}

	Sprite* background = LoadBackground();
	addChild(background);

	m_lightManager = new LightManager();
	SetupLight();

	SetupCharacter();

	return true;
}

void StageScene::SetupCharacter()
{
	Vector<MenuItem*> menuList;

	MenuItemImage* backButton = MakeBackButton();
	menuList.pushBack(backButton);
	
	MenuItemImage* menuItem = MenuItemImage::create();
	menuItem->setNormalImage(
		Sprite::createWithSpriteFrame(
		SpriteFrameCache::getInstance()->getSpriteFrameByName(FileStuff::CHARACTER_STANDING)
		)
	);
	menuItem->setSelectedImage(
		Sprite::createWithSpriteFrame(
		SpriteFrameCache::getInstance()->getSpriteFrameByName(FileStuff::CHARACTER_SELECTED)
		)
	);

	int stepsound = CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("res/sound_effects/footsteps_short.mp3");

	menuItem->setCallback(CC_CALLBACK_0(StageScene::GotoStage, this, m_stageToPlay));

	if (!m_hasCharacterMoved)
	{
		menuItem->setPosition(GetCharacterPosition(m_stageToPlay - 1));
		MoveTo* action = MoveTo::create(1.5f, GetCharacterPosition(m_stageToPlay));
		menuItem->runAction(action);
		m_hasCharacterMoved = true;
	}
	else
	{
		menuItem->setPosition(GetCharacterPosition(m_stageToPlay));
	}
	
	menuList.pushBack(menuItem);
	Menu* menu = Menu::createWithArray(menuList);
	menu->setPosition(Vec2::ZERO);
	addChild(menu);
}

Point StageScene::GetCharacterPosition(int stage)
{
	Size screenSize = Director::getInstance()->getVisibleSize();
	if (stage == 0)
	{
		return Point(screenSize.width / 2 , 0);
	}
	LightManager mng;
	int odd = stage % 2;
	Vec2 lightPos = mng.GetPosition(stage);
	float posRatio = 1.f;
	
	/*
	lightPos와 그 이전과의 lightPos , 가운데 중앙선 이 이루는 사다리 꼴에서
	posRatio비율만큼의 대각선 거리. 짝수 탄에는 거기서 y축으로 절반만큼 간 거리.
	*/

	Vec2 currentDelta = Vec2(-50, -50);
	currentDelta.x *= -(odd);
	currentDelta.x -= 20;

	return lightPos + posRatio * currentDelta;
}

Sprite* StageScene::LoadBackground()
{
	Sprite* background; 
	switch (m_stageToPlay)
	{
	case 1:
		background = Sprite::create(FileStuff::STAGE_BACKGROUND_01);
		break;
	case 2:
		background = Sprite::create(FileStuff::STAGE_BACKGROUND_02);
		break;
	case 3:
		background = Sprite::create(FileStuff::STAGE_BACKGROUND_03);
		break;
	case 4:
		background = Sprite::create(FileStuff::STAGE_BACKGROUND_04);
		break;
	case 5:
		background = Sprite::create(FileStuff::STAGE_BACKGROUND_05);
		break;
	case 6:
		background = Sprite::create(FileStuff::STAGE_BACKGROUND_06);
		break;
	case 7:
		background = Sprite::create(FileStuff::STAGE_BACKGROUND_07);
		break;
	case 8:
		background = Sprite::create(FileStuff::STAGE_BACKGROUND_08);
		break;
	case 9:
		background = Sprite::create(FileStuff::STAGE_BACKGROUND_09);
		break;
	case 10:
		background = Sprite::create(FileStuff::STAGE_BACKGROUND_10);
		break;
	case 11:
		background = Sprite::create(FileStuff::STAGE_BACKGROUND_11);
		break;
	case 12:
		background = Sprite::create(FileStuff::STAGE_BACKGROUND_12);
		break;
	default:
		background = Sprite::create(FileStuff::STAGE_BACKGROUND_12);
		break;
	}

	float scale = (Director::getInstance()->getVisibleSize().width) / (background->getContentSize().width);
	background->setAnchorPoint(Point::ZERO);
	background->setScale(scale);

	return background;
}

void StageScene::SetupLight()
{
	switch (m_stageToPlay)
	{
	case 14:
	case 13:
		addChild(m_lightManager->GetLight(12));
	case 12:
		if (m_stageToPlay <= 14)
		{
			CocosDenshion::SimpleAudioEngine::sharedEngine()->stopBackgroundMusic(true);
			CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic("res/bgmusic/no_way....mp3", true);
		}
		addChild(m_lightManager->GetLight(11));
	case 11:
		addChild(m_lightManager->GetLight(10));
	case 10:
		addChild(m_lightManager->GetLight(9));
	case 9:
		addChild(m_lightManager->GetLight(8));
	case 8:
		addChild(m_lightManager->GetLight(7));
	case 7:
		addChild(m_lightManager->GetLight(6));
	case 6:
		addChild(m_lightManager->GetLight(5));
	case 5:
		if (m_stageToPlay <= 5)
		{
			CocosDenshion::SimpleAudioEngine::sharedEngine()->stopBackgroundMusic(true);
			CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic("res/bgmusic/something's_wrong.mp3", true);
		}
		addChild(m_lightManager->GetLight(4));
	case 4:
		addChild(m_lightManager->GetLight(3));
	case 3:
		addChild(m_lightManager->GetLight(2));
	case 2:
		addChild(m_lightManager->GetLight(1));
	default:
		break;
	}
}

Sprite* StageScene::LoadCharacter()
{
	Sprite* character = Sprite::createWithSpriteFrameName(FileStuff::CHARACTER_STANDING);
	character->setPosition(Sling::create()->SLING_POSITION - Point(0, 15));

	return character;
}

void StageScene::MoveCharacter(Ref* pSender, int stageNum)
{
	MenuItemImage* character = dynamic_cast<MenuItemImage*>(pSender);
	//애니매이션 및 사운드 재생하는 부분
	if (character)
	{
		float timeLength = 2.5f;
		StageScene* tmp = StageScene::create();
		Point finishPos = tmp->GetCharacterPosition(stageNum);
		MoveTo* action = MoveTo::create(timeLength, finishPos);
		character->runAction(action);
	}
}

void StageScene::GotoStage(Ref* pSender, int stageNum)
{
	Scene* scene = GameScene::createScene();
	GameScene* gameScene = static_cast<GameScene*>(scene->getChildByName("GameScene"));

	GameManager::GetInstance()->SetStage(gameScene->GetGameLayer(), gameScene->GetUILayer(), stageNum);
	TransitionFade* sceneWithEffect = TransitionFade::create(1.5f, scene);

	Director::getInstance()->replaceScene(sceneWithEffect);
}

void StageScene::ChangeToMainScene(Ref* pSender)
{
	Director::getInstance()->replaceScene(MainScene::createScene());
}

void StageScene::ChangeToStageScene(Ref* pSender)
{
	Director::getInstance()->replaceScene(StageScene::createScene());
}

void StageScene::IntroEvent(float dt)
{
	//FadeIn Version	
	Vec2 deltaPos = Vec2(0, 45.0f*1.75f);
	Vec2 textPos = Vec2(160.0f, 360.0f);

	PrintIntroText("I got lost in a highway", textPos, 0.0f, 3.0f);
	PrintIntroText("I hate staying in dark", textPos-=deltaPos, 4.5f, 3.0f);
	PrintIntroText("Let's turn on a light and take a step", textPos-=deltaPos, 9.0f, 3.0f);
	PrintIntroText("I can get out of here", textPos -= deltaPos, 14.0f, 3.0f);

	UserDefault::getInstance()->setIntegerForKey(ConstVars::LASTSTAGE, 1);

	CallFuncN* callFuncN = CallFuncN::create(
		CC_CALLBACK_1(StageScene::ChangeToStageScene, this));

	Sequence* seq = Sequence::create(
		DelayTime::create(18.0f),
		callFuncN,
		nullptr);

	runAction(seq);
}

void StageScene::PrintIntroText(const string& message, const Vec2 pos, float startTime, float keepTime)
{
	Label* text = Label::create(
		message, FileStuff::FONT_ARIAL, 12.5f);
	text->setAlignment(TextHAlignment::CENTER);
	text->setScale(1.75f);
	text->setOpacity(0);
	text->setAnchorPoint(Vec2(0.5, 0.5));
	text->setPosition(pos);
	addChild(text);

	Sequence* seq = Sequence::create(
		DelayTime::create(startTime),
		FadeIn::create(keepTime-1.0f),
		NULL);

	text->runAction(seq);
}

void StageScene::EndingEvent(float dt)
{
	//불 켜질 때 확 켜지는 소리
	//하얀 시체 
	//텅 불꺼지는 소리(정신 나감)
	//이후 태우 형꺼 이어붙이기
}

MenuItemImage* StageScene::MakeBackButton()
{
	MenuItemImage* button = MenuItemImage::create(
		FileStuff::PAUSEBUTTON,
		FileStuff::PAUSEBUTTON,
		CC_CALLBACK_1(StageScene::ChangeToMainScene, this));

	Size buttonSize = button->getContentSize();
	float scale = MIN(
		UILayer::PAUSE_BUTTON_WIDTH / buttonSize.width,
		UILayer::PAUSE_BUTTON_HEIGHT / buttonSize.height);
	button->setScale(scale);
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	button->setPosition(
		origin.x + visibleSize.width - buttonSize.width*scale / 2,
		origin.y + buttonSize.height*scale / 2
		);

	return button;
}
