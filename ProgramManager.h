#ifndef _PROGRAMMANAGER_H
#define _PROGRAMMANAGER_H
#include "Texture.h"
#include "Timer.h"
#include "time.h"
#include "InputManager.h"

class ProgramManager {

private:

	static ProgramManager* sInstance;

	const int FRAME_RATE = 60;

	bool mQuit;
	Graphics* mGraphics;

	Timer* mTimer;
	InputManager* mInputManager;

	//ScreenManager* mScreenMgr;

	sf::Event mEvent;

public:

	static ProgramManager* Instance();
	static void Release();

	void Run();

private:
	
	ProgramManager();
	~ProgramManager();

	void EarlyUpdate();
	void Update();
	void LateUpdate();

	void Render();

};

#endif