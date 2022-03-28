//include engin.h here to grant access to the entrypoint.
#include <Engin.h>

class Sandbox : public Engin::Application {
public:
	Sandbox() {
	}

	~Sandbox() {

	}
};

//definition of CreateApplication() inside of Application.h
Engin::Application* Engin::CreateApplication() {
	return new Sandbox();
}