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
		//or any other event type
		dispatcher.Dispatch<WindowResizeEvent>(BIND_EVENT_FN(OnWindowResize));
		dispatcher.Dispatch<KeyPressedEvent>(BIND_EVENT_FN(OnKeyPressed));
		dispatcher.Dispatch<KeyReleasedEvent>(BIND_EVENT_FN(OnKeyReleased));
		dispatcher.Dispatch<MouseScrolledEvent>(BIND_EVENT_FN(OnMouseScrolled));
		dispatcher.Dispatch<MouseButtonPressedEvent>(BIND_EVENT_FN(OnMouseButtonPressed));
		dispatcher.Dispatch<MouseButtonReleasedEvent>(BIND_EVENT_FN(OnMouseButtonReleased));
		dispatcher.Dispatch<MouseMovedEvent>(BIND_EVENT_FN(OnMouseMoved));

		//glClearColor(0, 0, 1, 1);
		ENGIN_CORE_TRACE("{0}", e);
	}

	//the primary loop of the engine
	void Application::Run() {
		//clears the screen from previously drawn things. Clear Color is set to magenta so the application window gets cleared with solid magenta color
		glClearColor(1, 0, 1, 1);
		while (m_Running)
		{
			glClear(GL_COLOR_BUFFER_BIT);
			//poll events and swaps front and back buffer
			m_Window->OnUpdate();
		}
	}

	//breaks the primary loop when the application window is closed. Called by the dispatcher if it receives a WindowCloseEvent
	bool Application::OnWindowClose(WindowCloseEvent& e) {
		m_Running = false;
		return true;
	}

	bool Application::OnWindowResize(WindowResizeEvent& e) {
		glClearColor(0.5, 0.7, 0.2, 1);
		return true;
	}

	bool Application::OnKeyPressed(KeyPressedEvent& e) {
		glClearColor(0, 0, 1, 1);
		return true;
	}

	bool Application::OnKeyReleased(KeyReleasedEvent & e) {
		glClearColor(0.7, 0.3, 0.5, 1);
		return true;
	}

	bool Application::OnMouseScrolled(MouseScrolledEvent& e) {
		glClearColor(0.9, 0.4, 0.4, 1);
		return true;
	}

	bool Application::OnMouseButtonPressed(MouseButtonPressedEvent& e) {
		glClearColor(0.2, 0.8, 0.3, 1);
		return true;
	}

	bool Application::OnMouseButtonReleased(MouseButtonReleasedEvent& e) {
		glClearColor(0.6, 0.3, 0.5, 1);
		return true;
	}

	bool Application::OnMouseMoved(MouseMovedEvent& e) {
		glClearColor(0.1, 0.2, 0.3, 1);
		return true;
	}

}