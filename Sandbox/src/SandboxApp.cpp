#include <Engin.h>

class Sandbox : public Engin::Application {
public:
	Sandbox() {

	}

	~Sandbox() {

	}
};

Engin::Application* Engin::CreateApplication() {
	return new Sandbox();
}