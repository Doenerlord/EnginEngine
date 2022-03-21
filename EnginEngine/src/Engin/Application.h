#pragma once

#include "Core.h"

namespace Engin {

	class ENGIN_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	//TO BE DEFINED IN CLIENT
	Application* CreateApplication();
}


