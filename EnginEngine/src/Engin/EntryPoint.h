#pragma once

#ifdef ENGIN_PLATFORM_WINDOWS

//extern means that this method exists somewhere in our code and is linked to this project
extern Engin::Application* Engin::CreateApplication();

int main(int argc, char** argv) {

	//intialized the log functionality
	Engin::Log::Init();
	ENGIN_CORE_WARN("Initialized CoreLogger!");
	ENGIN_WARN("Initialized ClientLogger!");

	//Application object gets created and it's Run function is called. After Run has completed the application object gets deleted
	auto app = Engin::CreateApplication();
	app->Run();
	delete app;
}

#endif