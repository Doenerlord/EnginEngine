#include "enginpch.h"
#include "Application.h"
#include "Engin/Events/ApplicationEvent.h"
#include "Engin/Log.h"

namespace Engin {

	Application::Application() {

	}

	Application::~Application() {

	}

	void Application::Run() {
		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication))
		{
			ENGIN_TRACE(e);
		}
		if (e.IsInCategory(EventCategoryInput))
		{
			ENGIN_TRACE(e);
		}
		while (true)
		{

		}
	}
}