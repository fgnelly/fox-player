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

	sf::Event mEvents;

public:

	static Graphics* Instance();
	static void Release();
	static bool Initalized();

	void ClearBackBuffer();

	sf::Texture* LoadTexture(std::string filename);
	sf::Text* CreateTextTexture(sf::Font* font, std::string text, int size, sf::Color color);
	void DrawTexture(sf::Texture* tex, float x, float y, sf::Vector2f scale, float rot);
	void DrawTextTexture(sf::Text*, float x, float y, sf::Vector2f scale);
	void DrawTextureTransparent(sf::Texture* tex, float x, float y, sf::Vector2f scale, int transparency);

	sf::Window* GetRenderWindow();

	sf::Event GetWindowEvent();

	void Render();

private:

	Graphics();
	~Graphics();

	bool Init();
	
};

#endif