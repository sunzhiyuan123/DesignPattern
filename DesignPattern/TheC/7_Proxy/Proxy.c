#include <stdio.h>
 #include <stdlib.h>
 #include <string.h>

 /*C����ʵ��<���ģʽ֮��>֮����ģʽ____��ͨ����*/

 /*����ģʽ: Ϊ���������ṩһ�ִ����Կ��ƶ��������ķ���*/
 /*��ͨ����:  ������ֻ�ܷ��ʴ����ɫ�������ܷ�����ʵ��ɫ�� ������ֻ֪�������
 ����֪����ʵ��ɫ����������ʵ��ɫ�ı���Ը߲�ģ���Ӱ�졣*/

 /*������Ϸ��*/
typedef struct _IGamePlayer IGamePlayer;
 struct _IGamePlayer
 {
     void (*login)(char *pName, char *pPassword, void *);
     void (*killBoss)(void *);
     void (*upgrade)(void *);
     void (*DeleteIGamePlayer)(void *);
 };

/*��Ϸ��*/
typedef struct _GamePlayer GamePlayer;
struct _GamePlayer
{
	IGamePlayer gmplayer;   /*�̳г�����Ϸ��*/
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

 /*��ͨ����Ĵ�����*/
typedef struct _GamePlayerProxy GamePlayerProxy;
struct _GamePlayerProxy
{
	IGamePlayer gmplayer;   /*�̳г�����Ϸ��*/
	GamePlayer *pGamePlayer; /*��������*/
	void (*DeleteGamePlayerProxy)(GamePlayerProxy *pGamePlayerProxy);
};

void ProxykillBoss(void * pGamePlayerProxy)
{
	((GamePlayerProxy *)pGamePlayerProxy)->pGamePlayer->gmplayer.killBoss(((GamePlayerProxy *)pGamePlayerProxy)->pGamePlayer);    /*����ִ�б������ߵķ���*/
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
	
	pGamePlayerProxy->pGamePlayer = CreateGamePlayer((IGamePlayer *)pGamePlayerProxy, pName);  /*������������*/
	
	pGamePlayerProxy->DeleteGamePlayerProxy 	 = DeleteGamePlayerProxy;
	pGamePlayerProxy->gmplayer.login             = Proxylogin;
	pGamePlayerProxy->gmplayer.killBoss          = ProxykillBoss;
	pGamePlayerProxy->gmplayer.upgrade           = Proxyupgrade;
	pGamePlayerProxy->gmplayer.DeleteIGamePlayer = pGamePlayerProxy->DeleteGamePlayerProxy;
	
	return pGamePlayerProxy;
}

/*����*/
void main( )
{
	/*����һ��������*/
	IGamePlayer *pPlayProxy = (IGamePlayer *)CreateProxy("zhangsan"); //ת��Ϊ�����࣬ ������ֻ�����ڳ�����
	
	/*��ʼ����Ϸ������ʱ���*/
	printf("game start time is : 2014-1-21 9:00\n");
	
	/*�����¼*/
	pPlayProxy->login("zhangsan", "password", pPlayProxy);
	
	/*������*/
	pPlayProxy->killBoss(pPlayProxy);
	
	/*��������*/
	pPlayProxy->upgrade(pPlayProxy);
	
	/*��Ϸ����*/
	printf("game end time is :2014-1-21 10:00");
	
	/*�ͷ���Դ*/
	pPlayProxy->DeleteIGamePlayer(pPlayProxy);
}
