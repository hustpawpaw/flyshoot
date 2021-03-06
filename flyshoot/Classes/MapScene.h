#ifndef __MAPSCENE_H__
#define __MAPSCENE_H__

#include "cocos2d.h"
#include "GamePlayer.h"
#include "GameBullet.h"
#include "GameEnemy.h"
#include "HRocker.h"
#include "ODSocket.h"

#include "SimpleAudioEngine.h"

#include<iostream>
#include<fstream>
#include<string>
#define ASIO boost::asio
#define BLOCK_SIZE 240
#define ENEMYNUM 10
#define MAX 8
using namespace cocos2d;

class MapScene :public CCLayer
{
	~MapScene(void);
private:
	CCParticleSystem*	m_emitter;
	CCParticleSystem*   m_emitter1;
	CCArray * bullets[10];
	CCArray* avatarBullets[MAX][10];// MAX-> ID [10] - > type;
	CCArray * enemybullets[ENEMYNUM];
	CCSprite *spRocker;//ҡ�� 
	CCSprite *spRockerBG;//ҡ�˱��� 
	HRocker *rocker;//����ҡ�� 
	CCSprite *spRocker1;//ҡ�� 
	CCSprite *spRockerBG1;//ҡ�˱��� 
	CCSprite *serverLite;
	CCSprite *clientLite;
	HRocker *rocker1;//����ҡ��
	bool m_isStop;
	int stepindex;
	int smallstepindex;
	int xdelta;
	int ydelta;
	int startx;
	int starty;
	int playerlife;
	double xstep;
	double ystep;
	CCSprite* maplayer1;
	CCSprite* maplayer2;
	CCSprite* life[LIFENUM+10];
    CCSprite* weapon[4];
	CCSprite* rocket;
	CCSprite* board;
	CCSprite* leaveBtn;
	int avatarLife;
	bool isreduce;
	bool socketAlive;
	GamePlayer* player;
	GamePlayer* avatar[8];
	ODSocket cSocketR;
	ODSocket cSocketW;
	ODSocket mysocketR;
	ODSocket mysocketW;
	GameEnemy* enemy[ENEMYNUM];
	int portR, portW, port;
	int id;
	std::string ip;
	bool start;
	bool status;
	bool heartBeat;
	std::ofstream ofs;
	int weaponType;
public:
	int vmove;
	int hmove;
	CCSprite*	m_tamara;
	virtual bool init(); 
	void  reduceLife(int num);
	void  resetreduce(ccTime dt);
	void  enemyrestart(ccTime dt);
	void  resettouch(ccTime dt);
	void  update(ccTime dt);
	void revert(ccTime dt);
	void revertavatar(ccTime dt);
	void revertplayer(ccTime dt);
	void resetRocket(ccTime dt);
	void resetPlayer(ccTime dt);
	void freezeplayer(ccTime dt);
	void syncLife(ccTime dt);
	void attackByBomb(ccTime dt);
	void send();
	void lose();
	void win();
	void receive();
	//���亯��
	void serverR();
	void serverW();
	void clientR();
	void clientW();
	void startServer();
	void startPractice();
	void startClient(std::string hostip);
	static cocos2d::CCScene* scene(char type, std::string hostip);
    virtual void ccTouchesBegan(CCSet *pTouches, CCEvent *pEvent);
	virtual void ccTouchesMoved(CCSet *pTouches, CCEvent *pEvent);
	virtual void ccTouchesEnded(CCSet *pTouches, CCEvent *pEvent);
	LAYER_NODE_FUNC(MapScene);
	virtual void keyBackClicked();
	virtual void keyMenuClicked();
};
#endif