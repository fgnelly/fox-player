#include "ProgramManager.h"

ProgramManager* ProgramManager::sInstance = NULL;

ProgramManager* ProgramManager::Instance()
{
	if (sInstance == NULL)
		sInstance = new ProgramManager();

	return sInstance;
}

void ProgramManager::Release()
{
	delete sInstance;
	sInstance = NULL;
}

ProgramManager::ProgramManager()
{
	srand(static_cast<unsigned int>(time(0)));

	mQuit = false;

	mGraphics = Graphics::Instance();

	if (!Graphics::Initalized())
		mQuit = true;

	//init all managers like screen inout and such

	mTimer = Timer::Instance();

	mInputManager = InputManager::Instance();
}

ProgramManager::~ProgramManager()
{
	Graphics::Release();
	mGraphics = NULL;

	//release and null all other managers

	Timer::Release();
	mTimer = NULL;

	InputManager::Release();
	mInputManager = NULL;
}

void ProgramManager::EarlyUpdate()
{
	//TEMPORARY: MANUAL INPUT/EVENT UPDATE
	//mGraphics->GetRenderWindow()->pollEvent(mEvent);

	mInputManager->Update();

	if (mInputManager->IsWindowClosed())
		mQuit = true;

	//TEMPORARY: FOR CLOSING THE WINDOW
	//if (mEvent.type == sf::Event::Closed)
		//mQuit = true;
}

void ProgramManager::Update()
{
	//update screen here
}

void ProgramManager::LateUpdate()
{
	//update/reset timer here
	mTimer->Reset();
}

void ProgramManager::Render()
{
	mGraphics->ClearBackBuffer();

	//here do all draw calls


	mGraphics->Render();

}

void ProgramManager::Run()
{
	//here put the main program loop and init basic framework parts

	while (!mQuit)
	{
		mTimer->Update();
		if (mTimer->DeltaTime() >= (1.0f / FRAME_RATE))
		{
			EarlyUpdate();
			Update(); //objects update
			LateUpdate(); //collison delection and stuff
			mInputManager->UpdatePrevInput();
			Render();
		}

	}

}