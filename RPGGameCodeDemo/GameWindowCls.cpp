#include "GameWindowCls.h"

void DreamersEngine::GameWindow::Init()
{
	if (this->m_Inited) {
		return;
	}
	this->m_Inited = true;
	this->m_IsOpen = true;
	sf::ContextSettings mOpenGLSettings;
	mOpenGLSettings.antialiasingLevel = 5;
	this->mWindow = new sf::RenderWindow(sf::VideoMode(this->m_windowSize.x, this->m_windowSize.y),sf::String(this->m_windowTitle),sf::Style::Default,mOpenGLSettings);
	this->mWindow->setVerticalSyncEnabled(true); //开启垂直同步
	
}

void DreamersEngine::GameWindow::Destroy()
{
	if (!this->m_Inited) {
		return;
	}
	this->m_Inited = false;
	this->m_IsOpen = false;
	delete this->mWindow;
}

void DreamersEngine::GameWindow::setWindowSize(unsigned int Width, unsigned int Height)
{
	this->m_windowSize.x = Width;
	this->m_windowSize.y = Height;
	if (this->m_IsOpen) {
		this->mWindow->setSize(this->m_windowSize);
	}
}

sf::Vector2u DreamersEngine::GameWindow::getWindowSize()
{
	return this->m_windowSize;
}

void DreamersEngine::GameWindow::setWindowTitle(const std::string & NewTitle)
{
	this->m_windowTitle = NewTitle;
	if (this->m_IsOpen) {
		this->mWindow->setTitle(sf::String(NewTitle));
	}
}

std::string DreamersEngine::GameWindow::getWindowTitle()
{
	return this->m_windowTitle;
}

void DreamersEngine::GameWindow::StartRenderProcess()
{
	while (this->m_IsOpen) {
		sf::Event mEvent;
		while (this->mWindow->pollEvent(mEvent)) {
			switch (mEvent.type) {
			case sf::Event::EventType::Closed:
				this->OnClosed();
				if (!this->m_IsOpen) {
					return;
				}
				break;
			default:
				if (ContainedActivity != NULL) {
					ContainedActivity->recvEvent(mEvent);
				}
				break;
			}
		}
		if (ContainedActivity != NULL) {
			this->mWindow->clear();
			ContainedActivity->realCallRender(this->mWindow);
			this->mWindow->display();
		}
	}
	return;
}

void DreamersEngine::GameWindow::CloseWindow()
{
	this->mWindow->close();
	this->m_IsOpen = false;
}

void DreamersEngine::GameWindow::OnClosed()
{
	return;
}
