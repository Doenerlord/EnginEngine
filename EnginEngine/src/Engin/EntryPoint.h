#pragma once

#ifdef ENGIN_PLATFORM_WINDOWS

extern Engin::Application* Engin::CreateApplication();

int main(int argc, char** argv) {

	Engin::Log::Init();
	ENGIN_CORE_WARN("Initialized CoreLogger!");
	ENGIN_WARN("Initialized ClientLogger!");

	auto app = Engin::CreateApplication();
	app->Run();
	delete app;
}

#endif