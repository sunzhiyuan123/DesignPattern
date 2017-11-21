#include <stdio.h>
 #include <stdlib.h>
 #include <string.h>

 /*C语言实现<设计模式之禅>之代理模式____普通代理*/

 /*代理模式: 为其他对象提供一种代理以控制对这个对象的访问*/
 /*普通代理:  调用者只能访问代理角色，而不能访问真实角色。 调用者只知道代理而
 不用知道真实角色，屏蔽了真实角色的变更对高层模块的影响。*/

 /*抽象游戏者*/
typedef struct _IGamePlayer IGamePlayer;
 struct _IGamePlayer
 {
     void (*login)(char *pName, char *pPassword, void *);
     void (*killBoss)(void *);
     void (*upgrade)(void *);
     void (*DeleteIGamePlayer)(void *);
 };

/*游戏者*/
typedef struct _GamePlayer GamePlayer;
struct _GamePlayer
{
	IGamePlayer gmplayer;   /*继承抽象游戏者*/
	char acName[10];
	void (*DeleteGamePlayer)(GamePlayer *pGamePlayer);
};

void login(char *pName, char *pPassword, void *pGamePlayer)
{
	printf("user :%s is login in !\n", pName);
}

void killBoss(void *pGamePlayer)
{
	printf("%s is killing the boss! \n", ((GamePlayer *)pGamePlayer)->acName);
}

void upgrade(void *pGamePlayer)
{
	printf("%s is upgrading !\n", ((GamePlayer *)pGamePlayer)->acName);
}

void DeleteGamePlayer(GamePlayer *pGamePlayer)
{
	if(pGamePlayer)
	{
		free(pGamePlayer);
		pGamePlayer = NULL;
	}
}

GamePlayer *CreateGamePlayer(IGamePlayer *pIGamePlayer, char *pName)
{
	GamePlayer *pGamePlayer = NULL;
	if(!pIGamePlayer)
	{
		return NULL;
	}
	else
	{
		pGamePlayer = (GamePlayer *)malloc(sizeof(GamePlayer));
		if(!pGamePlayer)
		{
			return NULL;
		}
		
		memset(pGamePlayer, 0, sizeof(GamePlayer));
		strcpy(pGamePlayer->acName, pName);
		pGamePlayer->DeleteGamePlayer  			= DeleteGamePlayer;
		pGamePlayer->gmplayer.login    			= login;
		pGamePlayer->gmplayer.killBoss 			= killBoss;
		pGamePlayer->gmplayer.upgrade           = upgrade;
		pGamePlayer->gmplayer.DeleteIGamePlayer = pGamePlayer->DeleteGamePlayer;
		
		return pGamePlayer;
	}
}

 /*普通代理的代理者*/
typedef struct _GamePlayerProxy GamePlayerProxy;
struct _GamePlayerProxy
{
	IGamePlayer gmplayer;   /*继承抽象游戏者*/
	GamePlayer *pGamePlayer; /*被代理者*/
	void (*DeleteGamePlayerProxy)(GamePlayerProxy *pGamePlayerProxy);
};

void ProxykillBoss(void * pGamePlayerProxy)
{
	((GamePlayerProxy *)pGamePlayerProxy)->pGamePlayer->gmplayer.killBoss(((GamePlayerProxy *)pGamePlayerProxy)->pGamePlayer);    /*代理执行被代理者的方法*/
}

void Proxylogin(char *pName, char *pPassword, void *pGamePlayerProxy)
{
	((GamePlayerProxy *)pGamePlayerProxy)->pGamePlayer->gmplayer.login(pName, pPassword, pGamePlayerProxy);
}

void Proxyupgrade(void *pGamePlayerProxy)
{
	((GamePlayerProxy *)pGamePlayerProxy)->pGamePlayer->gmplayer.upgrade(((GamePlayerProxy *)pGamePlayerProxy)->pGamePlayer);
}

void DeleteGamePlayerProxy(GamePlayerProxy *pGamePlayerProxy)
{
	if(pGamePlayerProxy->pGamePlayer)
	{
		pGamePlayerProxy->pGamePlayer->DeleteGamePlayer(pGamePlayerProxy->pGamePlayer);
	}
	if(pGamePlayerProxy)
	{
		free(pGamePlayerProxy);
		pGamePlayerProxy = NULL;
	}
	
	return;
}

GamePlayerProxy *CreateProxy(char *pName)
{
	GamePlayerProxy *pGamePlayerProxy = NULL;
	
	pGamePlayerProxy = (GamePlayerProxy *)malloc(sizeof(GamePlayerProxy));
	if(!pGamePlayerProxy)
	{
		return NULL;
	}
	
	memset(pGamePlayerProxy, 0, sizeof(GamePlayerProxy));
	
	pGamePlayerProxy->pGamePlayer = CreateGamePlayer((IGamePlayer *)pGamePlayerProxy, pName);  /*创建被代理者*/
	
	pGamePlayerProxy->DeleteGamePlayerProxy 	 = DeleteGamePlayerProxy;
	pGamePlayerProxy->gmplayer.login             = Proxylogin;
	pGamePlayerProxy->gmplayer.killBoss          = ProxykillBoss;
	pGamePlayerProxy->gmplayer.upgrade           = Proxyupgrade;
	pGamePlayerProxy->gmplayer.DeleteIGamePlayer = pGamePlayerProxy->DeleteGamePlayerProxy;
	
	return pGamePlayerProxy;
}

/*场景*/
void main( )
{
	/*定义一个代理者*/
	IGamePlayer *pPlayProxy = (IGamePlayer *)CreateProxy("zhangsan"); //转换为抽象类， 即场景只依赖于抽象类
	
	/*开始打游戏，记下时间戳*/
	printf("game start time is : 2014-1-21 9:00\n");
	
	/*代理登录*/
	pPlayProxy->login("zhangsan", "password", pPlayProxy);
	
	/*代理打怪*/
	pPlayProxy->killBoss(pPlayProxy);
	
	/*代理升级*/
	pPlayProxy->upgrade(pPlayProxy);
	
	/*游戏结束*/
	printf("game end time is :2014-1-21 10:00");
	
	/*释放资源*/
	pPlayProxy->DeleteIGamePlayer(pPlayProxy);
}
