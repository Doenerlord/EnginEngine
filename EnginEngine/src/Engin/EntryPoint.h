#pragma once

#ifdef ENGIN_PLATFORM_WINDOWS

extern Engin::Application* Engin::CreateApplication();

int main(int argc, char** argv) {

	auto app = Engin::CreateApplication();
	app->Run();
	delete app;
}

#endif