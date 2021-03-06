#pragma once
#include "defines.h"
#include "IUpdateDraw.h"
#include "../Event/Event.h"
#include "../Engine.h"
#include "Texture.h"
#include "InputManager.h"
#include "../SpriteRenderer.h"
#include "../ThirdParty/NetEase/Sprite2.h"
#include "../ThirdParty/NetEase/WDF.h"
#include "../ThirdParty/NetEase/WAS.h"
#include "GameMap.h"
#include "../Environment.h"
#include "../ResourceManager.h"
#include "Config.h"
#include "../GMath.h"

#include "FrameAnimation.h"
#include "Player.h"



class Demo : public IUpdateDraw, public IMouseEvent
{
public:
	Demo();
	~Demo();

	static float s_ScreenWidth; 
	static float s_ScreenHeight;

	static int GetScreenWidth(){ return s_ScreenWidth; };
	static int GetScreenHeight(){ return s_ScreenHeight; };

	void Update() override;
	void Draw() override;
	void OnEvent(int button, int action, int mods) override;

private:
	void ProcessInput();
	void TestServer();
	
	SpriteRenderer  *m_RendererPtr;
	
	Texture* m_BlockTexturePtr;

	GameMap* m_GameMapPtr;

	Player * m_StriderPtr;
	
	std::vector< Player * > m_NPCs;

	bool m_IsChangeState = false;
	double m_ChangeStateTimeInterval = 0;
	bool m_IsTestNpc0;
};


