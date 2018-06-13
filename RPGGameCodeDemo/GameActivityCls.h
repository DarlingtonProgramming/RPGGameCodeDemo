#ifndef __XSYDFILE_GAMEACTCLS__
	#define __XSYDFILE_GAMEACTCLS__
	#include <SFML/Graphics.hpp>
	#include <typeinfo>
	
	//用编译器预处理器ifndef来防止头文件被俩次Include后编译报错(重复定义)
	//定义GameActivity这个类, 这个类的OnRender是一个虚函数(类似于Java中的abstract), 我们到时候会对每个场景进行细分, 都变成一个个的GameActivity.
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