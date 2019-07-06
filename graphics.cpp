#include "graphics.h"

Graphics* Graphics::sInstance = NULL;
bool Graphics::sInitialized = false;

Graphics* Graphics::Instance()
{
	if (sInstance == NULL)
		sInstance = new Graphics();

	return sInstance;
}

void Graphics::Release()
{
	delete sInstance;
	sInstance = NULL;

	sInitialized = false;
}

bool Graphics::Initalized()
{
	return sInitialized;
}

Graphics::Graphics()
{
	sInitialized = Init();
}

Graphics::~Graphics()
{
	mWindow->close();
}

bool Graphics::Init()
{
	mWindow = new sf::RenderWindow(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), WINDOW_TITLE);
	return true;
}

void Graphics::ClearBackBuffer()
{
	mWindow->clear(WINDOW_COLOR);
}

sf::Window* Graphics::GetRenderWindow()
{
	return mWindow;
}

void Graphics::Render()
{
	mWindow->display();
}

