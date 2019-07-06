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

sf::Texture* Graphics::LoadTexture(std::string filename)
{
	sf::Texture* tex = NULL;
	tex = new sf::Texture();

	tex->loadFromFile(filename);

	return tex;
}

sf::Text* Graphics::CreateTextTexture(sf::Font* font, std::string text, int size, sf::Color color)
{
	sf::Text* Text = NULL;
	Text = new sf::Text(text, *font, size);
	Text->setFillColor(color);

	return Text;

}

void Graphics::DrawTexture(sf::Texture* tex, float x, float y, sf::Vector2f scale, float rot)
{
	sf::Sprite sprite;
	sprite.setTexture(*tex);
	sprite.setRotation(rot);
	if (rot == 180.0f)
	{
		x += sprite.getLocalBounds().width;
		y += sprite.getLocalBounds().height;
	}
	else if (rot == 90.0f)
	{
		x += sprite.getLocalBounds().width;
	}
	else if (rot == 270.0f)
	{
		y += sprite.getLocalBounds().height;
	}
	sprite.setPosition(sf::Vector2f{ x, y });
	sprite.setScale(scale);
	mWindow->draw(sprite);
}

void Graphics::DrawTextureTransparent(sf::Texture* tex, float x, float y, sf::Vector2f scale, int transparency)
{
	sf::Sprite sprite;
	sprite.setTexture(*tex);
	sprite.setPosition(sf::Vector2f{ x, y });
	sprite.setScale(scale);
	sprite.setColor(sf::Color(255, 255, 255, transparency));
	mWindow->draw(sprite);
}

void Graphics::DrawTextTexture(sf::Text* tex, float x, float y, sf::Vector2f scale)
{
	tex->setPosition(sf::Vector2f{ x, y });
	tex->setScale(scale);
	mWindow->draw(*tex);
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

sf::Event Graphics::GetWindowEvent()
{
	mWindow->pollEvent(mEvents);
	return mEvents;
}

void Graphics::Render()
{
	mWindow->display();
}

