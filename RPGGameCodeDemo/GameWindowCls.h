#ifndef __XSYDFILE_GAMEWDCLS__
	#define __XSYDFILE_GAMEWDCLS__
	#include <SFML/Graphics.hpp>
	#include "GameActivityCls.h"
	//��DreamersEngine��������ռ��ж���GameWindow��, ���ཫ�������Ƕ���Ϸ��, �û����ķֱ��ʵ�����½�������Ӧ����.
	namespace DreamersEngine {
		class GameWindow {
		private:

		protected:
			sf::RenderWindow* mWindow = NULL;
			
			bool m_Inited = false;
			bool m_IsOpen = false;
			sf::Vector2u m_windowSize = sf::Vector2u(800,600);
			std::string m_windowTitle = "SFML Window";
		public:
			GameActivity * ContainedActivity = NULL;
			void Init();
			void Destroy();
			void setWindowSize(unsigned int Width, unsigned int Height);
			sf::Vector2u getWindowSize();
			void setWindowTitle(const std::string& NewTitle);
			std::string getWindowTitle();
			void StartRenderProcess();
			void CloseWindow();
			virtual void OnClosed();
		};
	}
#endif