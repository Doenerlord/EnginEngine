#include "enginpch.h"
#include "Application.h"
#include "Engin/Log.h"
#include <GLFW/glfw3.h>

namespace Engin {

	//macro to easily bind functions to something
#define  BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

	//Application constructor creats a new window and sets the event callback.
	Application::Application() {
		m_Window = std::unique_ptr<Window>(Window::Create());
		//sets event callback to the binded function
		m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));
	}

	Application::~Application() {

	}

	void Application::OnEvent(Event& e) {
		//use the dispatcher to dispatch certain events to certain functions
		EventDispatcher dispatcher(e);
		//bind OnWindowClose function to be used by the dispatcher if it sees a WindowCloseEvent
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));

		ENGIN_CORE_TRACE("{0}", e);
	}

	//the primary loop of the engine
	void Application::Run() {
		while (m_Running)
		{
			//clears the screen from previously drawn things. Clear Color is set to magenta so the application window gets cleared with solid magenta color
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			//poll events and swaps front and back buffer
			m_Window->OnUpdate();
		}
	}

	//breaks the primary loop when the application window is closed
	bool Application::OnWindowClose(WindowCloseEvent& e) {
		m_Running = false;
		return true;
	}
}