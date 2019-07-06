#ifndef _GRAPHICS_H
#define _GRAPHICS_H
#include <SFML/Graphics.hpp>

class Graphics {

public:

	static int const SCREEN_WIDTH = 600;
	static int const SCREEN_HEIGHT = 350;
	const char* WINDOW_TITLE = "Fox-Player";
	const sf::Color WINDOW_COLOR = sf::Color::Black;

private:

	static Graphics* sInstance;
	static bool sInitialized;

	sf::RenderWindow* mWindow;

	sf::Event* mEvents;

public:

	static Graphics* Instance();
	static void Release();
	static bool Initalized();

	void ClearBackBuffer();

	sf::Window* GetRenderWindow();

	void Render();

private:

	Graphics();
	~Graphics();

	bool Init();
	
};

#endif