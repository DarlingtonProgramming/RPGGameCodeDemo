#include <SFML/Graphics.hpp>
#include "GameActivityCls.h"
#include "GameWindowCls.h"
#include <iostream>
#include <SFML/Audio.hpp>


const constexpr int WindowWidth = 800;
const constexpr int WindowHeight = 600;
const constexpr float CharacterScale = 0.5f;
const constexpr unsigned int MovementDelta = 5U;
const constexpr unsigned int CharacterInitX = 0U;
const constexpr unsigned int CharacterInitY = WindowHeight / 2U;


class RenderTest : public DreamersEngine::GameWindow {
public:
	void OnClosed() override{ //Override¿ÉÐ´¿É²»Ð´
		this->CloseWindow();
	}
};
class RenderActivity : public DreamersEngine::GameActivity {
protected:
	sf::Texture CharacterTexture;
	sf::Texture MapTexture;
	unsigned int CharacterPositionX = CharacterInitX;
	unsigned int CharacterPositionY = CharacterInitY;
	sf::Vector2f m_MapSize;
	sf::Vector2f m_CharacterSize;
	sf::Music music;
public:
	RenderActivity() {
		CharacterTexture.loadFromFile("Resource/Character.png");
		CharacterTexture.setRepeated(false);
		CharacterTexture.setSmooth(true);
		MapTexture.loadFromFile("Resource/Map.png");
		MapTexture.setRepeated(false);
		MapTexture.setSmooth(true);
		music.openFromFile("Resource/ts.wav");

		
	}
	void OnRender(sf::RenderTarget* TargetToBeRendered) {
		sf::Vector2u WindowSize = TargetToBeRendered->getSize();
		
		sf::Vector2u MapSize = MapTexture.getSize();
		float MapScale = static_cast<float>(WindowSize.y) / static_cast<float>(MapSize.y);
		sf::Vector2f MapNewSize = sf::Vector2f(MapSize.x*MapScale, MapSize.y*MapScale);
		m_MapSize = MapNewSize;
		sf::Vector2u CharacterSize = CharacterTexture.getSize();
		m_CharacterSize.x = CharacterSize.x * CharacterScale;
		m_CharacterSize.y = CharacterSize.y * CharacterScale;

		sf::Sprite MapSprite;
		MapSprite.setTexture(MapTexture);
		MapSprite.setScale(sf::Vector2f(MapScale, MapScale));
		sf::Vector2f MapLocation;
		MapLocation.y = 0U;
		if (CharacterPositionX <= WindowSize.x / 2U) {
			MapLocation.x = 0U;
		}
		else if (CharacterPositionX >= (MapNewSize.x - WindowSize.x / 2U)) {
			MapLocation.x = WindowSize.x - MapNewSize.x;
		}
		else {
			MapLocation.x = static_cast<float>((WindowSize.x / 2U)) - static_cast<float>(CharacterPositionX);
		}
		MapSprite.setPosition(MapLocation);
		TargetToBeRendered->draw(MapSprite);

		sf::Sprite CharacterSprite;
		CharacterSprite.setTexture(CharacterTexture);
		CharacterSprite.setPosition(sf::Vector2f(this->CharacterPositionX + MapLocation.x, this->CharacterPositionY));
		CharacterSprite.setScale(sf::Vector2f(CharacterScale, CharacterScale));
		TargetToBeRendered->draw(CharacterSprite);
		
	}
	void OnKeyDown(sf::Keyboard::Key KeyCode) {
		switch (KeyCode) {
		case sf::Keyboard::Key::Left:
			if (this->CharacterPositionX >= MovementDelta) {
				this->CharacterPositionX -= MovementDelta;
				break;
			}
		case sf::Keyboard::Key::Right:
			if (this->CharacterPositionX <= m_MapSize.x - MovementDelta - this->m_CharacterSize.x) {
				this->CharacterPositionX += MovementDelta;
			}
			break;
		case sf::Keyboard::Key::Up:
			if (this->CharacterPositionY >= MovementDelta) {
				this->CharacterPositionY -= MovementDelta;
			}
			break;
		case sf::Keyboard::Key::Down:
			if (this->CharacterPositionY <= m_MapSize.y - MovementDelta) {
				this->CharacterPositionY += MovementDelta;
			}
			break;
		}
	}
	void OnKeyReleased(sf::Keyboard::Key KeyCode) {

	}
	void OnMouseEnter() {

	}
	void OnMouseLeft() {

	}
	void OnMouseMove(int X, int Y) {

	}
	void OnMouseDown(sf::Mouse::Button Button, int X, int Y) {

	}
	void OnMouseUp(sf::Mouse::Button Button, int X, int Y) {

	}

	void BGM() {
		music.play();
		music.setLoop(true);
		music.setVolume(50);
		music.setPitch(1.2);
	}
};

int main()
{
	RenderTest mWindow;
	RenderActivity mAct;
	mAct.BGM();
	mWindow.setWindowTitle("RPG Game Demo");
	mWindow.setWindowSize(WindowWidth, WindowHeight);
	mWindow.ContainedActivity = &mAct;
	mWindow.Init();
	mWindow.StartRenderProcess();
	mWindow.Destroy();
	return 0;
}