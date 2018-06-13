#ifndef __XSYDFILE_GAMEACTCLS__
	#define __XSYDFILE_GAMEACTCLS__
	#include <SFML/Graphics.hpp>
	#include <typeinfo>
	
	//�ñ�����Ԥ������ifndef����ֹͷ�ļ�������Include����뱨��(�ظ�����)
	//����GameActivity�����, ������OnRender��һ���麯��(������Java�е�abstract), ���ǵ�ʱ����ÿ����������ϸ��, �����һ������GameActivity.
	//onKeyDown, onKeyReleased, onMouseEnter, onMouseLeft, onMouseMove, onMouseButton

	namespace DreamersEngine {
		class GameActivity {
			friend class GameWindow;
		protected:
			void recvEvent(sf::Event Event);
			void realCallRender(sf::RenderTarget* TargetToBeRendered);
		public:
			virtual void OnRender(sf::RenderTarget* TargetToBeRendered);
			virtual void OnKeyDown(sf::Keyboard::Key KeyCode);
			virtual void OnKeyReleased(sf::Keyboard::Key KeyCode);
			virtual void OnMouseEnter();
			virtual void OnMouseLeft();
			virtual void OnMouseMove(int X, int Y);
			virtual void OnMouseDown(sf::Mouse::Button Button, int X, int Y);
			virtual void OnMouseUp(sf::Mouse::Button Button, int X, int Y);

		};
	}
#endif