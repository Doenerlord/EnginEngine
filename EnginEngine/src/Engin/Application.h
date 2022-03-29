#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "Events/ApplicationEvent.h"
#include "Events/KeyEvent.h"
#include "Events/MouseEvent.h"
#include "Window.h"

namespace Engin {

	class ENGIN_API Application {
	public:
		Application();
		virtual ~Application();

		//primary loop of the engine
		//clears the screen from previously drawn things. Clear Color is set to magenta so the application window gets cleared with solid magenta color
		void Run();

		void OnEvent(Event& e);
	private:
		//breaks the primary loop when the application window is closed
		bool OnWindowClose(WindowCloseEvent& e);
		bool OnWindowResize(WindowResizeEvent& e);
		bool OnKeyPressed(KeyPressedEvent& e);
		bool OnKeyReleased(KeyReleasedEvent& e);
		bool OnMouseScrolled(MouseScrolledEvent& e);
		bool OnMouseButtonPressed(MouseButtonPressedEvent& e);
		bool OnMouseButtonReleased(MouseButtonReleasedEvent& e);
		bool OnMouseMoved(MouseMovedEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};

	//TO BE DEFINED IN CLIENT
	Application* CreateApplication();
}


