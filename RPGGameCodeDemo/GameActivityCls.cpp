#include "GameActivityCls.h"

void DreamersEngine::GameActivity::recvEvent(sf::Event Event)
{
	sf::Event mEvent = Event;
	switch (mEvent.type) {
		case sf::Event::EventType::KeyPressed:
			this->OnKeyDown(mEvent.key.code);
			break;
		case sf::Event::EventType::KeyReleased:
			this->OnKeyReleased(mEvent.key.code);
			break;
		case sf::Event::EventType::MouseEntered:
			this->OnMouseEnter();
			break;
		case sf::Event::EventType::MouseLeft:
			this->OnMouseLeft();
			break;
		case sf::Event::EventType::MouseMoved:
			this->OnMouseMove(mEvent.mouseMove.x, mEvent.mouseMove.y);
			break;
		case sf::Event::EventType::MouseButtonPressed:
			this->OnMouseDown(mEvent.mouseButton.button, mEvent.mouseButton.x, mEvent.mouseButton.y);
			break;
		case sf::Event::EventType::MouseButtonReleased:
			this->OnMouseUp(mEvent.mouseButton.button, mEvent.mouseButton.x, mEvent.mouseButton.y);
			break;
		default:
			break;
	}
}

void DreamersEngine::GameActivity::realCallRender(sf::RenderTarget * TargetToBeRendered)
{
	this->OnRender(TargetToBeRendered);
}

void DreamersEngine::GameActivity::OnRender(sf::RenderTarget * TargetToBeRendered)
{
	
	return;
}

void DreamersEngine::GameActivity::OnKeyDown(sf::Keyboard::Key KeyCode)
{
	return;
}

void DreamersEngine::GameActivity::OnKeyReleased(sf::Keyboard::Key KeyCode)
{
	return;
}

void DreamersEngine::GameActivity::OnMouseEnter()
{
	return;
}

void DreamersEngine::GameActivity::OnMouseLeft()
{
	return;
}

void DreamersEngine::GameActivity::OnMouseMove(int X, int Y)
{
	return;
}

void DreamersEngine::GameActivity::OnMouseDown(sf::Mouse::Button Button, int X, int Y)
{
	return;
}

void DreamersEngine::GameActivity::OnMouseUp(sf::Mouse::Button Button, int X, int Y)
{
	return;
}
