#pragma once

#include "Core.h"
#include "Engin/Events/ApplicationEvent.h"
#include "Events/Event.h"
#include "Window.h"

namespace Engin {

	class ENGIN_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};

	//TO BE DEFINED IN CLIENT
	Application* CreateApplication();
}


