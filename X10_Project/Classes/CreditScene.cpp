#include "stdafx.h"
#include "ConstVars.h"
#include "FileStuff.h"
#include "CreditScene.h"
#include "SimpleAudioEngine.h"
#include "MainScene.h"

float CreditScene::ypos = 0.0f;

Scene* CreditScene::createScene()
{
	Scene* scene = Scene::create();

	Layer* layer = CreditScene::create();
	scene->addChild(layer);

	return scene;
}

bool CreditScene::init()
{
	if (!Layer::init())
	{
		return false;
	}
	UserDefault::getInstance()->setBoolForKey("AllCleared", true);
	ypos = 0.0f;

	CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic(FileStuff::SOUND_INITIAL_BACKGROUND, true);
	;

	Sprite* credit = Sprite::create();
	credit->addChild(createSentence(" ", 20));
	credit->addChild(createSentence("Quite Night", 40));
	credit->addChild(createSentence(" ", 15));
	credit->addChild(createSentence("NEXT INSTITUTE", 20));
	credit->addChild(createSentence("GameDevelopment track", 20));
	credit->addChild(createSentence("Experience project", 20));
	
	credit->addChild(createSentence(" ", 15));
	credit->addChild(createSentence("A GAME BY", 20));
	credit->addChild(createSentence("X10", 30));

	credit->addChild(createSentence("MC Kim", 30));
	credit->addChild(createSentence("JW Choi", 30));
	credit->addChild(createSentence("TW Kim", 30));
	credit->addChild(createSentence(" ", 20));

	credit->addChild(createSentence("It's time to have", 15));
	credit->addChild(createSentence("Chickens", 20));
	credit->addChild(createSentence(" ", 20));

	credit->addChild(createSentence("Code Review", 15));
	credit->addChild(createSentence("Prof. SM Koo", 20));
	credit->addChild(createSentence(" ", 20));

	credit->addChild(createSentence("Mentor", 15));
	credit->addChild(createSentence("Prof. SM Koo", 20));
	credit->addChild(createSentence("Prof. HS Seo", 20));
	credit->addChild(createSentence(" ", 20));

	credit->addChild(createSentence("Nojam GAG", 15));
	credit->addChild(createSentence("MC Kim", 20));
	credit->addChild(createSentence(" ", 20));

	credit->addChild(createSentence("Submodule migration", 15));
	credit->addChild(createSentence("HY Nam", 20));
	credit->addChild(createSentence("SB Kim", 20));
	credit->addChild(createSentence(" ", 20));

	credit->addChild(createSentence("cppson library", 15));
	credit->addChild(createSentence("HY Nam", 20));
	credit->addChild(createSentence(" ", 20));

	credit->addChild(createSentence("Game programming", 15));
	credit->addChild(createSentence("TW Kim, MC Kim, JW Choi", 20));
	credit->addChild(createSentence("Art work", 15));
	credit->addChild(createSentence("MC Kim, TW Kim, JW Choi", 20));
	credit->addChild(createSentence("Map design", 15));
	credit->addChild(createSentence("JW Choi, MC Kim, TW Kim", 20));
	credit->addChild(createSentence("Game balancing", 15));
	credit->addChild(createSentence("JW Choi, TW Kim, MC Kim", 20));
	credit->addChild(createSentence("Sound effect", 15));
	credit->addChild(createSentence("TW Kim, MC Kim, JW Choi", 20));
	credit->addChild(createSentence("www.freesfx.co.uk", 20));

	credit->addChild(createSentence(" ", 20));
	credit->addChild(createSentence("Special Thanks to", 20));
	credit->addChild(createSentence("Prof. EJ(Silver bell) Park,", 15));
	credit->addChild(createSentence("Gagyungpu team, ", 15));
	credit->addChild(createSentence("DS Lee, JS Kim, YK Kim, YS Kim, MH Kim, ", 15)); 
	credit->addChild(createSentence("Alchon, MS Chicken, DamSo Sundae,", 15));
	credit->addChild(createSentence("BurgerKing, KKu muk pig", 15));
	credit->addChild(createSentence("Visual Studio & Assist, Pain.NET,", 15));
	credit->addChild(createSentence("Texture packer, Gold Wave,", 15));
	credit->addChild(createSentence("Goolge", 15));
	credit->addChild(createSentence(" ", 20));

	credit->addChild(createSentence("Special Damn to", 15));
	credit->addChild(createSentence("Git", 20));

	credit->addChild(createSentence(" ", 20));
	credit->addChild(createSentence("Thank you for playing.", 30));
	credit->addChild(createSentence("X10 - Quiet Night", 30));
	credit->addChild(createSentence("NEXT INSTITUTE", 30));

	addChild(credit);
	Size size = Director::getInstance()->getVisibleSize();
	credit->setPosition(size.width / 2, 100);

	MoveBy* moveUp = MoveBy::create(2.0, Vec2(0, 60));
	RepeatForever* action = RepeatForever::create(moveUp);
	credit->runAction(action);

	float endTime = 80.0f;
	Sequence* seq = Sequence::create(
		DelayTime::create(endTime),
		CallFunc::create(CC_CALLBACK_0(CreditScene::EndScene, this)),
		nullptr
		);

	runAction(seq);
	return true;
}

void CreditScene::EndScene()
{
	Director::getInstance()->replaceScene(MainScene::createScene());
	return;
}

Node* CreditScene::createSentence(string str, float fontSize)
{
	ypos -= fontSize * 1.2;
	Node* result = Label::create(str, "arial", fontSize);
	result->setPosition(0, ypos);
	ypos -= fontSize * 0.5;
	return result;
}